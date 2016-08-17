

  //** \file
  //* \brief MPD client library
  //*
  //* Password authentication.
  //*
  //* Do not include this header directly.  Use mpd/client.h instead.
  //**


var
  //**
  //* Sends the password to MPD, to gain more privileges.
  //**
  mpd_send_password     : function  (connection: Pmpd_connection; const password: PChar): cbool;

  //**
  //* Sends the password to MPD and receives its response.
  //*
  //* @return true on success, false on failure
  //**
  mpd_run_password      : function  (connection: Pmpd_connection; const password : PChar): cbool;

