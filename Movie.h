#ifndef MOVIE_H
#define MOVIE_H

#include "Media.h"

//This header file declares movie class and adds fields and methods
//Created by Tai Wong, 11/4/24


class Movie : public Media {
private:
    char* director; // director of the movie
    int duration;   // duration in minutes
    float rating;   // rating of the movie
public:
    Movie(const char* title, int year, const char* director, int duration, float rating); // constructor
    ~Movie();    // destructor
    void print() const override; // print movie details
    const char* getDirector() const; // get the director
    int getDuration() const;         // get the duration
    float getRating() const;         // get the rating
};

#endif
