

  //**! \file
  //* \brief MPD client library
  //*
  //* Do not include this header directly.  Use mpd/client.h instead.
  //**


var
  //**
  //* Requests a list of supported and allowed.  Use
  //* mpd_recv_pair_named() to obtain the list of "command" pairs.
  //*
  //* @param connection the connection to MPD
  //* @return true on success, false on error
  //**
  mpd_send_allowed_commands     : function  (connection: Pmpd_connection): cbool;

  //**
  //* Requests a list of supported commands which are not allowed for
  //* this connection.  Use mpd_recv_pair_named() to obtain the list of
  //* "command" pairs.
  //*
  //* @param connection the connection to MPD
  //* @return true on success, false on error
  //**
  mpd_send_disallowed_commands  : function  (connection: Pmpd_connection): cbool;

  //**
  //* Receives the next supported command.  Call this in a loop after
  //* mpd_send_commands() or mpd_send_notcommands().
  //*
  //* Free the return value with mpd_return_pair().
  //*
  //* @param connection a #mpd_connection
  //* @returns a "command" pair, or NULL on error or if the end of the
  //* response is reached
  //**
  function  mpd_recv_command_pair(connection: Pmpd_connection): Pmpd_pair; inline;


var
  //**
  //* Requests a list of supported URL handlers in the form "scheme://",
  //* example: "http://".  Use mpd_recv_pair_named() to obtain the list
  //* of "handler" pairs.
  //*
  //* @param connection the connection to MPD
  //* @return true on success, false on error
  //**
  mpd_send_list_url_schemes     : function  (connection: Pmpd_connection): cbool;

  //**
  //* Receives one line of the mpd_send_urlhandlers() response.
  //*
  //* Free the return value with mpd_return_pair().
  //*
  //* @param connection a #mpd_connection
  //* @returns a "handler" pair, or NULL on error or if the end of the
  //* response is reached
  //**
  function  mpd_recv_url_scheme_pair(connection: Pmpd_connection): Pmpd_pair; inline;


var
  //**
  //* Requests a list of supported tag types.  Use mpd_recv_pair_named()
  //* to obtain the list of "tagtype" pairs.
  //*
  //* @param connection the connection to MPD
  //* @return true on success, false on error
  //**
  mpd_send_list_tag_types       : function  (connection: Pmpd_connection): cbool;

  //**
  //* Receives the next tag type name.  Call this in a loop after
  //* mpd_send_tagtypes().
  //*
  //* Free the return value with mpd_return_pair().
  //*
  //* @param connection a #mpd_connection
  //* @returns a "tagtype" pair, or NULL on error or if the end of the
  //* response is reached
  //**
  function  mpd_recv_tag_type_pair(connection: Pmpd_connection): Pmpd_pair; inline;

