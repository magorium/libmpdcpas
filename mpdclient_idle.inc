

  //**! \file
  //* \brief MPD client library
  //*
  //* Do not include this header directly.  Use mpd/client.h instead.
  //**


type
  //**
  //* This enum contains bit masks for all idle events.
  //**
  {$IFDEF FPC}          // FPC: make use of a set
  Tmpd_idle_enum =
  (
    //** song database has been updated*/
    NMPD_IDLE_DATABASE,

    //** a stored playlist has been modified, created, deleted or renamed */
    NMPD_IDLE_STORED_PLAYLIST,

    //** the queue has been modified */
    NMPD_IDLE_QUEUE,

    //** deprecated, don't use */
    NMPD_IDLE_PLAYLIST, //           = NMPD_IDLE_QUEUE,

    //** the player state has changed: play, stop, pause, seek, ... */
    NMPD_IDLE_PLAYER,

    //** the volume has been modified */
    NMPD_IDLE_MIXER,

    //** an audio output device has been enabled or disabled */
    NMPD_IDLE_OUTPUT,

    //** options have changed: crossfade, random, repeat, ... */
    NMPD_IDLE_OPTIONS,

    //** a database update has started or finished. */
    NMPD_IDLE_UPDATE,

    //** a sticker has been modified. */
    NMPD_IDLE_STICKER,

    //** a client has subscribed to or unsubscribed from a channel */
    NMPD_IDLE_SUBSCRIPTION,

    //** a message on a subscribed channel was received */
    NMPD_IDLE_MESSAGE
  );

  Tmpd_idle = set of Tmpd_idle_enum;
  {$ENDIF}


var
  //**
  //* Returns the name of the specified idle event.
  //*
  //* @param idle an idle event id
  //* @return the name, or NULL if that event is not known
  //**
  mpd_idle_name         : function  (idle: Tmpd_idle_enum): PChar;

  //**
  //* Parses the name of an idle event.
  //*
  //* @param name an idle event name
  //* @return the id, or 0 if that event is not known
  //**
  mpd_idle_name_parse   : function  (const name: PChar): Tmpd_idle;

  //**
  //* Enters "idle" mode: MPD will stall the response until an event has
  //* occurred.  Call mpd_send_noidle() to abort the idle mode, or
  //* mpd_recv_idle() to read the event mask (or synchronously wait for
  //* events).
  //**
  mpd_send_idle         : function  (connection: Pmpd_connection): cbool;

  //**
  //* Same as mpd_send_idle(), but listen only on specific events.
  //*
  //* @param connection the connection to MPD
  //* @param mask a bit mask of idle events; must not be 0
  //* @return a positive job id on success, 0 on error
  //**
  mpd_send_idle_mask    : function  (connection: Pmpd_connection; mask: Tmpd_idle): cbool;

  //**
  //* Tells MPD to leave the "idle" mode.  MPD will then respond with a
  //* list of events which have occurred (which may be empty).  Call
  //* mpd_recv_idle() after that.
  //**
  mpd_send_noidle       : function  (connection: Pmpd_connection): cbool;

  //**
  //* Parses a "changed" pair, which is part of MPD's response to the
  //* "idle" command.
  //*
  //* @return an idle code, or 0 if the pair was not understood
  //**
  mpd_idle_parse_pair   : function  (const pair: Pmpd_pair): Tmpd_idle;

  //**
  //* Waits until MPD sends the list of idle events and returns it in a
  //* bit mask.
  //*
  //* @param connection the connection to MPD
  //* @param disable_timeout if true, then libmpdclients temporarily
  //* disables the configured timeout (see mpd_connection_set_timeout()):
  //* this function blocks forever, until either MPD sends a response, or
  //* an error occurs.
  //* @return the event bit mask, or 0 on error or if there were no
  //* events
  //**
  mpd_recv_idle         : function  (connection: Pmpd_connection; disable_timeout: cbool): Tmpd_idle;

  //**
  //* Shortcut for mpd_send_idle() and mpd_recv_idle().  During
  //* mpd_recv_idle(), the configured timeout is disabled.
  //*
  //* @param connection the connection to MPD
  //* @return the event bit mask, or 0 on error
  //**
  mpd_run_idle          : function  (connection: Pmpd_connection): Tmpd_idle;

  //**
  //* Shortcut for mpd_send_idle_mask() and mpd_recv_idle().  During
  //* mpd_recv_idle(), the configured timeout is disabled.
  //*
  //* @param connection the connection to MPD
  //* @param mask a bit mask of idle events; must not be 0
  //* @return the event bit mask, or 0 on error
  //**
  mpd_run_idle_mask     : function  (connection: Pmpd_connection; mask: Tmpd_idle): Tmpd_idle;

  //**
  //* Shortcut for mpd_send_noidle() and mpd_recv_idle().  During
  //* mpd_recv_idle(), the configured timeout is not disabled.
  //*
  //* @param connection the connection to MPD
  //* @return the event bit mask, or 0 on error or if there were no
  //* events
  //**
  mpd_run_noidle        : function  (connection: Pmpd_connection): Tmpd_idle;

