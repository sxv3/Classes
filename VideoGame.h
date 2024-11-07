#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "Media.h"

// this file declares the VideoGame class and adds methods
//Created by Tai Wong, 11/4/24

class VideoGame : public Media {
private:
    char* publisher; // publisher of the video game
    float rating;    // rating of the video game
public:
    VideoGame(const char* title, int year, const char* publisher, float rating); // constructor
    ~VideoGame();   // destructor
    void print() const override; // print video game details
    const char* getPublisher() const; // get the publisher
    float getRating() const;          // get the rating
};

#endif
