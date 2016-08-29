

  //**! \file
  //* \brief MPD client library
  //*
  //* Do not include this header directly.  Use mpd/client.h instead.
  //**


type
  //**
  //* MPD's playback state.
  //**
  Tmpd_state =
  (
    //** no information available */
    NMPD_STATE_UNKNOWN           = 0,

    //** not playing */
    NMPD_STATE_STOP              = 1,

    //** playing */
    NMPD_STATE_PLAY              = 2,

    //** playing, but paused */
    NMPD_STATE_PAUSE             = 3
  );

  //**
  //* \struct mpd_status
  //*
  //* Holds information about MPD's status.
  //**
  Tmpd_status = record end;
  Pmpd_status = ^Tmpd_status;


var
  //**
  //* Begins parsing the server status: creates a new empty #mpd_status
  //* object.  Free it with mpd_status_free().
  //*
  //* @return the newly allocated #mpd_status object, or NULL if out of
  //* memory
  //**
  mpd_status_begin              : function  : Pmpd_status;

  //**
  //* Parses the pair, adding its information to the specified
  //* #mpd_status object.
  //**
  mpd_status_feed               : procedure (status: Pmpd_status; const pair: Pmpd_pair);

  //**
  //* Sends the "status" command to MPD.  Call mpd_recv_status() to read
  //* the response.
  //*
  //* @return true on success
  //**
  mpd_send_status               : function  (connection: Pmpd_connection): cbool;

  //**
  //* Receives a #mpd_status object from the server.
  //*
  //* @return the received #mpd_status object, or NULL on error
  //**
  mpd_recv_status               : function  (connection: Pmpd_connection): Pmpd_status;

  //**
  //* Executes the "status" command and reads the response.
  //*
  //* @return the #mpd_status object returned by the server, or NULL on
  //* error
  //**
  mpd_run_status                : function  (connection: Pmpd_connection): Pmpd_status;

  //**
  //* Releases a #mpd_status object.
  //**
  mpd_status_free               : procedure (status: Pmpd_status);

  //**
  //* Returns the current volume: 0-100, or -1 when there is no volume
  //* support.
  //**
  mpd_status_get_volume         : function  (const status: Pmpd_status): cint;

  //**
  //* Returns true if repeat mode is on.
  //**
  mpd_status_get_repeat         : function  (const status: Pmpd_status): cbool;

  //**
  //* Returns true if random mode is on.
  //**
  mpd_status_get_random         : function  (const status: Pmpd_status): cbool;

  //**
  //* Returns true if single mode is on.
  //**
  mpd_status_get_single         : function  (const status: Pmpd_status): cbool;

  //**
  //* Returns true if consume mode is on.
  //**
  mpd_status_get_consume        : function  (const status: Pmpd_status): cbool;

  //**
  //* Returns the number of songs in the queue.  If MPD did not
  //* specify that, this function returns 0.
  //**
  mpd_status_get_queue_length   : function  (const status: Pmpd_status): cunsigned;

  //**
  //* Returns queue version number.  You may use this to determine
  //* when the queue has changed since you have last queried it.
  //**
  mpd_status_get_queue_version  : function  (const status: Pmpd_status): cunsigned;

  //**
  //* Returns the state of the player: either stopped, playing or paused.
  //**
  mpd_status_get_state          : function  (const status: Pmpd_status): Tmpd_state;

  //**
  //* Returns crossfade setting in seconds.  0 means crossfading is
  //* disabled.
  //**
  mpd_status_get_crossfade      : function  (const status: Pmpd_status): cunsigned;

  //**
  //* Returns mixrampdb setting in db.
  //**
  mpd_status_get_mixrampdb      : function  (const status: Pmpd_status): cfloat;

  //**
  //* Returns mixrampdelay setting in seconds.  Negative means mixramp is
  //* disabled.
  //**
  mpd_status_get_mixrampdelay   : function  (const status: Pmpd_status): cfloat;

  //**
  //* Returns the position of the currently playing song in the queue
  //* (beginning with 0) if a song is currently selected (always the case when
  //* state is PLAY or PAUSE).  If there is no current song, -1 is returned.
  //**
  mpd_status_get_song_pos       : function  (const status: Pmpd_status): cint;

  //**
  //* Returns the id of the current song.  If there is no current song,
  //* -1 is returned.
  //**
  mpd_status_get_song_id        : function  (const status: Pmpd_status): cint;

  //**
  //* The same as mpd_status_get_next_song_pos, but for the next song to be
  //* played.
  //**
  mpd_status_get_next_song_pos  : function  (const status: Pmpd_status): cint;

  //**
  //* Returns the id of the next song to be played.  If it is not known, -1 is
  //* returned.
  //**
  mpd_status_get_next_song_id   : function  (const status: Pmpd_status): cint;

  //**
  //* Returns time in seconds that have elapsed in the currently playing/paused
  //* song
  //**
  mpd_status_get_elapsed_time   : function  (const status: Pmpd_status): cunsigned;

  //**
  //* Returns time in milliseconds that have elapsed in the currently
  //* playing/paused song.
  //**
  mpd_status_get_elapsed_ms     : function  (const status: Pmpd_status): cunsigned;

  //**
  //* Returns the length in seconds of the currently playing/paused song
  //**
  mpd_status_get_total_time     : function  (const status: Pmpd_status): cunsigned;

  //**
  //* Returns current bit rate in kbps.  0 means unknown.
  //**
  mpd_status_get_kbit_rate      : function  (const status: Pmpd_status): cunsigned;

  //**
  //* Returns audio format which MPD is currently playing.  May return
  //* NULL if MPD is not playing or if the audio format is unknown.
  //**
  mpd_status_get_audio_format   : function  (const status: Pmpd_status): Pmpd_audio_format;

  //**
  //* Returns 1 if mpd is updating, 0 otherwise
  //**
  mpd_status_get_update_id      : function  (const status: Pmpd_status): cunsigned;

  //**
  //* Returns the error message
  //**
  mpd_status_get_error          : function  (const status: Pmpd_status): PChar;

