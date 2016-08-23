

  //**! \file
  //* \brief MPD client library
  //*
  //* Do not include this header directly.  Use mpd/client.h instead.
  //**


var
  //**
  //* Finishes the response and checks if the command was successful.  If
  //* there are data pairs left, they are discarded.
  //*
  //* @return true on success, false on error
  //**
  mpd_response_finish   : function  (connection: Pmpd_connection): cbool;

  //**
  //* Finishes the response of the current list command.  If there are
  //* data pairs left, they are discarded.
  //*
  //* @return true on success, false on error
  //**
  mpd_response_next     : function  (connection: Pmpd_connection): cbool;

