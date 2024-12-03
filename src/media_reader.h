/*
    File: media_reader.h
    Date created: August 2024
    Author: mathbitQ
    Description: Reads media file from the given file to
                 get properties from the media file, such as
                 bit rate, frame rate and duration.
                 Also supports formatting duration in format
                 hh:mm:ss where hh represents hours, mm represents
                 minutes and ss represents seconds.
                 Required FFmpeg library to support reading
                 format, and wxWidgets to support wxString.
    Version: 1.0
*/

#ifndef MEDIA_READER_H_INCLUDED
#define MEDIA_READER_H_INCLUDED

#include <wx/wx.h>
extern "C"
{
    #include "libavcodec/avcodec.h"
    #include "libavformat/avformat.h"
}

// Allows the avcodec and avformat from ffmpeg library to read metadata from media file
int64_t getMediaDuration(const wxString *filename);

// Allows to convert timer (as seconds) to format of hh:mm:ss
wxString getMediaTimerFormat(const int64_t timer);

#endif // MEDIA_READER_H_INCLUDED
