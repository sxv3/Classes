#include "VideoGame.h"
#include <iostream>
#include <cstring>

//this file defines the methods in the Media header file
//Created by Tai Wong, 11/4/24

using namespace std;

// constructor
VideoGame::VideoGame(const char* t, int y, const char* p, float r)
    : Media(t, y), rating(r) {
    publisher = new char[strlen(p) + 1];
    strcpy(publisher, p);
}

// destructor
VideoGame::~VideoGame() {
    delete[] publisher;
}

// print video game details
void VideoGame::print() const {
    Media::print();
    cout << "Publisher: " << publisher << "\nRating: " << rating << endl;
}

// get the publisher
const char* VideoGame::getPublisher() const {
    return publisher;
}

// get the rating
float VideoGame::getRating() const {
    return rating;
}
