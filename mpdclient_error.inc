

  //**! \file
  //* \brief MPD client library
  //*
  //* Do not include this header directly.  Use mpd/client.h or
  //* mpd/async.h instead.
  //**


type
  Tmpd_error =
  (
    //** no error */
    NMPD_ERROR_SUCCESS = 0,

    //** out of memory */
    NMPD_ERROR_OOM,

    //** a function was called with an unrecognized or invalid argument */
    NMPD_ERROR_ARGUMENT,

    //** a function was called which is not available in the current state of libmpdclient */
    NMPD_ERROR_STATE,

    //** timeout trying to talk to mpd */
    NMPD_ERROR_TIMEOUT,

    //** system error */
    NMPD_ERROR_SYSTEM,

    //** unknown host */
    NMPD_ERROR_RESOLVER,

    //** malformed response received from MPD */
    NMPD_ERROR_MALFORMED,

    //** connection closed by mpd */
    NMPD_ERROR_CLOSED,

    //**
    //* The server has returned an error code, which can be queried
    //* with mpd_connection_get_server_error().
    //**
    NMPD_ERROR_SERVER
  );

