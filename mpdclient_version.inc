

  //**! \file
  //* \brief MPD client library
  //*
  //* Do not include this header directly.  Use mpd/client.h instead.
  //**


const
  LIBMPDCLIENT_MAJOR_VERSION =  2;
  LIBMPDCLIENT_MINOR_VERSION = 10;
  LIBMPDCLIENT_PATCH_VERSION =  0;

  //**
  //* Runtime function which allows you to check which version of
  //* libmpdclient you are compiling with.  It can be used in
  //* preprocessor directives.
  //*
  //* @return true if this libmpdclient version equals or is newer than
  //* the specified version number
  //* @since libmpdclient 2.1
  //**
  function  LIBMPDCLIENT_CHECK_VERSION(major, minor, patch: cunsigned): cbool;

