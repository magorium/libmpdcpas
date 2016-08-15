

  //**! \file
  //* \brief MPD client library
  //*
  //* Do not include this header directly.  Use mpd/client.h instead.
  //**


type
  //**
  //* A name-value pair received from the MPD server.
  //**
  Tmpd_pair = 
  record
    //* the name of the element */
    name    : PChar;

    //* the value of the element */
    value   : PChar;
  end;
  Pmpd_pair = ^Tmpd_pair;

