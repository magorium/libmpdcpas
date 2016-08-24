

  //**! \file
  //* \brief MPD client library
  //*
  //* Search songs in the database or the queue.
  //*
  //* Do not include this header directly.  Use mpd/client.h instead.
  //**


type
  //**
  //* This type is not yet used, it is reserved for a future protocol
  //* extension which will allow us to specify a comparison operator for
  //* constraints.
  //**
  Tmpd_operator =
  (
    //**
    //* The default search operator.  If "exact" was passed as
    //* "true", then it means "full string comparison"; if false,
    //* then it means "search for substring".
    //**
     NMPD_OPERATOR_DEFAULT
  );


var
  //**
  //* Search for songs in the database.
  //* Constraints may be specified with mpd_search_add_tag_constraint().
  //* Send the search command with mpd_search_commit(), and read the
  //* response items with mpd_recv_song().
  //*
  //* @param connection the connection to MPD
  //* @param exact if to match exact
  //* @return true on success, false on error
  //**
  mpd_search_db_songs               : function  (connection: Pmpd_connection; exact: cbool): cbool;

  //**
  //* Search for songs in the database and adds the result to the queue.
  //* Constraints may be specified with mpd_search_add_tag_constraint().
  //* Send the search command with mpd_search_commit().
  //*
  //* @param connection the connection to MPD
  //* @param exact if to match exact (only "true" supported by MPD 0.16)
  //* @return true on success, false on error
  //**
  mpd_search_add_db_songs           : function  (connection: Pmpd_connection; exact: cbool): cbool;

  //**
  //* Search for songs in the queue.
  //* Constraints may be specified with mpd_search_add_tag_constraint().
  //* Send the search command with mpd_search_commit(), and read the
  //* response items with mpd_recv_song().
  //*
  //* @param connection the connection to MPD
  //* @param exact if to match exact
  //* @return true on success, false on error
  //**
  mpd_search_queue_songs            : function  (connection: Pmpd_connection; exact: cbool): cbool;

  //**
  //* Obtains a list of unique tag values from the database.
  //* Constraints may be specified with mpd_search_add_tag_constraint().
  //* Send the search command with mpd_search_commit(), and read the
  //* response items with mpd_recv_pair_tag().
  //*
  //* @param connection the connection to MPD
  //* @param type The type of the tags to search for
  //* @return true on success, false on error
  //**
  mpd_search_db_tags                : function  (connection: Pmpd_connection; typ: Tmpd_tag_type): cbool;

  //**
  //* Gathers statistics on a set of songs in the database.
  //* Constraints may be specified with mpd_search_add_tag_constraint().
  //* Send the command with mpd_search_commit(), and read the response
  //* with mpd_recv_stats().
  //*
  //* @param connection the connection to MPD
  //* @return true on success, false on error
  //**
  mpd_count_db_songs                : function  (connection: Pmpd_connection): cbool;

  //**
  //* Limit the search to a certain directory.
  //*
  //* @param connection a #mpd_connection
  //* @param oper reserved, pass #MPD_OPERATOR_DEFAULT
  //* @param value the URI relative to the music directory
  //* @return true on success, false on error
  //**
  mpd_search_add_base_constraint    : function  (connection: Pmpd_connection; oper: Tmpd_operator; const value: PChar): cbool;

  //**
  //* Add a constraint on the song's URI.
  //*
  //* @param connection a #mpd_connection
  //* @param oper reserved, pass #MPD_OPERATOR_DEFAULT
  //* @param value The value of the constraint
  //* @return true on success, false on error
  //**
  mpd_search_add_uri_constraint     : function  (connection: Pmpd_connection; oper: Tmpd_operator; const value: PChar): cbool;

  //**
  //* Add a constraint to a search limiting the value of a tag.
  //*
  //* @param connection a #mpd_connection
  //* @param oper reserved, pass #MPD_OPERATOR_DEFAULT
  //* @param type The tag type of the constraint
  //* @param value The value of the constraint
  //* @return true on success, false on error
  //**
  mpd_search_add_tag_constraint     : function  (connection: Pmpd_connection; oper: Tmpd_operator; typ: Tmpd_tag_type; const value: PChar): cbool;

  //**
  //* Add a constraint to a search, search for a value in any tag.
  //*
  //* @param connection a #mpd_connection
  //* @param oper reserved, pass #MPD_OPERATOR_DEFAULT
  //* @param value The value of the constraint
  //* @return true on success, false on error
  //**
  mpd_search_add_any_tag_constraint : function  (connection: Pmpd_connection; oper: Tmpd_operator; const value: PChar): cbool;

  //**
  //* Limit the search to files modified after the given time stamp.
  //*
  //* @param connection a #mpd_connection
  //* @param oper reserved, pass #MPD_OPERATOR_DEFAULT
  //* @param value the reference time stamp
  //* @return true on success, false on error
  //**
  mpd_search_add_modified_since_constraint  : function  (connection: Pmpd_connection; oper: Tmpd_operator; value: time_t): cbool;

  //**
  //* Request only a portion of the result set.
  //*
  //* @param connection a #mpd_connection
  //* @param oper reserved, pass #MPD_OPERATOR_DEFAULT
  //* @param type The tag type of the constraint
  //* @param value The value of the constraint
  //* @return true on success, false on error
  //**
  mpd_search_add_window             : function  (connection: Pmpd_connection; start: cunsigned; ending: cunsigned): cbool;

  //**
  //* Starts the real search with constraints added with
  //* mpd_search_add_constraint().
  //*
  //* @param connection the connection to MPD
  //* @return true on success, false on error
  //**
  mpd_search_commit                 : function  (connection: Pmpd_connection): cbool;

  //**
  //* Cancels the search request before you have called
  //* mpd_search_commit().  Call this to clear the current search
  //* request.
  //*
  //* @param connection the connection to MPD
  //**
  mpd_search_cancel                 : procedure (connection: Pmpd_connection);

  //**
  //* Same as mpd_recv_pair_named(), but the pair name is specified as
  //* #mpd_tag_type.
  //*
  //* @param connection the connection to MPD
  //* @param type the tag type you are looking for
  //* @return a pair, or NULL on error or if there are no more matching
  //* pairs in this response
  //**
  mpd_recv_pair_tag                 : function  (connection: Pmpd_connection; typ: Tmpd_tag_type): Pmpd_pair;

