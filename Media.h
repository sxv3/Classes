#ifndef MEDIA_H
#define MEDIA_H

// Declares Media, which is the base class for all media types. Contains the methods used by all media types
//Created by Tai Wong, 11/4/24


class Media {
protected:
    char* title; // title of the media
    int year;    // year of release
public:
    Media(const char* title, int year); // constructor
    virtual ~Media();                   // destructor
    virtual void print() const;         // print media details
    const char* getTitle() const;       // get the title
    int getYear() const;                // get the year
};

#endif
