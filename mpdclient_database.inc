

  //**! \file
  //* \brief Database
  //*
  //* This file declares functions which query or update MPD's music
  //* database.
  //*
  //* Do not include this header directly.  Use mpd/client.h instead.
  //**


var
  //**
  //* Get a recursive list of all directories, songs and playlist from
  //* MPD.  They are returned without metadata.  This is a rather
  //* expensive operation, because the response may be large.
  //*
  //* @param connection the connection to MPD
  //* @param path an optional base path for the query
  //* @return true on success, false on error
  //**
  mpd_send_list_all         : function  (connection: Pmpd_connection; const path: PChar): cbool;

  //**
  //* Like #mpd_send_list_all(), but return metadata.  This operation is
  //* even more expensive, because the response is larger.  If it is
  //* larger than a configurable server-side limit, MPD may disconnect
  //* you.
  //*
  //* To read the response, you may use mpd_recv_entity().
  //*
  //* @param connection the connection to MPD
  //* @param path an optional base path for the query
  //* @return true on success, false on error
  //**
  mpd_send_list_all_meta    : function  (connection: Pmpd_connection; const path: PChar): cbool;

  //**
  //* Get a list of all directories, songs and playlist in a directory
  //* from MPD, including metadata.
  //*
  //* To read the response, you may use mpd_recv_entity().
  //*
  //* @param connection the connection to MPD
  //* @param path the directory to be listed
  //* @return true on success, false on error
  //**
  mpd_send_list_meta        : function  (connection: Pmpd_connection; const path: PChar): cbool;

  //**
  //* Send "readcomments".  Read the "comments" of a song file.  This
  //* returns key/value pairs which can be read using mpd_recv_pair().
  //*
  //* @param connection the connection to MPD
  //* @param path the relative path of the song file within the music
  //* directory or an arbitrary file path starting with file:///
  //* @return true on success, false on error
  //**
  mpd_send_read_comments    : function  (connection: Pmpd_connection; const path: PChar): cbool;

  //**
  //* Instructs MPD to update the music database: find new files, remove
  //* deleted files, update modified files.
  //*
  //* @param connection the connection to MPD
  //* @param path optional path to update; if NULL, then all of the music
  //* directory is updated
  //* @return true on success, false on error
  //**
  mpd_send_update           : function  (connection: Pmpd_connection; const path: PChar): cbool;

  //**
  //* Like mpd_send_update(), but also rescans unmodified files.
  //*
  //* @param connection the connection to MPD
  //* @param path optional path to update; if NULL, then all of the music
  //* directory is updated
  //* @return true on success, false on error
  //**
  mpd_send_rescan           : function  (connection: Pmpd_connection; const path: PChar): cbool;

  //**
  //* Receives the id the of the update job which was submitted by
  //* mpd_send_update().
  //*
  //* @param connection the connection to MPD
  //* @return a positive job id on success, 0 on error
  //**
  mpd_recv_update_id        : function  (connection: Pmpd_connection): cunsigned;

  //**
  //* Shortcut for mpd_send_update() and mpd_recv_update_id().
  //*
  //* @param connection the connection to MPD
  //* @param path optional path to update; if NULL, then all of the music
  //* directory is updated
  //* @return a positive job id on success, 0 on error
  //**
  mpd_run_update            : function  (connection: Pmpd_connection; const path: PChar): cunsigned;

  //**
  //* Like mpd_run_update(), but also rescans unmodified files.
  //*
  //* @param connection the connection to MPD
  //* @param path optional path to update; if NULL, then all of the music
  //* directory is updated
  //* @return a positive job id on success, 0 on error
  //**
  mpd_run_rescan            : function  (connection: Pmpd_connection; const path: PChar): cunsigned;

