

  //**! \file
  //* \brief MPD client library
  //*
  //* Functions for sending command lists.
  //*
  //* Do not include this header directly.  Use mpd/client.h instead.
  //**


var
  //**
  //* Starts a command list, i.e. a group of pipelined commands which are
  //* transferred in one block.  If one command fails, the rest of the
  //* command list is canceled.
  //*
  //* Note that there is no guarantee on atomicity.
  //*
  //* @param connection the connection to MPD
  //* @param discrete_ok tells MPD whether to acknowledge every list
  //* command with an "list_OK" response
  //* @return true on success
  //**
  mpd_command_list_begin    : function  (connection: Pmpd_connection; discrete_ok: cbool): cbool;
 
  //**
  //* Commits the command list, i.e. makes MPD execute all commands which
  //* were queued.
  //*
  //* Note: there is no way to cancel a command list once it is started.
  //* You may however close the socket connection.
  //*
  //* @param connection the connection to MPD
  //* @return true on success
  //**
  mpd_command_list_end      : function  (connection: Pmpd_connection): cbool;

