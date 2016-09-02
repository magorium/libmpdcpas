unit mpdclient;

{$MODE OBJFPC}{$H+}

interface

uses
  ctypes, pvt.chelpers;


const
  LIBMPDCLIENT_FULLVERSION = 021000;


  {$INCLUDE mpdclient_version.inc}
  {$INCLUDE mpdclient_error.inc}
  {$INCLUDE mpdclient_settings.inc}
  {$INCLUDE mpdclient_protocol.inc}
  {$INCLUDE mpdclient_async.inc}
  {$INCLUDE mpdclient_connection.inc}
  {$INCLUDE mpdclient_audio_format.inc}
  {$INCLUDE mpdclient_pair.inc}
  {$INCLUDE mpdclient_capabilities.inc}
  {$INCLUDE mpdclient_database.inc}
  {$INCLUDE mpdclient_directory.inc}
  {$INCLUDE mpdclient_tag.inc}
  {$INCLUDE mpdclient_song.inc}
  {$INCLUDE mpdclient_playlist.inc}
  {$INCLUDE mpdclient_entity.inc}
  {$INCLUDE mpdclient_idle.inc}
  {$INCLUDE mpdclient_list.inc}
  {$INCLUDE mpdclient_message.inc}
  {$INCLUDE mpdclient_mixer.inc}
  {$INCLUDE mpdclient_output.inc}
  {$INCLUDE mpdclient_parser.inc}
  {$INCLUDE mpdclient_password.inc}
  {$INCLUDE mpdclient_player.inc}
  {$INCLUDE mpdclient_queue.inc}
  {$INCLUDE mpdclient_recv.inc}
  {$INCLUDE mpdclient_response.inc}
  {$INCLUDE mpdclient_search.inc}
  {$INCLUDE mpdclient_send.inc}
  {$INCLUDE mpdclient_stats.inc}
  {$INCLUDE mpdclient_status.inc}
  {$INCLUDE mpdclient_sticker.inc}
  {$INCLUDE mpdclient_compiler.inc}


implementation


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
begin
  result := 
  (
    (major < LIBMPDCLIENT_MAJOR_VERSION) or
    (
      (major = LIBMPDCLIENT_MAJOR_VERSION) and
      (
        (minor < LIBMPDCLIENT_MINOR_VERSION) or
        (
          (minor = LIBMPDCLIENT_MINOR_VERSION) and
          (patch <= LIBMPDCLIENT_PATCH_VERSION)
        )
      )
    )
  );
end;


function  mpd_recv_command_pair(connection: Pmpd_connection): Pmpd_pair; inline;
begin
  result := mpd_recv_pair_named(connection, 'command');
end;


function  mpd_recv_url_scheme_pair(connection: Pmpd_connection): Pmpd_pair; inline;
begin
  result := mpd_recv_pair_named(connection, 'handler');
end;


function  mpd_recv_tag_type_pair(connection: Pmpd_connection): Pmpd_pair; inline;
begin
  result := mpd_recv_pair_named(connection, 'tagtype');
end;


function  mpd_recv_channel_pair(connection: Pmpd_connection): Pmpd_pair; inline;
begin
  result := mpd_recv_pair_named(connection, 'channel');
end;


initialization


end.
