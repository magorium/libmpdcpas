

  //**! \file
  //* \brief Asynchronous MPD connections
  //*
  //* This class provides a very basic interface to MPD connections.  It
  //* does not know much about the MPD protocol, it does not know any
  //* specific MPD command.
  //*
  //* The constructor expects a socket descriptor which is already
  //* connected to MPD.  The first thing it does is read the server's
  //* handshake code ("OK MPD 0.15.0").
  //**


type
  //**
  //* Event bit mask for polling.
  //**
  {$IFDEF FPC}          // FPC: make use of a set
  Tmpd_async_event_enum =
  (
    //** ready to read from the file descriptor */
    NMPD_ASYNC_EVENT_READ,

    //** ready to write to the file descriptor */
    NMPD_ASYNC_EVENT_WRITE,

    //** hangup detected */
    NMPD_ASYNC_EVENT_HUP,

    //** I/O error */
    NMPD_ASYNC_EVENT_ERROR
  );

  Tmpd_async_event = set of Tmpd_async_event_enum;
  {$ENDIF}


type
  //**
  //* struct mpd_async
  //*
  //* This opaque object represents an asynchronous connection to a MPD
  //* server.  Call mpd_async_new() to create a new instance.
  //**
  Tmpd_async = record end;
  Pmpd_async = ^Tmpd_async;


var
  //**
  //* Creates a new asynchronous MPD connection, based on a stream socket
  //* connected with MPD.
  //*
  //* @param fd the socket file descriptor of the stream connection to MPD
  //* @return a mpd_async object, or NULL on out of memory
  //**
  mpd_async_new                 : function  (fd: cint): Pmpd_async;

  //**
  //* Closes the socket and frees memory.
  //**
  mpd_async_free                : procedure (async: Pmpd_async);

  //**
  //* After an error has occurred, this function returns the error code.
  //* If no error has occurred, it returns #MPD_ERROR_SUCCESS.
  //**
  mpd_async_get_error           : function  (const async: Pmpd_async): Tmpd_error;

  //**
  //* If mpd_async_is_alive() returns false, this function returns the
  //* human readable error message which caused this.  This message is
  //* optional, and may be NULL.  The pointer is invalidated by
  //* mpd_async_free().
  //*
  //* For #MPD_ERROR_SERVER, the error message is encoded in UTF-8.
  //* #MPD_ERROR_SYSTEM obtains its error message from the operating
  //* system, and thus the locale's character set (and probably language)
  //* is used.  Keep that in mind when you print error messages.
  //**
  mpd_async_get_error_message   : function  (const async: Pmpd_async): PChar;

  //**
  //* Returns the error code from the operating system; on most operating
  //* systems, this is the errno value.  Calling this function is only
  //* valid if mpd_async_get_error() returned #MPD_ERROR_SYSTEM.
  //*
  //* May be 0 if the operating system did not specify an error code.
  //**
  mpd_async_get_system_error    : function  (const async: Pmpd_async): cint;

  //**
  //* Returns the file descriptor which should be polled by the caller.
  //* Do not use the file descriptor for anything except polling!  The
  //* file descriptor never changes during the lifetime of this
  //* #mpd_async object.
  //**
  mpd_async_get_fd              : function  (const async: Pmpd_async): cint;

  //**
  //* Enables (or disables) TCP keepalives.
  //*
  //* Keepalives are enabled using the SO_KEEPALIVE socket option.  They may be
  //* required for long-idled connections to persist on some networks that
  //* would otherwise terminate inactive TCP sessions.
  //*
  //* The default value is false.
  //*
  //* @param async the #mpd_async object
  //* @param keepalive whether TCP keepalives should be enabled
  //**
  mpd_async_set_keepalive       : procedure (async: Pmpd_async; keepalive: cbool);

  //**
  //* Returns a bit mask of events which should be polled for.
  //**
  mpd_async_events              : function  (const async: Pmpd_async): Tmpd_async_event;

  //**
  //* Call this function when poll() has returned events for this
  //* object's file descriptor.  libmpdclient will attempt to perform I/O
  //* operations.
  //*
  //* @return false if the connection was closed due to an error
  //**
  mpd_async_io                  : function  (async: Pmpd_async; events: Tmpd_async_event): cbool;

  //**
  //* Appends a command to the output buffer.
  //*
  //* @param async the connection
  //* @param command the command name, followed by arguments, terminated by
  //* NULL
  //* @param args the argument list
  //* @return true on success, false if the buffer is full
  //**
  mpd_async_send_command_v      : function (async: Pmpd_async; const command: PChar; const args: array of PChar): cbool;

  //**
  //* Appends a command to the output buffer.
  //*
  //* @param async the connection
  //* @param command the command name, followed by arguments, terminated by
  //* NULL
  //* @return true on success, false if the buffer is full
  //**
  mpd_async_send_command        : function  (async: Pmpd_async; const command: PChar; const args: array of PChar): cbool;

  //**
  //* Receives a line from the input buffer.  The result will be
  //* null-terminated, without the newline character.  The pointer is
  //* only valid until the next async function is called.
  //*
  //* @param async the connection
  //* @return a line on success, NULL otherwise
  //**
  mpd_async_recv_line           : function  (async: Pmpd_async): PChar;

