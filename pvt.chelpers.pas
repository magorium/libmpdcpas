unit pvt.chelpers;


//
//  Author      : Magorium
//  Title       : CHelpers
//  Version     : Various (this is not a stable unit and based per project)
//  Description : A unit that helps porting c-projects to Pascal.
//  Note        : 
//  Implementations gathered from various sources and rewritten to Pascal 
//  by author. As such, license from the original code (still) applies.
//  Not intended to be used permanently. If a project uses routines from 
//  this unit then these should (eventually) be replaced by their Pascal 
//  counterpart(s) (if only to avoid licensing issues).
//


{$MODE OBJFPC}{$H+}
{$DEFINE DEBUG_CHELPERS}


interface


uses
  ctypes;
  

Type
  size_t    = cint64;
  float64   = double;
  pvoid     = pointer;
  sigset_t  = LongWord;


type
  {$IFDEF WIN32}
  time_t    = longint;
  
  timeval_p = ^timeval_t;
  timeval_t = 
  record
    tv_sec  : time_t;    // Seconds
    tv_usec : longint;   // Microseconds
  end;
  {$ENDIF}
  
  {$IFDEF AROS}
  time_t    = longint;
  
  timeval_p = ^timeval_t;
  timeval_t = 
  record
    tv_sec  : time_t;    // Seconds
    tv_usec : longint;   // Microseconds
  end;
  {$ENDIF}
  
          //
          // Small helpers
          //
function  IIF(expression: boolean; TrueValue: pointer; FalseValue: pointer): pointer; overload; inline;
function  IIF(expression: boolean; TrueValue: LongWord; FalseValue: LongWord): LongWord; overload; inline;
function  IIF(expression: boolean; TrueValue: Byte; FalseValue: Byte): Byte; overload; inline;
function  IIF(expression: boolean; TrueValue: boolean; FalseValue: boolean): boolean; overload; inline;

          //
          // Memory related functionality
          //
function  malloc(size: SizeInt): pointer; inline;
function  realloc(ptr: pointer; size: csize_t): pointer; inline;
procedure free(p: pointer); inline;

function  memcmp(const ptr1: pointer; const ptr2: pointer; num: csize_t): integer; inline;
function  memcpy(destination: pvoid; const source: pvoid; num: csize_t): pvoid; inline;
function  memmove(destination: pvoid; const source: pvoid; num: csize_t): pvoid; inline;
function  memset(ptr: pvoid; value: byte; num: csize_t): pvoid; inline;
//function  memchr(ptr: pchar; value: char; num: csize_t): pchar;
function  memchr(ptr: pvoid; value: char; num: csize_t): pvoid;
          //
          // char related functionality
          //
function  isalpha(c: char): boolean; inline;
function  isascii(c: char): boolean; inline;
function  isdigit(c: char): boolean; inline;
function  isspace(c: char): boolean; inline;
function  isupper(c: char): boolean; inline;
          //
          // str related functionality
          //
Function  atoi(c: PChar): Integer; inline;
function  atof(const s: PChar): cdouble;
function  strcat(destination: PChar; const source: PChar): PChar;
function  strchr(str: PChar; character: Char): PChar; overload;
function  strcmp(const str1: PChar; const str2: PChar): integer; inline;
function  strdup(const s: PChar): PChar; inline;
function  strncmp(const str1: PChar; const str2: PChar; num: csize_t): integer;
function  strrchr(const str: PChar; character: Char): PChar;
function  strtod(const s: PChar; endptr: PPChar): cdouble;
function  strtof(const s: PChar; endptr: PPChar): cfloat;
function  strtol(const nptr: PChar; endptr: PPChar; base: integer): LongInt;
function  strtoul(const nptr: PChar; endptr: PPChar; base: integer): LongWord;

function  sprintf(s: PChar; const format: PChar; const args: array of const): integer;
function  snprintf(s: PChar; n: csize_t; const fmt: PChar; const args: array of const): integer;

          //
          // Posix
          //
function  strcasecmp(const s1: PChar; const s2: PChar): size_t;
function  strncasecmp(const s1: PChar; const s2: PChar; n: size_t): size_t;
          //
          // file 
          //
function  fgets(s: PChar; num: integer; var stream: Text): PChar;



implementation


uses
  {$IFDEF DEBUG_CHELPERS}
  pvt.simpledebug,
  {$ENDIF}
  Strings,
  SysUtils;


