

  //**! \file
  //* \brief MPD client library
  //*
  //* Do not include this header directly.  Use mpd/client.h instead.
  //**


type
  //**
  //* \struct mpd_connection
  //*
  //* This opaque object represents a connection to a MPD server.  Call
  //* mpd_connection_new() to create a new instance.  To free an
  //* instance, call mpd_connection_free().
  //* 
  //* Error handling: most functions return a "bool" indicating success
  //* or failure.  In this case, you may query the nature of the error
  //* with the functions mpd_connection_get_error(),
  //* mpd_connection_get_error_message(),
  //* mpd_connection_get_server_error().
  //*
  //* Some errors can be cleared by calling mpd_connection_clear_error(),
  //* like #MPD_ERROR_SERVER, #MPD_ERROR_ARGUMENT.  Most others are
  //* fatal, and cannot be recovered, like #MPD_ERROR_CLOSED -
  //* mpd_connection_clear_error() returns false.
  //*
  //* Some functions like mpd_recv_pair() cannot differentiate between
  //* "end of response" and "error".  If this function returns NULL, you
  //* have to check mpd_connection_get_error().
  //**
  Tmpd_connection =  record end;
  Pmpd_connection = ^Tmpd_connection;


var
  //**
  //* Opens a new connection to a MPD server.  Both the name server
  //* lookup and the connect() call are done synchronously.  After this
  //* function has returned, you should check if the connection was
  //* successful with mpd_connection_get_error().
  //*
  //* @param host the server's host name, IP address or Unix socket path.
  //* If the resolver returns more than one IP address for a host name,
  //* this functions tries all of them until one accepts the connection.
  //* NULL is allowed here, which will connect to the default host
  //* (using the MPD_HOST environment variable if present).
  //* @param port the TCP port to connect to, 0 for default port (using
  //* the MPD_PORT environment variable if present).  If "host" is a Unix
  //* socket path, this parameter is ignored.
  //* @param timeout_ms the timeout in milliseconds, 0 for the default
  //* timeout (the environment variable MPD_TIMEOUT may specify a timeout
  //* in seconds); you may modify it later with
  //* mpd_connection_set_timeout()
  //* @return a mpd_connection object (which may have failed to connect),
  //* or NULL on out-of-memory
  //**
  mpd_connection_new                : function  (host: PChar; port: cunsigned; timeout_ms: cunsigned): Pmpd_connection;

  //**
  //* Creates a #mpd_connection object based on an existing asynchronous
  //* MPD connection.  You should not continue to use the #mpd_async
  //* object.  Note that mpd_connection_free() also frees your #mpd_async
  //* object!
  //*
  //* This function does not block at all, which is why you have to pass
  //* the welcome message to it.
  //*
  //* @param async a #mpd_async instance
  //* @param welcome the first line sent by MPD (the welcome message)
  //* @return a mpd_connection object, or NULL on out-of-memory
  //*
  mpd_connection_new_async          : function  (async: Pmpd_async; const welcome: PChar): Pmpd_connection;

  //**
  //* Close the connection and free all memory.
  //*
  //* @param connection the connection to MPD
  //*
  mpd_connection_free               : procedure (connection: Pmpd_connection);

  //**
  //* Returns the settings which were used to connect to the server.  May
  //* be NULL if the settings are not known.
  //*
  mpd_connection_get_settings       : function  (const connection: Pmpd_connection): Pmpd_settings;

  //**
  //* Enables (or disables) TCP keepalives.
  //*
  //* Keepalives are enabled using the SO_KEEPALIVE socket option.  They may be
  //* required for long-idled connections to persist on some networks that
  //* would otherwise terminate inactive TCP sessions.
  //*
  //* The default value is false.
  //*
  //* @param connection the connection to MPD
  //* @param keepalive whether TCP keepalives should be enabled
  //**
  mpd_connection_set_keepalive      : procedure (connection: Pmpd_connection; keepalive: cbool);

  //**
  //* Sets the timeout for synchronous operations.  If the MPD server
  //* does not send a response during this time span, the operation is
  //* aborted by libmpdclient.
  //*
  //* The initial value is the one passed to mpd_connection_new().  If
  //* you have used mpd_connection_new_async(), then the default value is
  //* 30 seconds.
  //*
  //* @param connection the connection to MPD
  //* @param timeout_ms the desired timeout in milliseconds; must not be 0
  //**
  mpd_connection_set_timeout        : procedure (connection: Pmpd_connection; timeout_ms: cunsigned);

  //**
  //* Returns the file descriptor which should be polled by the caller.
  //* Do not use the file descriptor for anything except polling!  The
  //* file descriptor never changes during the lifetime of this
  //* #mpd_connection object.
  //**
  mpd_connection_get_fd             : function  (const connection: Pmpd_connection): cint;

  //**
  //* Returns the underlying #mpd_async object.  This can be used to send
  //* commands asynchronously.  During an asynchronous command, you must
  //* not use synchronous #mpd_connection functions until the
  //* asynchronous response has been finished.
  //*
  //* If an error occurs while using #mpd_async, you must close the
  //* #mpd_connection.
  //**
  mpd_connection_get_async          : function  (connection: Pmpd_connection): Pmpd_async;

  //**
  //* Returns the libmpdclient error code.  MPD_ERROR_SUCCESS means no
  //* error occurred.
  //**
  mpd_connection_get_error          : function  (const connection: Pmpd_connection): Tmpd_error;

  //**
  //* Returns the human-readable (English) libmpdclient error message.
  //* Calling this function is only valid if an error really occurred.
  //* Check with mpd_connection_get_error().
  //*
  //* For #MPD_ERROR_SERVER, the error message is encoded in UTF-8.
  //* #MPD_ERROR_SYSTEM obtains its error message from the operating
  //* system, and thus the locale's character set (and probably language)
  //* is used.  Keep that in mind when you print error messages.
  //**
  mpd_connection_get_error_message  : function  (const connection: Pmpd_connection): PChar;

  //**
  //* Returns the error code returned from the server.  Calling this
  //* function is only valid if mpd_connection_get_error() returned
  //* #MPD_ERROR_SERVER.
  //**
  mpd_connection_get_server_error   : function  (const connection: Pmpd_connection): Tmpd_server_error;

  //**
  //* Returns the location of the server error, i.e. an index within the
  //* command list.  Calling this function is only valid in a command
  //* list response, and if mpd_connection_get_error() returned
  //* #MPD_ERROR_SERVER.
  //**
  mpd_connection_get_server_error_location  : function  (const connection: Pmpd_connection): cunsigned;

  //**
  //* Returns the error code from the operating system; on most operating
  //* systems, this is the errno value.  Calling this function is only
  //* valid if mpd_connection_get_error() returned #MPD_ERROR_SYSTEM.
  //*
  //* May be 0 if the operating system did not specify an error code.
  //**
  mpd_connection_get_system_error           : function  (const connection: Pmpd_connection): cint;

  //**
  //* Attempts to recover from an error condition.  This function must be
  //* called after a non-fatal error before you can continue using this
  //* object.
  //*
  //* @return true on success, false if the error is fatal and cannot be
  //* recovered
  //**
  mpd_connection_clear_error                : function  (connection: Pmpd_connection): cbool;

  //**
  //* Returns a three-tuple containing the major, minor and patch version
  //* of the MPD protocol.
  //**
  mpd_connection_get_server_version         : function  (const connection: Pmpd_connection): pcunsigned;

  //**
  //* Compares the MPD protocol version with the specified triple.
  //*
  //* @return -1 if the server is older, 1 if it is newer, 0 if it is
  //* equal
  //**
  mpd_connection_cmp_server_version         : function  (const connection: Pmpd_connection; major: cunsigned; minor: cunsigned; patch: cunsigned): cint;

