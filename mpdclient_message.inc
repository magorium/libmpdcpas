

  //**! \file
  //* \brief MPD client library
  //*
  //* Do not include this header directly.  Use mpd/client.h instead.
  //**


type
  //**
  //* \struct mpd_message
  //**
  Tmpd_message = record end;
  Pmpd_message = ^Tmpd_message;


var
  //**
  //* Begins parsing a new message.
  //*
  //* @param pair the first pair in this message (name must be "channel")
  //* @return the new #mpd_entity object, or NULL on error (out of
  //* memory, or pair name is not "channel")
  //**
  mpd_message_begin         : function  (const pair: Pmpd_pair): Pmpd_message;

  //**
  //* Parses the pair, adding its information to the specified
  //* #mpd_message object.
  //*
  //* @return true if the pair was parsed and added to the message (or if
  //* the pair was not understood and ignored), false if this pair is the
  //* beginning of the next message
  //**
  mpd_message_feed          : function  (output: Pmpd_message; const pair: Pmpd_pair): cbool;

  //**
  //* Frees a #mpd_message object.
  //**
  mpd_message_free          : procedure (msg: Pmpd_message);

  //**
  //* Returns the channel name.
  //**
  mpd_message_get_channel   : function  (const msg: Pmpd_message): PChar;

  //**
  //* Returns the message text.
  //**
  mpd_message_get_text      : function  (const msg: Pmpd_message): PChar;

  //**
  //* Sends the "subscribe" command: subscribe to a message channel.
  //*
  //* @param connection the connection to MPD
  //* @param channel the channel name
  //* @return true on success
  //**
  mpd_send_subscribe        : function  (connection: Pmpd_connection; const channel: PChar): cbool;

  //**
  //* Shortcut for mpd_send_subscribe() and mpd_response_finish().
  //*
  //* @param connection the connection to MPD
  //* @param channel the channel name
  //* @return true on success
  //**
  mpd_run_subscribe         : function  (connection: Pmpd_connection; const channel: PChar): cbool;

  //**
  //* Sends the "unsubscribe" command: unsubscribe from a message
  //* channel.
  //*
  //* @param connection the connection to MPD
  //* @param channel the channel name
  //* @return true on success
  //**
  mpd_send_unsubscribe      : function  (connection: Pmpd_connection; const channel: PChar): cbool;

  //**
  //* Shortcut for mpd_send_unsubscribe() and mpd_response_finish().
  //*
  //* @param connection the connection to MPD
  //* @param channel the channel name
  //* @return true on success
  //**
  mpd_run_unsubscribe       : function  (connection: Pmpd_connection; const channel: PChar): cbool;

  //**
  //* Sends the "sendmessage" command: send a message to a channel.
  //*
  //* @param connection the connection to MPD
  //* @param channel the channel name
  //* @param text the message text
  //* @return true on success
  //**
  mpd_send_send_message     : function  (connection: Pmpd_connection; const channel: PChar; const txt: PChar): cbool;

  //**
  //* Shortcut for mpd_send_send_message() and mpd_response_finish().
  //*
  //* @param connection the connection to MPD
  //* @param channel the channel name
  //* @param text the message text
  //* @return true on success
  //**
  mpd_run_send_message      : function  (connection: Pmpd_connection; const channel: PChar; const txt: PChar): cbool;

  //**
  //* Sends the "readmessages" command: send a message to a channel.
  //*
  //* @param connection the connection to MPD
  //* @return true on success
  //**
  mpd_send_read_messages    : function  (connection: Pmpd_connection): cbool;

  //**
  //* Reads the next mpd_message from the MPD response.  Free the return
  //* value with mpd_message_free().
  //*
  //* @return a mpd_message object on success, NULL on error or
  //* end-of-response
  //**
  mpd_recv_message          : function  (connection: Pmpd_connection): Pmpd_message;

  //**
  //* Sends the "channels" command: get a list of all channels.
  //*
  //* @param connection the connection to MPD
  //* @return true on success
  //**
  mpd_send_channels         : function  (connection: Pmpd_connection): cbool;

  //**
  //* Receives the next channel name.  Call this in a loop after
  //* mpd_send_channels().
  //*
  //* Free the return value with mpd_return_pair().
  //*
  //* @param connection a #mpd_connection
  //* @returns a "channel" pair, or NULL on error or if the end of the
  //* response is reached
  //**
  function  mpd_recv_channel_pair(connection: Pmpd_connection): Pmpd_pair; inline;

