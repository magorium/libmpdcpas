

  //**! \file
  //* \brief MPD client library
  //*
  //* Manipulate stickers.
  //*
  //* Do not include this header directly.  Use mpd/client.h instead.
  //**


var
  //**
  //* Adds or replaces a sticker value.
  //*
  //* @param connection the connection to MPD
  //* @param type the object type, e.g. "song"
  //* @param uri the URI of the object
  //* @param name the name of the sticker
  //* @param value the value of the sticker
  //* @return true on success, false on error
  //**
  mpd_send_sticker_set      : function  (connection: Pmpd_connection; const typ: PChar; const uri: PChar; const name: PChar; const value: PChar): cbool;

  //**
  //* Shortcut for mpd_send_sticker_set() and mpd_response_finish().
  //*
  //* @param connection the connection to MPD
  //* @param type the object type, e.g. "song"
  //* @param uri the URI of the object
  //* @param name the name of the sticker
  //* @param value the value of the sticker
  //* @return true on success, false on error
  //**
  mpd_run_sticker_set       : function  (connection: Pmpd_connection; const typ: PChar; const uri: PChar; const name: PChar; const value: PChar): cbool;

  //**
  //* Deletes a sticker value.
  //*
  //* @param connection the connection to MPD
  //* @param type the object type, e.g. "song"
  //* @param uri the URI of the object
  //* @param name the name of the sticker
  //* @return true on success, false on error
  //**
  mpd_send_sticker_delete   : function  (connection: Pmpd_connection; const typ: PChar; const uri: PChar; const name: PChar): cbool;

  //**
  //* Shortcut for mpd_send_sticker_delete() and mpd_response_finish().
  //*
  //* @param connection the connection to MPD
  //* @param type the object type, e.g. "song"
  //* @param uri the URI of the object
  //* @param name the name of the sticker
  //* @return true on success, false on error
  //**
  mpd_run_sticker_delete    : function  (connection: Pmpd_connection; const typ: PChar; const uri: PChar; const name: PChar): cbool;

  //**
  //* Queries a sticker value.  Call mpd_recv_sticker() to receive the response.
  //*
  //* @param connection the connection to MPD
  //* @param type the object type, e.g. "song"
  //* @param uri the URI of the object
  //* @param name the name of the sticker
  //* @return true on success, false on error
  //**
  mpd_send_sticker_get      : function  (connection: Pmpd_connection; const typ: PChar; const uri: PChar; const name: PChar): cbool;

  //**
  //* Obtains a list of all stickers of the specified object.  Call
  //* mpd_recv_sticker() to receive each response item.
  //*
  //* @param connection the connection to MPD
  //* @param type the object type, e.g. "song"
  //* @param uri the URI of the object
  //* @return true on success, false on error
  //**
  mpd_send_sticker_list     : function  (connection: Pmpd_connection; const typ: PChar; const uri: PChar): cbool;

  //**
  //* Searches for stickers with the specified name.
  //*
  //* @param connection the connection to MPD
  //* @param type the object type, e.g. "song"
  //* @param base_uri the base URI to start the search, e.g. a directory;
  //* NULL to search for all objects of the specified type
  //* @param name the name of the sticker
  //* @return true on success, false on error
  //**
  mpd_send_sticker_find     : function  (connection: Pmpd_connection; const typ: PChar; const base_uri: PChar; const name: PChar): cbool;

  //**
  //* Parse a sticker input line in the form "name=value".
  //*
  //* @param input the input value, the value from a received pair named
  //* "sticker"
  //* @param name_length_r the length of the name (starting at the
  //* beginning of the input string) is returned here
  //* @return a pointer to the sticker value, or NULL on error
  //**
  mpd_parse_sticker         : function  (const input: PChar; name_length_r: pcsize_t): PChar;

  //**
  //* Receives the next sticker.  You have to free the return value with
  //* mpd_return_sticker().
  //*
  //* @param connection the connection to MPD
  //* @return a #mpd_pair object on success, NULL on end of response or
  //* error
  //**
  mpd_recv_sticker          : function  (connection: Pmpd_connection): Pmpd_pair;

  //**
  //* Free the pair returned by mpd_recv_sticker().
  //**
  mpd_return_sticker        : procedure (connection: Pmpd_connection; pair: Pmpd_pair);

