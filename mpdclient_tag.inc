

type
  Tmpd_tag_type =
  (
    //**
    //* Special value returned by mpd_tag_name_parse() when an
    //* unknown name was passed.
    //**
    NMPD_TAG_UNKNOWN = -1,

    NMPD_TAG_ARTIST,
    NMPD_TAG_ALBUM,
    NMPD_TAG_ALBUM_ARTIST,
    NMPD_TAG_TITLE,
    NMPD_TAG_TRACK,
    NMPD_TAG_NAME,
    NMPD_TAG_GENRE,
    NMPD_TAG_DATE,
    NMPD_TAG_COMPOSER,
    NMPD_TAG_PERFORMER,
    NMPD_TAG_COMMENT,
    NMPD_TAG_DISC,

    NMPD_TAG_MUSICBRAINZ_ARTISTID,
    NMPD_TAG_MUSICBRAINZ_ALBUMID,
    NMPD_TAG_MUSICBRAINZ_ALBUMARTISTID,
    NMPD_TAG_MUSICBRAINZ_TRACKID,
    NMPD_TAG_MUSICBRAINZ_RELEASETRACKID,

    NMPD_TAG_COUNT
  );


var
  //**
  //* Looks up the name of the specified tag.
  //*
  //* @return the name, or NULL if the tag type is not valid
  //**
  mpd_tag_name          : function  (typ: Tmpd_tag_type): PChar;

  //**
  //* Parses a tag name, and returns its #mpd_tag_type value.
  //*
  //* @return a #mpd_tag_type value, or MPD_TAG_UNKNOWN if the name was
  //* not recognized
  //**
  mpd_tag_name_parse    : function  (const name: PChar): Tmpd_tag_type;

  //**
  //* Same as mpd_tag_name_parse(), but ignores case.
  //*
  //* @return a #mpd_tag_type value, or MPD_TAG_UNKNOWN if the name was
  //* not recognized
  //**
  mpd_tag_name_iparse   : function  (const name: PChar): Tmpd_tag_type;

