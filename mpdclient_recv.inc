

  //**! \file
  //* \brief MPD client library
  //*
  //* Receiving response lines from MPD.
  //*
  //* Do not include this header directly.  Use mpd/client.h instead.
  //**


var
  //**
  //* Reads the next #mpd_pair from the server.  Returns NULL if there
  //* are no more pairs.
  //*
  //* The caller must dispose the pair with either mpd_return_pair() or
  //* mpd_enqueue_pair().
  //**
  mpd_recv_pair         : function  (connection: Pmpd_connection): Pmpd_pair;

  //**
  //* Same as mpd_recv_pair(), but discards all pairs not matching the
  //* specified name.
  //**
  mpd_recv_pair_named   : function  (connection: Pmpd_connection; const name: PChar): Pmpd_pair;

  //**
  //* Indicates that the pair object is not needed anymore, and can be
  //* freed.  You must free the previous #mpd_pair object before calling
  //* mpd_recv_pair() again.
  //**
  mpd_return_pair       : procedure (connection: Pmpd_connection; pair: Pmpd_pair);

  //**
  //* Unreads a #mpd_pair.  You may unread only the one pair you just got
  //* from mpd_recv_pair().  Unreading the "NULL" pair is allowed, to
  //* allow you to call mpd_recv_pair() again at the end of a response.
  //**
  mpd_enqueue_pair      : procedure (connection: Pmpd_connection; pair: Pmpd_pair);