// ############################################################################
//        Small helpers
// ############################################################################


function  IIF(expression: boolean; TrueValue: pointer; FalseValue: pointer): pointer; overload; inline;
begin
  if expression then IIF := truevalue else IIF := falsevalue;
end;


function  IIF(expression: boolean; TrueValue: LongWord; FalseValue: LongWord): LongWord; overload; inline;
begin
  if expression then IIF := truevalue else IIF := falsevalue;
end;


function  IIF(expression: boolean; TrueValue: Byte; FalseValue: Byte): Byte; overload; inline;
begin
  if expression then IIF := truevalue else IIF := falsevalue;
end;


function  IIF(expression: boolean; TrueValue: boolean; FalseValue: boolean): boolean; overload; inline;
begin
  if expression then IIF := truevalue else IIF := falsevalue;
end;


// ############################################################################
//        Memory related functionality
// ############################################################################


function  malloc(size: SizeInt): pointer; inline;
begin
  malloc := System.GetMem(size);
  {$IFDEF DEBUG_CHELPERS}
  DebugLn('< malloc(%d) = $%p >', [size, malloc]);
  {$ENDIF}
end;


function  realloc(ptr: pointer; size: csize_t): pointer; inline;
begin
  realloc := System.ReAllocMem(ptr, size);
end;


procedure free(p: pointer); inline;
begin
  if (p <> nil) then
  begin
    {$IFDEF DEBUG_CHELPER}  
    DebugLn('< free($%p) >', [p]);
    {$ENDIF}
    System.FreeMem(p);
  end
  else 
  begin
    {$IFDEF DEBUG_CHELPER}
    DebugLn('< free($00000000) >');
    {$ENDIF}
  end;
end;


function  memchr(ptr: pvoid; value: char; num: csize_t): pvoid;
var
  res : PChar;
begin
  res := strscan(ptr, value);
  if assigned(res) and ((res - ptr) <= num) then exit(res) else exit(nil);
end;


function  memcmp(const ptr1: pointer; const ptr2: pointer; num: csize_t): integer; inline;
begin
  memcmp := System.CompareByte(ptr1, ptr2, num);
end;


function  memcpy(destination: pvoid; const source: pvoid; num: csize_t): pvoid; inline;
begin
  Move(Source^, Destination^, num);
  memcpy := destination;
end;


function  memmove(destination: pvoid; const source: pvoid; num: csize_t): pvoid; inline;
begin
  Move(Source^, Destination^, num);
  memmove := destination;
end;


function  memset(ptr: pvoid; value: byte; num: csize_t): pvoid; inline;
begin
  FillChar(ptr^, num, value);
  memset := ptr;
end;


// ############################################################################
//        Math related functionality
// ############################################################################


function pow(base: cdouble; exponent: cdouble): cdouble;
begin
  pow := Exp(exponent*Ln(base))
end;


// ############################################################################
//        char related functionality
// ############################################################################


function  isalpha(c: char): boolean; inline;
begin
  isalpha := ( (c >= 'A') and (c <= 'Z') ) or ( (c >= 'a') and (c <= 'z'));
end;


