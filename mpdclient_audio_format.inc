

  //**! \file
  //* \brief MPD client library
  //*
  //* Do not include this header directly.  Use mpd/client.h instead.
  //**


const
  {$IFDEF FPC}  // FPC: unnamed enum converted to plain constants
  //**
  //* 32 bit floating point samples.
  //**
  NMPD_SAMPLE_FORMAT_FLOAT = $e0;

  //**
  //* DSD samples.
  //**
  NMPD_SAMPLE_FORMAT_DSD = $e1;
  {$ENDIF}


type
  //**
  //* This structure describes the format of a raw PCM stream.
  //**
  Tmpd_audio_format = 
  record
    //**
    //* The sample rate in Hz.  A better name for this attribute is
    //* "frame rate", because technically, you have two samples per
    //* frame in stereo sound.
    //**
    sample_rate : cuint32;

    //**
    //* The number of significant bits per sample.  Samples are
    //* currently always signed.  Supported values are 8, 16, 24,
    //* 32 and the special values #MPD_SAMPLE_FORMAT_FLOAT,
    //* #MPD_SAMPLE_FORMAT_DSD.
    //**
    bits        : cuint8;

    //**
    //* The number of channels.  Only mono (1) and stereo (2) are
    //* fully supported currently.
    //**
    channels    : cuint8;

    //* reserved for future use
    reserved0   : cuint16;

    //* reserved for future use
    reserved1   : cuint32;
  end;
  Pmpd_audio_format = ^Tmpd_audio_format;

