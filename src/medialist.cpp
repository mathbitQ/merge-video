/*
    File: medialist.cpp
    Date created: August 2024
    Author: mathbitQ
    Description: An initialization for capturing a list of media files
                 All MediaFile objects will be stored as a vector of pointer of object
                 Media list allows the user to add, remove a file, display content of
                 a list of media file.
    Version: 1.0
*/
#include "medialist.h"

// A construction for creating media list
MediaList::MediaList()
{

}

// A destruction for deleting media list
MediaList::~MediaList()
{

}

// Adds a new MediaFile to vector
// MediaFile will be pushed back of a vector
void MediaList::push(MediaFile *index)
{
    mediaFileList.push_back(index);
}


// Deletes all the contents of MediaFile, freeing
// memory and clearing all the pointers point to
// the MediaFile
void MediaList::clear()
{
    for(uint64_t i = 0; i < mediaFileList.size(); i++)
        delete mediaFileList[i];
    mediaFileList.clear();
}

// Returns true if vector containing media file list
// is empty
bool MediaList::isEmpty()
{
    return mediaFileList.empty();
}

// Removes file at the end of the list
// and freeing memory
void MediaList::pop()
{
    delete mediaFileList.back();
    mediaFileList.pop_back();
}

// Removes file at a certain of the list
// If position given is invalid, raises an error
void MediaList::pop(uint64_t index)
{
    if(index >= 0 && index <= mediaFileList.size() - 1)
    {
        delete mediaFileList.at(index);
        mediaFileList.erase(mediaFileList.begin() + index);
    }
    //For debug
    else
        std::cerr<<"Invalid position!"<<std::endl;
}

// Displays the content of a media file list
void MediaList::display()
{
    for(uint64_t i = 0; i < mediaFileList.size(); i++)
        mediaFileList[i]->display();
}
// Gets the content of a media file from the media list
// Returns as a pointer to MediaFile
// Returns null pointer if index given is invalid
MediaFile *MediaList::at(uint64_t index)
{
    if((index >= 0 && index <= mediaFileList.size() - 1) || (mediaFileList.size() > 0))
        return mediaFileList.at(index);
    return nullptr;
}

// Returns the size of a media file list
int MediaList::size()
{
    return mediaFileList.size();
}
