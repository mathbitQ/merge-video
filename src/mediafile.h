/*
    File: mediafile.h
    Date created: August 2024
    Author: mathbitQ
    Description: An initialization object for defining media file.
                 Includes only two main properties are path file and
                 duration of media file.
    Version: 1.0
*/
#ifndef MEDIAFILE_H
#define MEDIAFILE_H

#include <wx/wx.h>
#include <cstdint>

class MediaFile
{
public:
    MediaFile();
    MediaFile(const MediaFile& source);
    MediaFile(wxString path, int64_t duration);
    virtual ~MediaFile();
    void setPath(wxString path);
    wxString getPath();
    void setDuration(int64_t duration);
    int64_t getDuration();
    void display();
private:
    wxString pathFile;
    int64_t duration;
};

#endif // MEDIAFILE_H
