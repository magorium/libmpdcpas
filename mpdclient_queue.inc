

  //**! \file
  //* \brief MPD client library
  //*
  //* Manipulate the queue (current playlist).
  //*
  //* Do not include this header directly.  Use mpd/client.h instead.
  //**


var
  //**
  //* Sends the "playlistinfo" command: list all songs in the queue
  //* including meta information.
  //**
  mpd_send_list_queue_meta          : function  (connection: Pmpd_connection): cbool;

  //**
  //* Like mpd_send_list_queue_meta(), but specifies a (position) range.
  //*
  //* @param connection the connection to MPD
  //* @param start the start position of the range (including)
  //* @param end the end position of the range (excluding); the special
  //* value "(unsigned)-1" makes the end of the range open
  //* @return true on success, false on error
  //**
  mpd_send_list_queue_range_meta    : function  (connection: Pmpd_connection; start: cunsigned; endpos: cunsigned): cbool;

  //**
  //*  Requests information (including tags) about one song in the
  //* playlist (command "playlistid").
  //*
  //* @param connection the connection to MPD
  //* @param pos the position of the requested song
  //**
  mpd_send_get_queue_song_pos       : function  (connection: Pmpd_connection; pos: cunsigned): cbool;

  //**
  //* Shortcut for mpd_send_get_queue_song_pos() and mpd_recv_song().
  //*
  //* @param connection the connection to MPD
  //* @param pos the position of the requested song
  //* @return the song at the specified position, or NULL on error
  //**
  mpd_run_get_queue_song_pos        : function  (connection: Pmpd_connection; pos: cunsigned): Pmpd_song;

  //**
  //* Requests information (including tags) about one song in the
  //* playlist (command "playlistid").
  //* 
  //* @param connection the connection to MPD
  //* @param id the id of the requested song
  //**
  mpd_send_get_queue_song_id        : function  (connection: Pmpd_connection; id: cunsigned): cbool;

  //**
  //* Shortcut for mpd_send_get_queue_song_id() and mpd_recv_song().
  //*
  //* @param connection the connection to MPD
  //* @param id the id of the requested song
  //* @return the song at the specified id, or NULL on error
  //**
  mpd_run_get_queue_song_id         : function  (connection: Pmpd_connection; id: cunsigned): Pmpd_song;

  //**
  //* Request the queue changes from MPD since the specified version,
  //* including tags.  The MPD command is called "plchanges".
  //*
  //* @param connection the connection to MPD
  //* @param version The playlist version you want the diff with.
  //* @return true on success, false on error
  //**
  mpd_send_queue_changes_meta       : function  (connection: Pmpd_connection; version: cunsigned) : cbool;

  //**
  //* A more bandwidth efficient version of the
  //* mpd_send_queue_changes_meta().  It only returns the position and id
  //* of changed songs.  The MPD command is called "plchangesposid".
  //*
  //* @param connection A valid and connected mpd_connection.
  //* @param version The playlist version you want the diff with.
  //* @return true on success, false on error
  //**
  mpd_send_queue_changes_brief      : function  (connection: Pmpd_connection; version: cunsigned): cbool;

  //**
  //* Receives a response element of mpd_send_queue_changes_brief().
  //*
  //* @param connection A valid and connected mpd_connection.
  //* @param position_r reference to the position of the changed song
  //* @param id_r reference to the id of the changed song
  //* @return true on success, false on error or if there are no more
  //* changes in this response
  //**
  mpd_recv_queue_change_brief       : function  (connection: Pmpd_connection; position_r: pcunsigned; id_r: pcunsigned): cbool;

  //**
  //* Appends a song to the playlist.
  //**
  mpd_send_add                      : function  (connection: Pmpd_connection; const filename: PChar): cbool;

  //**
  //* Shortcut for mpd_send_add() and mpd_response_finish().
  //*
  //* @param connection the connection to MPD
  //* @param uri the URI of the song to be added
  //* @return true on success, false on error
  //**
  mpd_run_add                       : function  (connection: Pmpd_connection; const uri: PChar): cbool;

  //**
  //* Appends a song to the playlist, and returns its id.
  //**
  mpd_send_add_id                   : function  (connection: Pmpd_connection; const filename: PChar): cbool;

  //**
  //* Inserts a song into the playlist, and returns its id.
  //*
  //* @param connection the connection to MPD
  //* @param uri the URI of the song to be added
  //* @param to the desired position of the song
  //* @return true on success, false on error
  //**
  mpd_send_add_id_to                : function  (connection: Pmpd_connection; const uri: PChar; topos: cunsigned): cbool;

  //**
  //* Returns the id of the new song in the playlist.  To be called after
  //* mpd_send_add_id().
  //*
  //* @return the new song id, -1 on error or if MPD did not send an id
  //**
  mpd_recv_song_id                  : function  (connection: Pmpd_connection): cint;

  //**
  //* Executes the "addid" command and reads the response.
  //*
  //* @return the new song id, -1 on error or if MPD did not send an id
  //**
  mpd_run_add_id                    : function  (connection: Pmpd_connection; const filename: PChar): cint;

  //**
  //* Executes the "addid" command and reads the response.
  //*
  //* @param connection the connection to MPD
  //* @param uri the URI of the song to be added
  //* @param to the desired position of the song
  //* @return the new song id, -1 on error or if MPD did not send an id
  //**
  mpd_run_add_id_to                 : function  (connection: Pmpd_connection; const uri: PChar; topos: cunsigned): cint;

  //**
  //* Deletes a song from the queue.
  //*
  //* @param connection the connection to MPD
  //* @param pos the position of the song to be deleted
  //**
  mpd_send_delete                   : function  (connection: Pmpd_connection; pos: cunsigned): cbool;

  //**
  //* Shortcut for mpd_send_delete() and mpd_response_finish().
  //*
  //* @param connection the connection to MPD
  //* @param pos the position of the song to be deleted
  //* @return true on success, false on error
  //**
  mpd_run_delete                    : function  (connection: Pmpd_connection; pos: cunsigned): cbool;

  //**
  //* Deletes songs from the queue.
  //*
  //* @param connection the connection to MPD
  //* @param start the start position of the range (including)
  //* @param end the end position of the range (excluding); the special
  //* value "(unsigned)-1" makes the end of the range open
  //* @return true on success, false on error
  //**
  mpd_send_delete_range             : function  (connection: Pmpd_connection; start: cunsigned; endpos: cunsigned): cbool;

  //**
  //* Shortcut for mpd_send_delete_range() and mpd_response_finish().
  //*
  //* @param connection the connection to MPD
  //* @param start the start position of the range (including)
  //* @param end the end position of the range (excluding); the special
  //* value "(unsigned)-1" makes the end of the range open
  //* @return true on success, false on error
  //**
  mpd_run_delete_range              : function  (connection: Pmpd_connection; start: cunsigned; endpos: cunsigned): cbool;

  //**
  //* Deletes a song from the queue.
  //*
  //* @param connection the connection to MPD
  //* @param id the id of the song to be deleted
  //**
  mpd_send_delete_id                : function  (connection: Pmpd_connection; id: cunsigned): cbool;

  //**
  //* Shortcut for mpd_send_delete_id() and mpd_response_finish().
  //*
  //* @param connection the connection to MPD
  //* @param id the id of the song to be deleted
  //* @return true on success, false on error
  //**
  mpd_run_delete_id                 : function  (connection: Pmpd_connection; id: cunsigned): cbool;

  //**
  //* Shuffles the queue.
  //*
  //* @param connection the connection to MPD
  //**
  mpd_send_shuffle                  : function  (connection: Pmpd_connection): cbool;

  //**
  //* Shortcut for mpd_send_shuffle() and mpd_response_finish().
  //*
  //* @param connection the connection to MPD
  //**
  mpd_run_shuffle                   : function  (connection: Pmpd_connection): cbool;

  //**
  //* Shuffles a range within the queue.
  //*
  //* @param connection the connection to MPD
  //* @param start the start position of the range (including)
  //* @param end the end position of the range (excluding); the special
  //* value "(unsigned)-1" makes the end of the range open
  //**
  mpd_send_shuffle_range            : function  (connection: Pmpd_connection; start: cunsigned; endpos: cunsigned): cbool;

  //**
  //* Shortcut for mpd_send_shuffle_range() and mpd_response_finish().
  //*
  //* @param connection the connection to MPD
  //* @param start the start position of the range (including)
  //* @param end the end position of the range (excluding); the special
  //* value "(unsigned)-1" makes the end of the range open
  //**
  mpd_run_shuffle_range             : function  (connection: Pmpd_connection; start: cunsigned; endpos: cunsigned): cbool;

  //**
  //* Clear the queue.
  //*
  //* @param connection the connection to MPD
  //**
  mpd_send_clear                    : function  (connection: Pmpd_connection): cbool;

  //**
  //* Shortcut for mpd_send_clear() and mpd_response_finish().
  //*
  //* @param connection the connection to MPD
  //**
  mpd_run_clear                     : function  (connection: Pmpd_connection): cbool;

  //**
  //* Moves a song within the queue.
  //*
  //* @param connection the connection to MPD
  //* @param from the source song position
  //* @param to the new position of the song
  //**
  mpd_send_move                     : function  (connection: Pmpd_connection; from: cunsigned; topos: cunsigned): cbool;

  //**
  //* Shortcut for mpd_send_move() and mpd_response_finish().
  //*
  //* @param connection the connection to MPD
  //* @param from the source song position
  //* @param to the new position of the song
  //**
  mpd_run_move                      : function  (connection: Pmpd_connection; from: cunsigned; topos: cunsigned): cbool;

  //**
  //* Moves a song within the queue.
  //*
  //* @param connection the connection to MPD
  //* @param from the source song id
  //* @param to the new position of the song (not an id!)
  //**
  mpd_send_move_id                  : function  (connection: Pmpd_connection; from: cunsigned; topos: cunsigned): cbool;

  //**
  //* Shortcut for mpd_send_move_id() and mpd_response_finish().
  //*
  //* @param connection the connection to MPD
  //* @param from the source song id
  //* @param to the new position of the song (not an id!)
  //**
  mpd_run_move_id                   : function  (connection: Pmpd_connection; from: cunsigned; topos: cunsigned): cbool;

  //**
  //* Moves a range of songs within the queue.
  //*
  //* @param connection the connection to MPD
  //* @param start the start position of the range (including)
  //* @param end the end position of the range (excluding); the special
  //* value "(unsigned)-1" makes the end of the range open
  //* @param to the new position of the song range
  //* @return true on success, false on error
  //**
  mpd_send_move_range               : function  (connection: Pmpd_connection; start: cunsigned; endpos: cunsigned; topos: cunsigned): cbool;

  //**
  //* Shortcut for mpd_send_move_id() and mpd_response_finish().
  //*
  //* @param connection the connection to MPD
  //* @param start the start position of the range (including)
  //* @param end the end position of the range (excluding); the special
  //* value "(unsigned)-1" makes the end of the range open
  //* @param to the new position of the song range
  //* @return true on success, false on error
  //**
  mpd_run_move_range                : function  (connection: Pmpd_connection; start: cunsigned; endpos: cunsigned; topos: cunsigned): cbool;

  //**
  //* Swap the position of two songs in the queue.
  //*
  //* @param connection the connection to MPD
  //* @param pos1 the position of one song
  //* @param pos2 the position of the other song
  //**
  mpd_send_swap                     : function  (connection: Pmpd_connection; pos1: cunsigned; pos2: cunsigned): cbool;

  //**
  //* Shortcut for mpd_send_swap() and mpd_response_finish().
  //*
  //* @param connection the connection to MPD
  //* @param pos1 the position of one song
  //* @param pos2 the position of the other song
  //**
  mpd_run_swap                      : function  (connection: Pmpd_connection; pos1: cunsigned; pos2: cunsigned): cbool;

  //**
  //* Swap the position of two songs in the queue.
  //*
  //* @param connection the connection to MPD
  //* @param id1 the id of one song
  //* @param id2 the id of the other song
  //**
  mpd_send_swap_id                  : function  (connection: Pmpd_connection; id1: cunsigned; id2: cunsigned): cbool;

  //**
  //* Shortcut for mpd_send_swap_id() and mpd_response_finish().
  //*
  //* @param connection the connection to MPD
  //* @param id1 the id of one song
  //* @param id2 the id of the other song
  //**
  mpd_run_swap_id                   : function  (connection: Pmpd_connection; id1: cunsigned; id2: cunsigned): cbool;

  //**
  //* Change the priority of the specified song.
  //*
  //* @param connection the connection to MPD
  //* @param priority a number between 0 and 255
  //* @param position the position of the song
  //**
  mpd_send_prio                     : function  (connection: Pmpd_connection; priority: cint; position: cunsigned): cbool;

  //**
  //* Shortcut for mpd_send_prio() and mpd_response_finish().
  //*
  //* @param connection the connection to MPD
  //* @param priority a number between 0 and 255
  //* @param position the position of the song
  //**
  mpd_run_prio                      : function  (connection: Pmpd_connection; priority: cint; position: cunsigned): cbool;

  //**
  //* Change the priority of a song range.
  //*
  //* @param connection the connection to MPD
  //* @param priority a number between 0 and 255
  //* @param start the start position of the range (including)
  //* @param end the end position of the range (excluding); the special
  //* value "(unsigned)-1" makes the end of the range open
  //**
  mpd_send_prio_range               : function  (connection: Pmpd_connection; priority: cint; startpos: cunsigned; endpos: cunsigned): cbool;

  //**
  //* Shortcut for mpd_send_prio_range() and mpd_response_finish().
  //*
  //* @param connection the connection to MPD
  //* @param priority a number between 0 and 255
  //* @param start the start position of the range (including)
  //* @param end the end position of the range (excluding); the special
  //* value "(unsigned)-1" makes the end of the range open
  //**
  mpd_run_prio_range                : function  (connection: Pmpd_connection; priority: cint; startpos: cunsigned; endpos: cunsigned): cbool;

  //**
  //* Change the priority of the specified song.
  //*
  //* @param connection the connection to MPD
  //* @param priority a number between 0 and 255
  //* @param id the id of the song
  //**
  mpd_send_prio_id                  : function  (connection: Pmpd_connection; priority: cint; id: cunsigned): cbool;

  //**
  //* Shortcut for mpd_send_prio_id() and mpd_response_finish().
  //*
  //* @param connection the connection to MPD
  //* @param priority a number between 0 and 255
  //* @param id the id of the song
  //**
  mpd_run_prio_id                   : function  (connection: Pmpd_connection; priority: cint; id: cunsigned): cbool;

