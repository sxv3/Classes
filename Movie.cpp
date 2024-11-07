#include "Movie.h"
#include <iostream>
#include <cstring>

//this file contains the definition of the Movie class
//created by Tai Wong, 11/4/24

using namespace std;

// constructor
Movie::Movie(const char* t, int y, const char* d, int du, float r) : Media(t, y), duration(du), rating(r) {
    director = new char[strlen(d) + 1];
    strcpy(director, d);
}

// destructor
Movie::~Movie() {
    delete[] director;
}

// print movie details
void Movie::print() const {
    Media::print();
    cout << "Director: " << director << "\nDuration: " << duration << " mins\nRating: " << rating << endl;
}

// get the director
const char* Movie::getDirector() const {
    return director;
}

// get the duration
int Movie::getDuration() const {
    return duration;
}

// get the rating
float Movie::getRating() const {
    return rating;
}
