

  //**! \file
  //* \brief MPD client library
  //*
  //* Do not include this header directly.  Use mpd/client.h instead.
  //**


type
  //**
  //* \struct mpd_song
  //*
  //* An opaque representation for a song in MPD's database or playlist.
  //* Use the functions provided by this header to access the object's
  //* attributes.
  //**
  Tmpd_song = record end;
  Pmpd_song = ^Tmpd_song;


var
  //**
  //* Free memory allocated by the #mpd_song object.
  //**
  mpd_song_free                 : procedure (song: Pmpd_song);

  //**
  //* Duplicates the specified #mpd_song object.
  //*
  //* @returns the copy, or NULL if out of memory
  //**
  mpd_song_dup                  : function  (const song: Pmpd_song): Pmpd_song;

  //**
  //* Returns the URI of the song.  This is either a path relative to the
  //* MPD music directory (without leading slash), or an URL with a
  //* scheme, e.g. a HTTP URL for a radio stream.
  //**
  mpd_song_get_uri              : function  (const song: Pmpd_song): PChar;

  //**
  //* Queries a tag value.
  //*
  //* @param song the song object
  //* @param type the tag type
  //* @param idx pass 0 to get the first value for this tag type.  This
  //* argument may be used to iterate all values, until this function
  //* returns NULL
  //* @return the tag value, or NULL if this tag type (or this index)
  //* does not exist
  //**
  mpd_song_get_tag              : function  (const song: Pmpd_song; typ: Tmpd_tag_type; idx: cunsigned): PChar;

  //**
  //* Returns the duration of this song in seconds.  0 means the duration
  //* is unknown.
  //**
  mpd_song_get_duration         : function  (const song: Pmpd_song): cunsigned;

  //**
  //* Returns the duration of this song in milliseconds.  0 means the
  //* duration is unknown.
  //**
  mpd_song_get_duration_ms      : function  (const song: Pmpd_song): cunsigned;

  //**
  //* Returns the start of the virtual song within the physical file in
  //* seconds.
  //**
  mpd_song_get_start            : function  (const song: Pmpd_song): cunsigned;

  //**
  //* Returns the end of the virtual song within the physical file in
  //* seconds.  Zero means that the physical song file is played to the
  //* end.
  //**
  mpd_song_get_end              : function  (const song: Pmpd_song): cunsigned;

  //**
  //* @return the POSIX UTC time stamp of the last modification, or 0 if
  //* that is unknown
  //**
  mpd_song_get_last_modified    : function  (const song: Pmpd_song): time_t;

  //**
  //* Sets the position within the queue.  This value is not used for
  //* songs which are not in the queue.
  //*
  //* This function is useful when applying the values returned by
  //* mpd_recv_queue_change_brief().
  //**
  mpd_song_set_pos              : procedure (song: Pmpd_song; pos: cunsigned);

  //**
  //* Returns the position of this song in the queue.  The value is
  //* undefined if you did not obtain this song from the queue.
  //**
  mpd_song_get_pos              : function  (const song: Pmpd_song): cunsigned;

  //**
  //* Returns the id of this song in the playlist.  The value is
  //* undefined if you did not obtain this song from the queue.
  //**
  mpd_song_get_id               : function  (const song: Pmpd_song): cunsigned;

  //**
  //* Returns the priority of this song in the playlist.  The value is
  //* undefined if you did not obtain this song from the queue.
  //**
  mpd_song_get_prio             : function  (const song: Pmpd_song): cunsigned;

  //**
  //* Begins parsing a new song.
  //*
  //* @param pair the first pair in this song (name must be "file")
  //* @return the new #mpd_entity object, or NULL on error (out of
  //* memory, or pair name is not "file")
  //**
  mpd_song_begin                : function  (const pair: Pmpd_pair): Pmpd_song;

  //**
  //* Parses the pair, adding its information to the specified
  //* #mpd_song object.
  //*
  //* @return true if the pair was parsed and added to the song (or if
  //* the pair was not understood and ignored), false if this pair is the
  //* beginning of the next song
  //**
  mpd_song_feed                 : function  (song: Pmpd_song; const pair: Pmpd_pair): cbool;

  //**
  //* Receives the next song from the MPD server.
  //*
  //* @return a #mpd_song object, or NULL on error or if the song list is
  //* finished
  //**
  mpd_recv_song                 : function  (connection: Pmpd_connection): Pmpd_song;

