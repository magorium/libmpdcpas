

  //**! \file
  //* \brief MPD client library
  //*
  //* Manipulate stored playlists.
  //*
  //* Do not include this header directly.  Use mpd/client.h instead.
  //**


type
  //**
  //* \struct mpd_playlist
  //*
  //* An opaque representation for a playlist stored in MPD's
  //* playlist directory.  Use the functions provided by this header to
  //* access the object's attributes.
  //**
  Tmpd_playlist = record end;
  Pmpd_playlist = ^Tmpd_playlist;


var
  //**
  //* Free memory allocated by the #mpd_playlist object.
  //**
  mpd_playlist_free                 : procedure (playlist: Pmpd_playlist);

  //**
  //* Duplicates a #mpd_playlist object.
  //*
  //* @return the new object, or NULL on out of memory
  //**
  mpd_playlist_dup                  : function  (const playlist: Pmpd_playlist): Pmpd_playlist;

  //**
  //* Returns the path name of this playlist file.  It does not begin
  //* with a slash.
  //**
  mpd_playlist_get_path             : function  (const playlist: Pmpd_playlist): PChar;

  //**
  //* @return the POSIX UTC time stamp of the last modification, or 0 if
  //* that is unknown
  //**
  mpd_playlist_get_last_modified    : function  (const playlist: Pmpd_playlist): time_t;

  //**
  //* Begins parsing a new playlist.
  //*
  //* @param pair the first pair in this playlist (name must be
  //* "playlist")
  //* @return the new #mpd_entity object, or NULL on error (out of
  //* memory, or pair name is not "playlist")
  //**
  mpd_playlist_begin                : function  (const pair: Pmpd_pair): Pmpd_playlist;

  //**
  //* Parses the pair, adding its information to the specified
  //* #mpd_playlist object.
  //*
  //* @return true if the pair was parsed and added to the playlist (or if
  //* the pair was not understood and ignored), false if this pair is the
  //* beginning of the next playlist
  //**
  mpd_playlist_feed                 : function  (playlist: Pmpd_playlist; const pair: Pmpd_pair): cbool;

  //**
  //* Obtain a list of stored playlists.
  //*
  //* @param connection the connection to MPD
  //* @return true on success, false on error
  //**
  mpd_send_list_playlists           : function  (connection: Pmpd_connection): cbool;

  //**
  //* List the content of a stored playlist.
  //*
  //* @param connection the connection to MPD
  //* @param name the name of the playlist
  //* @return true on success, false on error
  //**
  mpd_recv_playlist                 : function  (connection: Pmpd_connection): Pmpd_playlist;

  //**
  //* List the content, with full metadata, of a stored playlist.
  //*
  //* @param connection the connection to MPD
  //* @param name the name of the playlist
  //* @return true on success, false on error
  //**
  mpd_send_list_playlist            : function  (connection: Pmpd_connection; const name: PChar): cbool;

  mpd_send_list_playlist_meta       : function  (connection: Pmpd_connection; const name: PChar): cbool;

  mpd_send_playlist_clear           : function  (connection: Pmpd_connection; const name: PChar): cbool;

  mpd_run_playlist_clear            : function  (connection: Pmpd_connection; const name: PChar): cbool;

  mpd_send_playlist_add             : function  (connection: Pmpd_connection; const name: PChar; const path: PChar): cbool;

  mpd_run_playlist_add              : function  (connection: Pmpd_connection; const name: PChar; const path: PChar): cbool;

  mpd_send_playlist_move            : function  (connection: Pmpd_connection; const name: PChar; from: cunsigned; topos: cunsigned): cbool;

  mpd_send_playlist_delete          : function  (connection: Pmpd_connection; const name: PChar; pos: cunsigned): cbool;

  mpd_run_playlist_delete           : function  (connection: Pmpd_connection; const name: PChar; pos: cunsigned): cbool;

  mpd_send_save                     : function  (connection: Pmpd_connection; const name: PChar): cbool;

  mpd_run_save                      : function  (connection: Pmpd_connection; const name: PChar): cbool;

  mpd_send_load                     : function  (connection: Pmpd_connection; const name: PChar): cbool;

  mpd_run_load                      : function  (connection: Pmpd_connection; const name: PChar): cbool;

  mpd_send_rename                   : function  (connection: Pmpd_connection; const from: PChar; const tpos: PChar): cbool;

  mpd_run_rename                    : function  (connection: Pmpd_connection; const from: PChar; const tpos: PChar): cbool;

  mpd_send_rm                       : function  (connection: Pmpd_connection; const name: PChar): cbool;

  mpd_run_rm                        : function  (connection: Pmpd_connection; const name: PChar): cbool;

