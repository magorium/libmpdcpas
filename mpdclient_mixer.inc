

  //**! \file
  //* \brief MPD client library
  //*
  //* Functions for manipulating MPD's mixer controls.
  //*
  //* Do not include this header directly.  Use mpd/client.h instead.
  //**


var
  //**
  //* Sets the volume of all output devices.
  //*
  //* @param connection the connection to MPD
  //* @param volume the volume, an integer between 0 and 100
  //* @return true on success, false on error
  //**
  mpd_send_set_volume       : function  (connection: Pmpd_connection; volume: cunsigned): cbool;

  //**
  //* Shortcut for mpd_send_set_volume() and mpd_response_finish().
  //*
  //* @param connection the connection to MPD
  //* @param volume the volume, an integer between 0 and 100
  //* @return true on success, false on error
  //**
  mpd_run_set_volume        : function  (connection: Pmpd_connection; volume: cunsigned): cbool;

  //**
  //* Changes the volume of all output devices.
  //*
  //* @param connection the connection to MPD
  //* @param relative_volume the relative volume, an integer between -100 and 100
  //* @return true on success, false on error
  //**
  mpd_send_change_volume    : function  (connection: Pmpd_connection; relative_volume: cint): cbool;

  //**
  //* Shortcut for mpd_send_change_volume() and mpd_response_finish().
  //*
  //* @param connection the connection to MPD
  //* @param relative_volume the relative volume, an integer between -100 and 100
  //* @return true on success, false on error
  //**
  mpd_run_change_volume     : function  (connection: Pmpd_connection; relative_volume: cint): cbool;

