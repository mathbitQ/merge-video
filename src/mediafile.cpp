/*
    File: mediafile.cpp
    Date created: August 2024
    Author: mathbitQ
    Description: An initialization object for defining media file.
                 Includes only two main properties are path file and
                 duration of media file.
    Version: 1.0
*/
#include "mediafile.h"
#include <wx/wx.h>
#include <iostream>

// A construction of object MediaFile
MediaFile::MediaFile()
{

}

// A construction of object MediaFile that copies from another MediaFile
MediaFile::MediaFile(const MediaFile& source)
{
    this->pathFile = source.pathFile;
    this->duration = source.duration;
}

// A construction of object MediaFile that takes two properties
// of path and duration
MediaFile::MediaFile(wxString path, int64_t duration)
{
    this->pathFile = path;
    this->duration = duration;
}

// A destruction of object MediaFile
MediaFile::~MediaFile()
{

}

// Setters for path file
void MediaFile::setPath(wxString path)
{
    this->pathFile = path;
}

// Getters for path file
wxString MediaFile::getPath()
{
    return this->pathFile;
}

// Setters for duration of media file
void MediaFile::setDuration(int64_t duration)
{
    this->duration = duration;
}

// Getters for duration of media file
int64_t MediaFile::getDuration()
{
    return this->duration;
}

// Displays the content of the file
void MediaFile::display()
{
    std::cout<<this->pathFile<<" "<<this->duration<<" seconds"<<std::endl;
}
