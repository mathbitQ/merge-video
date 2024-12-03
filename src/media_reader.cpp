/*
    File: media_reader.cpp
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

#include "media_reader.h"
#include <codecvt>
#include <iostream>
#include <string>
#include <locale.h>
#include <wchar.h>
#include <stdlib.h>

// Allows the avcodec and avformat from FFmpeg library to read metadata from media file
int64_t getMediaDuration(const wxString *filename)
{

    // Creates context of AVFormatContext from FFmpeg
    AVFormatContext *formatContext = avformat_alloc_context();
    if(!formatContext)
    {
        return -1;
    }

    // Converts filename as wxString to std::string with UTF8 format and Char Buffer from wxString
    std::string utf8filename = filename->ToUTF8().data();

    // Return -1 if file can't be opened
    if(avformat_open_input(&formatContext, utf8filename.c_str(), nullptr, nullptr))
    {
        std::cerr<<"Could not open file: "<<filename<<"\n";
        avformat_free_context(formatContext);
        return -1;
    }

    // Return -1 if media info can't be retrieved
    if(avformat_find_stream_info(formatContext, nullptr) < 0)
    {
        std::cerr << "Could not retrieve stream info from file: " << filename << "\n";
        avformat_close_input(&formatContext);
        avformat_free_context(formatContext);
        return -1;
    }

    // Assigns duration from the file and return
    // Duration will be formatted as seconds
    int64_t duration = (formatContext->duration / AV_TIME_BASE);

    // Closes all the input (file reader and context) to free memory
    avformat_close_input(&formatContext);
    avformat_free_context(formatContext);

    return duration;
}

// Converts duration as seconds to hh:mm:ss format as string
wxString getMediaTimerFormat(const int64_t timer)
{
    if(timer <= 0)
        return "00:00:00";

    wxString format = "";
    int64_t temp_second = timer;
    int64_t hour;
    int64_t minute;
    int64_t second;


    // Hours section
    hour = temp_second / 3600;
    temp_second %= 3600;
    // Minutes section
    minute = temp_second / 60;
    temp_second %= 60;
    // Seconds section
    second = temp_second;

    // Hours format, same goes to minutes and seconds
    // If unit format is between 0 - 9, appends 0 in front
    // of the unit format and the duration afterward
    // Otherwise, only appends the duration calculated
    // above
    if(hour >= 10)
    {
        format.Append(std::to_string(hour));
    }
    else
    {
        format.Append("0");
        format.Append(std::to_string(hour));
    }
    format.Append(":");
    if(minute >= 10)
    {
        format.Append(std::to_string(minute));
    }
    else
    {
        format.Append("0");
        format.Append(std::to_string(minute));
    }
    format.Append(":");
    if(second >= 10)
    {
        format.Append(std::to_string(second));
    }
    else
    {
        format.Append("0");
        format.Append(std::to_string(second));
    }
    return format;
}
