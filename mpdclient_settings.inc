

  //**! \file
  //* \brief MPD client library
  //*
  //* Library to determine connection settings prior to calling
  //* mpd_connection_new().
  //*
  //* Do not include this header directly.  Use mpd/client.h instead.
  //**


type
  //**
  //* \struct mpd_settings
  //*
  //* An object which describes configurable connection settings.
  //**
  Tmpd_settings = record end;
  Pmpd_settings = ^Tmpd_settings;


var
  //**
  //* Creates a new #mpd_settings object.  The values which are not
  //* passed by the caller are taken from environment variables.
  //*
  //* @param host the server's host name, IP address or Unix socket path.
  //* An address starting with '@' denotes an "abstract socket".
  //* NULL is allowed here, which will connect to the default host
  //* (using the MPD_HOST environment variable if present).
  //* @param port the TCP port to connect to, 0 for default port (using
  //* the MPD_PORT environment variable if present).  If "host" is a Unix
  //* socket path, this parameter is ignored.
  //* @param timeout_ms the timeout in milliseconds, 0 for the default
  //* timeout (the environment variable MPD_TIMEOUT may specify a timeout
  //* in seconds)
  //* @param reserved reserved for future use, pass NULL
  //* @param password the password, or NULL to use the default (MPD_HOST
  //* before "@")
  //* @return a #mpd_settings object or NULL if out of memory
  //**
  mpd_settings_new              : function  (host: PChar; port: cunsigned; timeout_ms: cunsigned; const reserved: PChar; const password: PChar): Pmpd_settings;

  //**
  //* Releases a #mpd_settings object.
  //**
  mpd_settings_free             : procedure (settings: Pmpd_settings);

  //**
  //* Returns the host name (without password/port), or NULL if unknown.
  //**
  mpd_settings_get_host         : function  (const settings: Pmpd_settings): PChar;

  //**
  //* Returns the port number, or 0 if not applicable.
  //**
  mpd_settings_get_port         : function  (const settings: Pmpd_settings): cunsigned;

  //**
  //* Returns the timeout in milliseconds, or 0 if unknown.
  //**
  mpd_settings_get_timeout_ms   : function  (const settings: Pmpd_settings): cunsigned;

  //**
  //* Returns the password, or NULL if none was configured.
  //**
  mpd_settings_get_password     : function  (const settings: Pmpd_settings): PChar;

