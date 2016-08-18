

  //**! \file
  //* \brief MPD client library
  //*
  //* Controlling playback.
  //*
  //* Do not include this header directly.  Use mpd/client.h instead.
  //**


var
  //**
  //* Fetches the currently selected song (the song referenced by
  //* status->song and status->songid).
  //**
  mpd_send_current_song     : function  (connection: Pmpd_connection): cbool;

  //**
  //* Shortcut for mpd_send_currentsong() and mpd_recv_song().
  //*
  //* @param connection the connection to MPD
  //* @return the current song, or NULL on error or if there is no
  //* current song
  //**
  mpd_run_current_song      : function  (connection: Pmpd_connection): Pmpd_song;

  //**
  //* Starts playing the current song from the beginning.
  //*
  //* @param connection the connection to MPD
  //**
  mpd_send_play             : function  (connection: Pmpd_connection): cbool;

  mpd_run_play              : function  (connection: Pmpd_connection): cbool;

  //**
  //* Starts playing the specified song from the beginning.
  //*
  //* @param song_pos the position of the song in the queue
  //* @param connection the connection to MPD
  //* @return true on success, false on error
  //**
  mpd_send_play_pos         : function  (connection: Pmpd_connection; song_pos: cunsigned): cbool;

  mpd_run_play_pos          : function  (connection: Pmpd_connection; song_pos: cunsigned): cbool;

  //**
  //* Starts playing the specified song from the beginning.
  //*
  //* @param connection the connection to MPD
  //* @param id the id of the song
  //* @return true on success, false on error
  //**
  mpd_send_play_id          : function  (connection: Pmpd_connection; id: cunsigned): cbool;

  mpd_run_play_id           : function  (connection: Pmpd_connection; song_id: cunsigned): cbool;

  mpd_send_stop             : function  (connection: Pmpd_connection): cbool;

  mpd_run_stop              : function  (connection: Pmpd_connection): cbool;

  //**
  //* Toggles the pause mode by sending "pause" without arguments.
  //*
  //* @param connection the connection to MPD
  //**
  mpd_send_toggle_pause     : function  (connection: Pmpd_connection): cbool;

  mpd_run_toggle_pause      : function  (connection: Pmpd_connection): cbool;

  mpd_send_pause            : function  (connection: Pmpd_connection; mode: cbool): cbool;

  mpd_run_pause             : function  (connection: Pmpd_connection; mode: cbool): cbool;

  mpd_send_next             : function  (connection: Pmpd_connection): cbool;

  mpd_run_next              : function  (connection: Pmpd_connection): cbool;

  mpd_send_previous         : function  (connection: Pmpd_connection): cbool;

  mpd_run_previous          : function  (connection: Pmpd_connection): cbool;

  //**
  //* Seeks the specified song.
  //*
  //* @param connection the connection to MPD
  //* @param song_pos the position of the song in the queue
  //* @param t the position within the song, in seconds
  //* @return true on success, false on error
  //**
  mpd_send_seek_pos         : function  (connection: Pmpd_connection; song_pos: cunsigned; t: cunsigned): cbool;

  mpd_run_seek_pos          : function  (connection: Pmpd_connection; song_pos: cunsigned; t: cunsigned): cbool;

  //**
  //* Seeks the specified song.
  //*
  //* @param connection the connection to MPD
  //* @param id the id of the song
  //* @param t the position within the song, in seconds
  //* @return true on success, false on error
  //**
  mpd_send_seek_id          : function  (connection: Pmpd_connection; id: cunsigned; t: cunsigned): cbool;

  mpd_run_seek_id           : function  (connection: Pmpd_connection; song_id: cunsigned; t: cunsigned): cbool;

  mpd_send_repeat           : function  (connection: Pmpd_connection; mode: cbool): cbool;

  mpd_run_repeat            : function  (connection: Pmpd_connection; mode: cbool): cbool;

  mpd_send_random           : function  (connection: Pmpd_connection; mode: cbool): cbool;

  mpd_run_random            : function  (connection: Pmpd_connection; mode: cbool): cbool;

  mpd_send_single           : function  (connection: Pmpd_connection; mode: cbool): cbool;

  mpd_run_single            : function  (connection: Pmpd_connection; mode: cbool): cbool;

  mpd_send_consume          : function  (connection: Pmpd_connection; mode: cbool): cbool;

  mpd_run_consume           : function  (connection: Pmpd_connection; mode: cbool): cbool;

  mpd_send_crossfade        : function  (connection: Pmpd_connection; seconds: cunsigned): cbool;

  mpd_run_crossfade         : function  (connection: Pmpd_connection; seconds: cunsigned): cbool;

  mpd_send_mixrampdb        : function  (connection: Pmpd_connection; db: cfloat): cbool;

  mpd_run_mixrampdb         : function  (connection: Pmpd_connection; db: cfloat): cbool;

  mpd_send_mixrampdelay     : function  (connection: Pmpd_connection; seconds: cfloat): cbool;

  mpd_run_mixrampdelay      : function  (connection: Pmpd_connection; seconds: cfloat): cbool;

  mpd_send_clearerror       : function  (connection: Pmpd_connection): cbool;

  mpd_run_clearerror        : function  (connection: Pmpd_connection): cbool;

