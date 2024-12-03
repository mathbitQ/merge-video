/*
    File: medialist.h
    Date created: August 2024
    Author: mathbitQ
    Description: An initialization for capturing a list of media files
                 All MediaFile objects will be stored as a vector of pointer of object
                 Media list allows the user to add, remove a file, display content of
                 a list of media file.
    Version: 1.0
*/

#ifndef MEDIALIST_H
#define MEDIALIST_H

#include "mediafile.h"
#include <vector>
#include <cstdint>

class MediaList
{
public:
    MediaList();
    virtual ~MediaList();
    void push(MediaFile* index);
    void clear();
    void pop();
    void pop(uint64_t index);
    bool isEmpty();
    void display();
    MediaFile *at(uint64_t index);
    int size();

private:
    std::vector<MediaFile*> mediaFileList;
};

#endif // MEDIALIST_H
