

type
  Tmpd_parser_result =
  (
    //**
    //* Response line was not understood.
    //**
    NMPD_PARSER_MALFORMED,

    //**
    //* MPD has returned "OK" or "list_OK" (check with
    //* mpd_parser_is_discrete()).
    //**
    NMPD_PARSER_SUCCESS,

    //**
    //* MPD has returned "ACK" with an error code.  Call
    //* mpd_parser_get_server_error() to get the error code.
    //**
    NMPD_PARSER_ERROR,

    //**
    //* MPD has returned a name-value pair.  Call
    //* mpd_parser_get_name() and mpd_parser_get_value().
    //**
    NMPD_PARSER_PAIR
  );


type
  //**
  //* struct mpd_parser
  //*
  //* This opaque object is a low-level parser for the MPD protocol.  You
  //* feed it with input lines, and it provides parsed representations.
  //**
  Tmpd_parser =  record end;
  Pmpd_parser = ^Tmpd_parser;

var
  //**
  //* Allocates a new mpd_parser object.  Returns NULL on error (out of
  //* memory).
  //**
  mpd_parser_new                : function  : Pmpd_parser;

  //**
  //* Frees a mpd_parser object.
  //**
  mpd_parser_free               : procedure (parser: Pmpd_parser);

  //**
  //* Feeds a line (without the trailing newline character) received from
  //* MPD / mpd_async_recv_line() into the parser.
  //*
  //* Note that the line parameter is writable, because the parser will
  //* modify it.  The functions mpd_parser_get_name() and
  //* mpd_parser_get_value() will return pointers inside this buffer.
  //* This means that after passing the line to this function, you must
  //* not modify or free it, until the name and value pointers are not
  //* used anymore.
  //*
  //* @param parser the #mpd_parser object
  //* @param line a line received from the MPD server
  //* @return a result code indicating the type of line, or error
  //**
  mpd_parser_feed               : function  (parser: Pmpd_parser; line: PChar): Tmpd_parser_result;

  //**
  //* Call this when mpd_parser_feed() has returned #MPD_PARSER_SUCCESS
  //* to find out whether this is an "OK" (false) or a "list_OK" (true)
  //* response.
  //*
  //* @param parser the #mpd_parser object
  //**
  mpd_parser_is_discrete        : function  (const parser: Pmpd_parser): cbool;

  //**
  //* Call this when mpd_parser_feed() has returned #MPD_PARSER_ERROR to
  //* obtain the reason for the error.
  //*
  //* @param parser the #mpd_parser object
  //**
  mpd_parser_get_server_error   : function  (const parser: Pmpd_parser): Tmpd_server_error;

  //**
  //* On #MPD_PARSER_ERROR, this returns the number of the list command
  //* which failed.  Don't call this outside of a command list.
  //*
  //* @param parser the #mpd_parser object
  //**
  mpd_parser_get_at             : function  (const parser: Pmpd_parser): cunsigned;

  //**
  //* On #MPD_PARSER_ERROR, this returns the human readable error message
  //* returned by MPD (UTF-8).
  //*
  //* This returns a pointer into the line buffer passed to
  //* mpd_parser_feed().  It is valid as long as the buffer is not
  //* freed/modified.
  //*
  //* @param parser the #mpd_parser object
  //**
  mpd_parser_get_message        : function  (const parser: Pmpd_parser): PChar;

  //**
  //* On #MPD_PARSER_PAIR, this returns the name.
  //*
  //* This returns a pointer into the line buffer passed to
  //* mpd_parser_feed().  It is valid as long as the buffer is not
  //* freed/modified.
  //*
  //* @param parser the #mpd_parser object
  //**
  mpd_parser_get_name           : function  (const parser: Pmpd_parser): PChar;

  //**
  //* On #MPD_PARSER_PAIR, this returns the value.
  //*
  //* This returns a pointer into the line buffer passed to
  //* mpd_parser_feed().  It is valid as long as the buffer is not
  //* freed/modified.
  //*
  //* @param parser the #mpd_parser object
  //**
  mpd_parser_get_value          : function  (const parser: Pmpd_parser): PChar;

