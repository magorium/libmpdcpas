

  //**! \file
  //* \brief MPD client library
  //*
  //* Do not include this header directly.  Use mpd/client.h instead.
  //**


type
  //**
  //* struct mpd_directory
  //*
  //* An opaque directory object.  This is a container for more songs,
  //* directories or playlists.
  //**
  Tmpd_directory = record end;
  Pmpd_directory = ^Tmpd_directory;


var
  //**
  //* Duplicates a #mpd_directory object.
  //*
  //* @return the new object, or NULL on out of memory
  //**
  mpd_directory_dup                 : function  (const directory: Pmpd_directory): Pmpd_directory;

  //**
  //* Free memory allocated by the #mpd_directory object.
  //**
  mpd_directory_free                : procedure (directory: Pmpd_directory);

  //**
  //* Returns the path of this directory, relative to the MPD music
  //* directory.  It does not begin with a slash.
  //**
  mpd_directory_get_path            : function  (const directory: Pmpd_directory): PChar;

  //**
  //* @return the POSIX UTC time stamp of the last modification, or 0 if
  //* that is unknown
  //**
  mpd_directory_get_last_modified   : function  (const directory: Pmpd_directory): time_t;

  //**
  //* Begins parsing a new directory.
  //*
  //* @param pair the first pair in this directory (name must be "directory")
  //* @return the new #mpd_entity object, or NULL on error (out of
  //* memory, or pair name is not "directory")
  //**
  mpd_directory_begin               : function  (const pair: Pmpd_pair): Pmpd_directory;

  //**
  //* Parses the pair, adding its information to the specified
  //* #mpd_directory object.
  //*
  //* @return true if the pair was parsed and added to the directory (or if
  //* the pair was not understood and ignored), false if this pair is the
  //* beginning of the next directory
  //**
  mpd_directory_feed                : function  (directory: Pmpd_directory; const pair: Pmpd_pair): cbool;

  //**
  //* Receives the next directory from the MPD server.
  //*
  //* @return a #mpd_directory object, or NULL on error or if the directory list is
  //* finished
  //**
  mpd_recv_directory                : function  (connection: Pmpd_connection): Pmpd_directory;

