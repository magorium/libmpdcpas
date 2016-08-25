

  //**! \file
  //* \brief MPD client library
  //*
  //* Do not include this header directly.  Use mpd/client.h instead.
  //**


var
  //**
  //* Sends a command with arguments to the MPD server.  The argument
  //* list must be terminated with a NULL.
  //*
  //* @param connection the connection to the MPD server
  //* @param command the command to be sent
  //* @return true on success
  //**
  mpd_send_command  : function  (connection: Pmpd_connection; const command: PChar; const args: array of PChar): cbool;

