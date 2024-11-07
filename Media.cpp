#include "Media.h"
#include <iostream>
#include <cstring>

//This cpp file defines the methods that are defined in the corresponding header file
//Handles the construction, destruction, and basic functionalities common to all media types
//Created by Tai Wong, 11/3/24

using namespace std;

// constructor
Media::Media(const char* t, int y) : year(y) {
    title = new char[strlen(t) + 1];
    strcpy(title, t);
}

// destructor
Media::~Media() {
    delete[] title;
}

// print the media details
void Media::print() const {
    cout << "Title: " << title << "\nYear: " << year << endl;
}

// get the title
const char* Media::getTitle() const {
    return title;
}

// get the year
int Media::getYear() const {
    return year;
}
