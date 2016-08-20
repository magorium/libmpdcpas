

  //**! \file
  //* \brief MPD client library
  //*
  //* Do not include this header directly.  Use mpd/client.h or
  //* mpd/parser.h instead.
  //**


type
  Tmpd_server_error =
  (
    NMPD_SERVER_ERROR_UNK            = -1,

    NMPD_SERVER_ERROR_NOT_LIST       = 1,
    NMPD_SERVER_ERROR_ARG            = 2,
    NMPD_SERVER_ERROR_PASSWORD       = 3,
    NMPD_SERVER_ERROR_PERMISSION     = 4,
    NMPD_SERVER_ERROR_UNKNOWN_CMD    = 5,

    NMPD_SERVER_ERROR_NO_EXIST       = 50,
    NMPD_SERVER_ERROR_PLAYLIST_MAX   = 51,
    NMPD_SERVER_ERROR_SYSTEM         = 52,
    NMPD_SERVER_ERROR_PLAYLIST_LOAD  = 53,
    NMPD_SERVER_ERROR_UPDATE_ALREADY = 54,
    NMPD_SERVER_ERROR_PLAYER_SYNC    = 55,
    NPD_SERVER_ERROR_EXIST           = 56
  );

