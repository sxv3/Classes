#include "Music.h"
#include <iostream>
#include <cstring>

//This file contains the definitions for the Music class methods
//Created by Tai Wong, 11/4/24

using namespace std;

// constructor
Music::Music(const char* t, int y, const char* a, int d, const char* p)
    : Media(t, y), duration(d) {
    artist = new char[strlen(a) + 1];
    strcpy(artist, a);
    publisher = new char[strlen(p) + 1];
    strcpy(publisher, p);
}

// destructor
Music::~Music() {
    delete[] artist;
    delete[] publisher;
}

// print music details
void Music::print() const {
    Media::print();
    cout << "Artist: " << artist << "\nDuration: " << duration << " mins\nPublisher: " << publisher << endl;
}

// get the artist
const char* Music::getArtist() const {
    return artist;
}

// get the duration
int Music::getDuration() const {
    return duration;
}

// get the publisher
const char* Music::getPublisher() const {
    return publisher;
}
