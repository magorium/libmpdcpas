unit pvt.simpledebug;


//
//  Author      : Magorium
//  Title       : SimpleDebug 
//  Version     : 20160727
//  Description : A unit that adds simple debugging techniques.
//


{$MODE OBJFPC}{$H+}
{.$DEFINE INLINED}


{$IF DEFINED(INLINED) AND DEFINED(AROS)}
  // AROS seems to treat inlined differently so, accomodate.
  {$DEFINE TRACEBACK_REQUIRED}
{$ENDIF}
{$IF NOT DEFINED(INLINED)}
  {$DEFINE TRACEBACK_REQUIRED}
{$ENDIF}


interface


uses
  LineInfo;


  procedure DebugLn(S: String); overload;
  procedure DebugLn(S: String; Args: Array of Const); overload;


  procedure ENTER; {$IFDEF INLINED}inline;{$ENDIF}
  procedure LEAVE; {$IFDEF INLINED}inline;{$ENDIF}


implementation


Uses
  {$IFDEF AROS}
  exec,
  utility,
  aros.debug,
  {$ENDIF}
  Dos,
  SysUtils;


{$IF FPC_FULLVERSION < 030000}
Type
  CodePointer = Pointer;
{$ENDIF}


type
  TDebugProc = procedure(S: AnsiString);


var
  DebugProc : TDebugProc;


{$IFDEF WINDOWS}
type
  LPCSTR  = PChar;


procedure OutputDebugString(lpOutputString:LPCSTR); stdcall; external 'kernel32' name 'OutputDebugStringA';
{$ENDIF}


{$IFDEF AROS}
function  ExtractSubRoutineName(S: ShortString): ShortString;
// Return func/proc-name from given symbol S (when possible else return S)
var
  T     : ShortString;
  j, k  : Integer;
begin
  T := '';

  j := Pos('_$$_', S);              // Rtn name located after this string-part

  if (j > 0)                        // partitionioning string found ?
  then j := j + Length('_$$_')      // then skip the string-part itself
  else Exit( S );                   // else something wrong so leave alone

  For k := j to Length(s) do        // copy rest of string until $ delimiter 
  begin                             // found (or end of string encountered)
    if (s[k] <> '$') 
    then T := T + s[k] 
    else Break;
  end;
  Exit( T );                        // T contains the name of the routine
end;


function  getLineInfo(memadr: ptruint; var func: ShortString; var source: ShortString; var line: LongInt): boolean;
// GetLineInfo 'simulation' for AROS. Slower than molasses, but seems to do the job.
var
  ModuleName    : PChar = '(unknown)';
  SymbolName    : PChar = '(unknown)';
  offset        : IPTR  = 0;
begin
  if                // if possible to Decode location
  ( 0 <>
    DecodeLocation
    (
      pointer(memadr),
      [
        SIPTR(DL_ModuleName)   , IPTR(@ModuleName),
        SIPTR(DL_SymbolName)   , IPTR(@SymbolName),
        SIPTR(DL_SymbolStart)  , IPTR(@offset),
        TAG_END
      ]
    ) 
  ) then            // then 'obtain' relevant information from tags
  begin
    // Name of the module (exe name, not unit name = wrong but has to be enough for now).
    Source := StrPas(ModuleName);
    // Symbol of the routine where the address was located.
    func   := StrPas(SymbolName);

    // 'decode' symbol and extract only the name part.
    func   := ExtractSubRoutineName(func);

    // Not yet found a way to retrieve line numbers, defaulting to -1.
    line   := -1;
    // This routine produced a valid result, let caller know.
    getLineInfo := true;
  end
  else
  begin
    // This routine was unable to create a proper result, let caller know.
    getLineInfo := false;
  end;
end;
{$ENDIF}


procedure ENTER; {$IFDEF INLINED}inline;{$ENDIF}
var
  cp           : CodePointer;
  __FILE__     : ShortString = '';
  __FUNCTION__ : ShortString = '';
  __LINE__     : LongInt = -1;
begin
  {$IFNDEF TRACEBACK_REQUIRED}
  cp := Get_pc_addr;
  {$ELSE}
  cp := get_caller_addr(get_frame);
  {$ENDIF}

  if not getLineInfo(PtrUInt(cp), __FUNCTION__, __FILE__, __LINE__) 
  then __FUNCTION__ := '$' + IntToHex(UIntPtr(cp), 8);

  DebugProc('>>> ' + __FUNCTION__ + '()');
end;


Procedure LEAVE;{$IFDEF INLINED}inline;{$ENDIF}
var
  cp           : CodePointer;
  __FILE__     : ShortString = '';
  __FUNCTION__ : ShortString = '';
  __LINE__     : LongInt = -1;
begin
  {$IFNDEF TRACEBACK_REQUIRED}
  cp := Get_pc_addr;
  {$ELSE}  
  cp := get_caller_addr(get_frame);
  {$ENDIF}

  if not getLineInfo(PtrUInt(cp), __FUNCTION__, __FILE__, __LINE__) 
  then __FUNCTION__ := '$' + IntToHex(UIntPtr(cp), 8);

  DebugProc('<<< ' + __FUNCTION__ + '()');
end;


procedure DebugProcEmpty(S: AnsiString);
begin
  // intentionally left blank
end;


procedure DebugProcConsole(S: AnsiString);
begin
  WriteLn(S);
end;


procedure DebugProcStdOut(S: AnsiString);
begin
  WriteLn(StdOut, S);
end;


procedure DebugProcSys(S: AnsiString);
begin
  {$IFDEF WINDOWS}
  OutputDebugString(PChar(S));
  {$ENDIF}

  {$IFDEF AROS}
  System.DebugLn(S);
  {$ENDIF}
end;


procedure DebugLn(S: String);
begin
  DebugProc(AnsiString(S));
end;


procedure DebugLn(S: String; Args: Array of Const);
begin
  DebugLn(Format(S, Args));
end;


initialization


begin
  // Setting environment variable <appname>.debug allows for
  // 'choosing' the output debug-channel.
  //
  // <appname> = name of the executable without filename extension
  //
  // Output channels are:
  // SYSTEM  = use OS kernel debug output
  // STDOUT  = use standard output channel (usually console)
  // CONSOLE = use console as output channel (usually stdout)
  // 
  // When no output channel is provided or set channel is not recognized
  // an empty proc will be invoked by default, so that no output will be 
  // written at all
  case UpCase(GetEnv(ApplicationName + '.' + 'debug')) of
    'SYS', 'SYSTEM'  : DebugProc := @DebugProcSys;
    'OUT', 'STDOUT'  : DebugProc := @DebugProcStdOut;
    'CON', 'CONSOLE' : DebugProc := @DebugProcConsole;
    else               DebugProc := @DebugProcEmpty;
  end;
end;


end.
