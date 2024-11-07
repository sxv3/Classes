#ifndef MUSIC_H
#define MUSIC_H

#include "Media.h"

//this header file declares the music class and adds fields and methods
//Created by Tai Wong, 11/4/24


class Music : public Media {
private:
    char* artist;    // artist of the music
    int duration;    // duration in minutes
    char* publisher; // publisher of the music
public:
    Music(const char* title, int year, const char* artist, int duration, const char* publisher); // constructor
    ~Music();    // destructor
    void print() const override; // print music details
    const char* getArtist() const;   // get the artist
    int getDuration() const;         // get the duration
    const char* getPublisher() const; // get the publisher
};

#endif
