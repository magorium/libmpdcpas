

  //**! \file
  //* \brief MPD client library
  //*
  //* Do not include this header directly.  Use mpd/client.h instead.
  //**


type
  //**
  //* The type of a #mpd_entity object.
  //**
  Tmpd_entity_type =
  (
    //**
    //* The type of the entity received from MPD is not implemented
    //* in this version of libmpdclient.
    //**
    NMPD_ENTITY_TYPE_UNKNOWN,

    //**
    //* A directory (#mpd_directory) containing more entities.
    //**
    NMPD_ENTITY_TYPE_DIRECTORY,

    //**
    //* A song file (#mpd_song) which can be added to the playlist.
    //**
    NMPD_ENTITY_TYPE_SONG,

    //**
    //* A stored playlist (#mpd_playlist).
    //**
    NMPD_ENTITY_TYPE_PLAYLIST
  );

  //**
  //* \struct mpd_entity
  //*
  //* An "entity" is an object returned by commands like "lsinfo".  It is
  //* an object wrapping all possible entity types.
  //**
  Tmpd_entity = record end;
  Pmpd_entity = ^Tmpd_entity;


var
  //**
  //* Releases an entity.  This also frees the wrapped object.
  //**
  mpd_entity_free           : procedure (entity: Pmpd_entity);

  //**
  //* @return the type of this entity.
  //**
  mpd_entity_get_type       : function  (const entity: Pmpd_entity): Tmpd_entity_type;

  //**
  //* Obtains a pointer to the #mpd_directory object enclosed by this
  //* #mpd_entity.  Calling this function is only allowed of
  //* mpd_entity_get_type() has returned #MPD_ENTITY_TYPE_DIRECTORY.
  //*
  //* @return the directory object
  //**
  mpd_entity_get_directory  : function  (const entity: Pmpd_entity): Pmpd_directory;

  //**
  //* Obtains a pointer to the #mpd_song object enclosed by this
  //* #mpd_entity.  Calling this function is only allowed of
  //* mpd_entity_get_type() has returned #MPD_ENTITY_TYPE_SONG.
  //*
  //* @return the song object
  //**
  mpd_entity_get_song       : function  (const entity: Pmpd_entity): Pmpd_song;

  //**
  //* Obtains a pointer to the #mpd_playlist object enclosed by
  //* this #mpd_entity.  Calling this function is only allowed of
  //* mpd_entity_get_type() has returned #MPD_ENTITY_TYPE_PLAYLIST.
  //*
  //* @return the directory object
  //**
  mpd_entity_get_playlist   : function  (const entity: Pmpd_entity): Pmpd_playlist;

  //**
  //* Begins parsing a new entity.
  //*
  //* @param pair the first pair in this entity
  //* @return the new #mpd_entity object, or NULL on error (out of memory)
  //**
  mpd_entity_begin          : function  (const pair: Pmpd_pair): Pmpd_entity;

  //**
  //* Parses the pair, adding its information to the specified
  //* #mpd_entity object.
  //*
  //* @return true if the pair was parsed and added to the entity (or if
  //* the pair was not understood and ignored), false if this pair is the
  //* beginning of the next entity
  //**
  mpd_entity_feed           : function  (entity: Pmpd_entity; const pair: Pmpd_pair): cbool;

  //**
  //* Receives the next entity from the MPD server.
  //*
  //* @return an entity object, or NULL on error or if the entity list is
  //* finished
  //**
  mpd_recv_entity           : function  (connection: Pmpd_connection): Pmpd_entity;

