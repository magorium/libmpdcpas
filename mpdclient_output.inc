

  //**! \file
  //* \brief MPD client library
  //*
  //* Do not include this header directly.  Use mpd/client.h instead.
  //**


type
  //**
  //* \struct mpd_output
  //*
  //* This type represents an audio output device on the MPD server.
  //**
  Tmpd_output = record end;
  Pmpd_output = ^Tmpd_output;


var
  //**
  //* Begins parsing a new #mpd_output.
  //*
  //* @param pair the first pair in this output (name is "outputid")
  //* @return the new #mpd_output object, or NULL on error (out of
  //* memory, or wrong pair name)
  //**
  mpd_output_begin          : function  (const pair: Pmpd_pair): Pmpd_output;

  //**
  //* Parses the pair, adding its information to the specified
  //* #mpd_output object.
  //*
  //* @return true if the pair was parsed and added to the output (or if
  //* the pair was not understood and ignored), false if this pair is the
  //* beginning of the next output
  //**
  mpd_output_feed           : function  (output : Pmpd_output; const pair: Pmpd_pair): cbool;

  //**
  //* Frees a mpd_output object returned from mpd_recv_output().
  //**
  mpd_output_free           : procedure (output: Pmpd_output);

  //**
  //* @return the id of the specified #mpd_output object
  //**
  mpd_output_get_id         : function  (const output: Pmpd_output): cunsigned;

  //**
  //* @return the configured name of the specified #mpd_output object
  //**
  mpd_output_get_name       : function  (const output: Pmpd_output): PChar;

  //**
  //* @return true if this output is enabled
  //**
  mpd_output_get_enabled    : function  (const output: Pmpd_output): cbool;

  //**
  //* Sends the "outputs" command to MPD.  Call mpd_recv_output() to
  //* read the response.
  //*
  //* @param connection A valid and connected mpd_connection.
  //* @return true on success
  //**
  mpd_send_outputs          : function  (connection: Pmpd_connection): cbool;

  //**
  //* Reads the next mpd_output from the MPD response.  Free the return
  //* value with mpd_output_free().
  //*
  //* @return a mpd_output object on success, NULL on error or
  //* end-of-response
  //**
  mpd_recv_output           : function  (connection: Pmpd_connection): Pmpd_output;

  //**
  //* Sends the "enableoutput" command to MPD.
  //*
  //* @param connection A valid and connected mpd_connection.
  //* @param output_id an identifier for the output device (see
  //* mpd_recv_output())
  //* @return true on success
  //**
  mpd_send_enable_output    : function  (connection: Pmpd_connection; output_id: cunsigned): cbool;

  //**
  //* Shortcut for mpd_send_enable_output() and mpd_response_finish().
  //*
  //* @param connection A valid and connected mpd_connection.
  //* @param output_id an identifier for the output device (see
  //* mpd_recv_output())
  //* @return true on success
  //**
  mpd_run_enable_output     : function  (connection: Pmpd_connection; output_id: cunsigned): cbool;

  //**
  //* Sends the "disableoutput" command to MPD.
  //*
  //* @param connection A valid and connected mpd_connection.
  //* @param output_id an identifier for the output device (see
  //* mpd_recv_output())
  //* @return true on success
  //**
  mpd_send_disable_output   : function  (connection: Pmpd_connection; output_id: cunsigned): cbool;

  //**
  //* Shortcut for mpd_send_disable_output() and mpd_response_finish().
  //*
  //* @param connection A valid and connected mpd_connection.
  //* @param output_id an identifier for the output device (see
  //* mpd_recv_output())
  //* @return true on success
  //**
  mpd_run_disable_output    : function  (connection: Pmpd_connection; output_id: cunsigned): cbool;

  //**
  //* Sends the "toggleoutput" command to MPD.
  //*
  //* @param connection a valid and connected mpd_connection.
  //* @param output_id an identifier for the output device (see
  //* mpd_recv_output())
  //* @return true on success
  //**
  mpd_send_toggle_output    : function  (connection: Pmpd_connection; output_id: cunsigned): cbool;

  //**
  //* Shortcut for mpd_send_toggle_output() and mpd_response_finish().
  //*
  //* @param connection a valid and connected mpd_connection.
  //* @param output_id an identifier for the output device (see
  //* mpd_recv_output())
  //* @return true on success
  //**
  mpd_run_toggle_output     : function  (connection: Pmpd_connection; output_id: cunsigned): cbool;