function  isascii(c: char): boolean; inline;
begin
  isascii := ((c >= #0) and (c <= #127));
end;


function  isdigit(c: char): boolean; inline;
begin
  isdigit := ( (c >= '0') and (c <= '9') );
end;


function  isspace(c: char): boolean; inline;
begin
  isspace := ( (c = ' ') or (c = #9) or (c = #10) or (c = #11) or (c = #12) or (c = #13) );
end;


function  isupper(c: char): boolean; inline;
begin
  isupper := ((c >= 'A') and (c <= 'Z'));
end;


function tolower(c: Char): Char;
begin
  tolower := LowerCase(c);
end;


// ############################################################################
//        Str related functionality
// ############################################################################


const
  {$IFDEF CPU16}
  {$ENDIF}
  {$IFDEF CPU32}
  LONG_MAX  = 2147483647;
  LONG_MIN  = (-LONG_MAX - 1);
  ULONG_MAX = 4294967295;
  {$ENDIF}
  {$IFDEF CPU64}
  LONG_MAX  = 9223372036854775807;
  LONG_MIN  = (-LONG_MAX - 1);
  ULONG_MAX = 18446744073709551615;
  {$ENDIF}


Function  atoi(c: PChar): Integer; inline;
begin
  atoi := StrToIntDef(c, -1);
end;


function  atof(const s: PChar): cdouble;
begin
  atof := strtod(s, PPChar(nil));
end;


function  strcat(destination: PChar; const source: PChar): PChar;
begin
  strcat := strings.StrCat(destination, source);
end;


function  strchr(str: PChar; character: Char): PChar; overload;
begin
  strchr := striscan(str, character);
end;


function  strcmp(const str1: PChar; const str2: PChar): integer; inline;
begin
  strcmp := strcomp(str1, str2);
end;


function  strdup(const s: PChar): PChar; inline;
var
  dupe : PChar;
  dptr : PChar;
  sptr : PChar;
begin
  dupe := malloc(strlen(s)+1);
  if (dupe <> nil) then
  begin
    dptr := dupe;
    sptr := s;
    while (sptr^ <> #0) do
    begin
      dptr^ := sptr^;
      inc(dptr);
      inc(sptr);
    end;
    dptr^ := #0;
  end;
  strdup := dupe;
end;


function  strncmp(const str1: PChar; const str2: PChar; num: csize_t): integer;
begin
  strncmp := strlcomp(str1, str2, num);
end;


function  strrchr(const str: PChar; character: Char): PChar;
begin
  strrchr := strrscan(str, character);
end;


function  strtod(const s: PChar; endptr: PPChar): cdouble;
var
  cstr      : PChar;
  val       : cdouble = 0;
  precision : cdouble;
  exp       : integer = 0;
  c         : char = #0;
  c2        : char = #0;
  digits    : integer = 0;
var
  edigits   : integer = 0;
begin
  cstr := s;

  if assigned(endptr)
  then endptr^ := PChar(s);
  
  while (isspace(cstr^))
  do inc(cstr);
  
  if (cstr^ <> #0) then
  begin
    if ( (cstr^ = '+') or (cstr^ = '-') ) then
    begin
      c := cstr^;
      inc(cstr);
    end;

    while (isdigit(cstr^)) do
    begin
      inc(digits);
      val := val * 10 + (Ord(cstr^) - ord('0'));
      inc(cstr);
    end;

    if ( (cstr^ = '.') and ( (digits > 0) or (isdigit((cstr+1)^))) ) then
    begin
      inc(cstr);

      precision := 0.1;
      while (isdigit(cstr^)) do
      begin
        inc(digits);
        val := val + ((Ord(cstr^) - ord('0')) * precision);
        inc(cstr);
        precision := precision * 0.1;
      end;
    end;

    if ( (digits > 0) and (tolower(cstr^) = 'e') ) then
    begin
      edigits := 0;
      inc(cstr);

      if ( (cstr^ = '+') or (cstr^ = '-') ) then 
      begin
        c2 := cstr^;
        inc(cstr);
      end;

      while (isdigit(cstr^)) do
      begin
        inc(edigits);
        exp := exp * 10 + (ord(cstr^) - ord('0'));
        inc(cstr);
      end;

      if (c2 = '-')
      then exp := -exp;

      if (edigits = 0) then
      begin
        dec(cstr); 
        if (c2 <> #0) then dec(cstr);
      end;

      val := val * pow(10, exp);
    end;

    if (c = '-')
    then val := -val;

    if ((digits = 0) and (c <> #0)) then
    begin
      dec(cstr);
    end;
  end;

  if ( (endptr <> nil) and (digits > 0) )
  then endptr^ := PChar(cstr);

  strtod := val;
end;


function  strtof(const s: PChar; endptr: PPChar): cfloat;
begin
  strtof := cfloat( strtod(s, endptr) );
end;


{$DEFINE STDC_STATIC}


function  strtol(const nptr: PChar; endptr: PPChar; base: integer): LongInt;
var
  s     : PChar;

  value : clong;
  ptr   : PChar;
  cpy   : PChar;
begin
  s := nptr;

  while isspace(s^)
  do inc(s);

  cpy := PChar(s);
  
  if (s^ <> #0) then
  begin
    value := strtoul(s, @ptr, base);
    
    if (endptr <> nil) then
    begin
      if (ptr = s)
      then s := cpy
      else s := ptr;
    end;

    if (cpy^ = '-') then
    begin
      if (cslong(value) > 0) then
      begin
        {$ifndef STDC_STATIC}
        errno := ERANGE;
        {$endif}
        value := LONG_MIN;
      end;
    end
    else
    begin
      if (cslong(value) < 0) then
      begin
        {$ifndef STDC_STATIC}
        errno := ERANGE;
        {$endif}
        value := LONG_MAX;
      end;
    end;
  end;

  if (endptr <> nil)
  then endptr^ := PChar(s);

  exit( value );
end;


function  strtoul(const nptr: PChar; endptr: PPChar; base: integer): LongWord;
var
  s         : PChar;
  value     : longword = 0;  
  digit     : cint;  
  c         : char = #0;
  cutoff    : culong;
  cutlim    : cint;
  any       : cint;
begin
  if ( (base < 0) or (base = 1) or (base > 36) ) then
  begin
    {$ifndef STDC_STATIC}
    errno := EINVAL;
    {$endif}
    if assigned(endptr)
    then endptr^ := PChar(nptr);

    exit( 0 );
  end;

  s := nptr;    // keep compiler happy: cannot assign value to const variables

  while (isspace(s^))
  do inc(s);


  if (s^ <> #0) then
  begin
    if ( (s^ = '+') or (s^ = '-') ) then
    begin
      c := s^;
      inc(s);
    end;

    if ( (base = 0) or (base = 16) ) then
    begin
      if (s^ = '0') then
      begin
        inc(s);

        if ( (s^ = 'x') or (s^ = 'X') ) then
        begin
          inc(s);
          base := 16;
        end
        else 
        if (base = 0)
        then base := 8;
      end
      else 
      if (base = 0)
      then base := 10;
    end;

    cutoff := Longword(ULONG_MAX) div longword(base);
    cutlim := longword(ULONG_MAX) mod longword(base);
    value := 0;
    any := 0;

    while (s^ <> #0) do
    begin
      digit := Ord(s^);

      if not(isascii(char(digit)))
      then break;

      if (isdigit(Char(digit))) then
      begin
		digit := digit - ord('0');
      end
      else 
      
      if (isalpha(Char(digit))) then
      begin
        if isupper(Char(digit))
        then digit := digit - ord('A') - 10
        else digit := digit - ord('a') - 10;
	  end
      else
        break;

      if (digit >= base)
      then break;

      if 
      ( 
        (any < 0) or (value > cutoff) or 
        ( 
          (value = cutoff) and (digit > cutlim) 
        ) 
      ) then

      begin
        any := -1;
      end
      else
      begin
        any := 1;
        value := (value * base) + digit;
      end;

      inc(s);
    end;

    if (any < 0) then
    begin
      value := ULONG_MAX;
      {$ifndef STDC_STATIC}
      errno := ERANGE;
      {$endif}
    end;

    if (c = '-')
    then value := -value;
  end;

  if assigned(endptr) 
  then endptr^ := PChar(s);

  exit( value );
end;


// ############################################################################


function  strcasecmp(const s1: PChar; const s2: PChar): size_t;
begin
  strcasecmp := stricomp(s1, s2);
end;


function  strncasecmp(const s1: PChar; const s2: PChar; n: size_t): size_t;
begin
  strncasecmp := StrLIComp(s1, s2, n);
end;


// ############################################################################


function  sprintf(s: PChar; const format: PChar; const args: array of const): integer;
begin
  StrFmt(s, Format, args);
  sprintf := strlen(s);
end;


function  snprintf(s: PChar; n: csize_t; const fmt: PChar; const args: array of const): integer;
begin
  StrLFmt(s, n, fmt, args);
  snprintf := strlen(s);
end;


// ############################################################################


// untested
function  fgets(s: PChar; num: integer; var stream: Text): PChar;
var
  b : PChar;
  c : char;
  i : integer;
begin
  b := s;
  i := 0;
  fgets := nil;
  
  while (i < num) do
  begin
    if not(eof(stream)) then
    begin
      Read(c);
      if c in [#13,#10] then
      begin
        if (c = #10) then
        begin
          // b[i] := #0;
          b[i]   := #10;
          b[i+1] := #00;
          break;
        end;
      end  
      else
      begin
        b[i]   := c;
        b[i+1] := #0;
      end;
    end
    else
    begin
      b[i] := #0;
      break;
    end;
    inc(i);
  end;

  if (i > 0) then fgets := s;
end;


// ############################################################################


end.
