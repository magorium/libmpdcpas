

  //**! \file
  //* \brief MPD client library
  //*
  //* Do not include this header directly.  Use mpd/client.h instead.
  //**


type
  //**
  //* \struct mpd_stats
  //*
  //* An opaque object representing MPD's response to the "stats"
  //* command.  To release this object, call mpd_stats_free().
  //**
  Tmpd_stats = record end;
  Pmpd_stats = ^Tmpd_stats;


var
  //**
  //* Send the "stats" command to MPD.
  //*
  //* @return true on success
  //**
  mpd_send_stats        : function  (connection: Pmpd_connection): cbool;

  //**
  //* Begins parsing server stats: creates a new empty #mpd_stats object.
  //* Free it with mpd_stats_free().
  //* 
  //* @return the newly allocated #mpd_stats object, or NULL if out of
  //* memory
  //**
  mpd_stats_begin                   : function  : Pmpd_stats;

  //**
  //* Parses the pair, adding its information to the specified #mpd_stats
  //* object.
  //**
  mpd_stats_feed                    : procedure (stats: Pmpd_stats; const pair: Pmpd_pair);

  //**
  //* Reads the "stats" response from MPD.
  //*
  //* @return a #mpd_stats object, or NULL on error
  //**
  mpd_recv_stats                    : function  (connection: Pmpd_connection): Pmpd_stats;

  //**
  //* Shortcut for mpd_send_stats() and mpd_recv_stats().
  //**
  mpd_run_stats                     : function  (connection: Pmpd_connection): Pmpd_stats;

  //**
  //* Frees a #mpd_stats object.
  //**
  mpd_stats_free                    : procedure (stats: Pmpd_stats);

  //**
  //* @return the number of distinct artists in MPD's database, or 0 if
  //* unknown
  //**
  mpd_stats_get_number_of_artists   : function  (const stats: Pmpd_stats): cunsigned;

  //**
  //* @return the number of distinct album names in MPD's database, or 0
  //* if unknown
  //**
  mpd_stats_get_number_of_albums    : function  (const stats: Pmpd_stats): cunsigned;

  //**
  //* @return the total number of song files in MPD's database, or 0 if
  //* unknown
  //**
  mpd_stats_get_number_of_songs     : function  (const stats: Pmpd_stats): cunsigned;

  //**
  //* @return the uptime of MPD in seconds, or 0 if unknown
  //**
  mpd_stats_get_uptime              : function  (const stats: Pmpd_stats): culong;

  //**
  //* @return the UNIX time stamp of the last database update, or 0 if
  //* unknown
  //**
  mpd_stats_get_db_update_time      : function  (const stats: Pmpd_stats): culong;

  //**
  //* @return the accumulated time MPD was playing music since the
  //* process was started, or 0 if unknown
  //**
  mpd_stats_get_play_time           : function  (const stats: Pmpd_stats): culong;

  //**
  //* @return the accumulated duration of all songs in the database, or 0
  //* if unknown
  //**
  mpd_stats_get_db_play_time        : function  (const stats: Pmpd_stats): culong;

