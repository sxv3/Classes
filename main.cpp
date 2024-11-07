#include <iostream>
#include <vector>
#include <cstring>
#include "Media.h"
#include "VideoGame.h"
#include "Music.h"
#include "Movie.h"

//Classes, a program utilizes 5 cpp files and 4 header files to store different media types of Music, VideoGame, and Movie. The program lets the user store and search the different media types stored.
//Created by Tai Wong, 11/4/24

using namespace std;

int main() {
  vector<Media*> mediaList; //store media pointers in vector
  char command[10]; // store user input

  while (true) {
    cout << "Enter a command (ADD, SEARCH, DELETE, QUIT): ";
    cin.getline(command, 10); // get user input
    
    if (strcmp(command, "ADD") == 0) {
      // adds new media to the database
      cout << "Enter media type (VideoGame, Music, Movie): ";
      char type[20];
      cin.getline(type, 20);
	    
      //if it is video game
      if (strcmp(type, "VideoGame") == 0) {
	// collect information from user
	char title[100];
        char publisher[100];
        int year;
        float rating;

        //collect more info
        cout << "Enter title: ";
        cin.getline(title, 100);
        cout << "Enter year: ";
        cin >> year;
        cin.ignore();
        cout << "Enter publisher: ";
        cin.getline(publisher, 100);
        cout << "Enter rating: ";
        cin >> rating;
        cin.ignore();

         // creates new videogame object and add to medialist
        VideoGame* videogame = new VideoGame(title, year, publisher, rating);
        mediaList.push_back(videogame);
	
      } else if (strcmp(type, "Music") == 0) {

	// collect music information from user
	char title[100];
	char artist[100];
	char publisher[100];
        int year, duration;
        cout << "Enter title: ";
        cin.getline(title, 100);
        cout << "Enter year: ";
        cin >> year;
        cin.ignore();
        cout << "Enter artist: ";
        cin.getline(artist, 100);
        cout << "Enter duration (in minutes): ";
        cin >> duration;
        cin.ignore();
        cout << "Enter publisher: ";
        cin.getline(publisher, 100);

        // create new music object and add to mediaList
        Music* music = new Music(title, year, artist, duration, publisher);
        mediaList.push_back(music);

      } else if (strcmp(type, "Movie") == 0) {

	// collect movie information from user
	char title[100];
	char director[100];
	int year, duration;
	float rating;
        cout << "Enter title: ";
        cin.getline(title, 100);
        cout << "Enter year: ";
        cin >> year;
        cin.ignore();
        cout << "Enter director: ";
        cin.getline(director, 100);
        cout << "Enter duration (in minutes): ";
        cin >> duration;
        cin.ignore();
        cout << "Enter rating: ";
        cin >> rating;
        cin.ignore();

	// create new movie  object and add to mediaList
        Movie* movie = new Movie(title, year, director, duration, rating);
        mediaList.push_back(movie);


      } else {
	cout << "Unknown media type!" << std::endl;
      }
    } else if (strcmp(command, "SEARCH") == 0) {
            // search command
      cout << "Search by title or year? ";
      char criteria[10];
      cin.getline(criteria, 10);
      
      if (strcmp(criteria, "title") == 0) {
	// search by title
        cout << "Enter title to search: ";
	char searchTitle[100];
	cin.getline(searchTitle, 100);
        // iterate over medialist and compare titles
	
	for (Media* media : mediaList) {
	  if (strcmp(media->getTitle(), searchTitle) == 0) {
	    media->print();
	    cout << endl;
	  }
	}
      } else if (strcmp(criteria, "year") == 0) {

	// search by year
        cout << "Enter year to search: ";
	int searchYear;
	cin >> searchYear;
        cin.ignore();

	// iterate over medialist and compare years

	for (Media* media : mediaList) {
	  if (media->getYear() == searchYear) {
	    media->print();
	    cout << endl;
	  }
	}
      } else {
	cout << "Unknown search criteria!" << endl;
      }
    } else if (strcmp(command, "DELETE") == 0) {

      cout << "Delete by title or year? ";
      char criteria[10];
      cin.getline(criteria, 10);
      vector<Media*>::iterator it = mediaList.begin();

      if (strcmp(criteria, "title") == 0) {

	// delete by title

	cout << "Enter title to delete: ";
	char searchTitle[100];
	cin.getline(searchTitle, 100);

	// iterate over mediaList and compare titles
	while (it != mediaList.end()) {
	  Media* media = *it;

	  if (strcmp(media->getTitle(), searchTitle) == 0) {
	    media->print();
            // ask for confirmation
            cout << "Do you want to delete this item? (y/n): ";
            char response[10];
            cin.getline(response, 10);

	    if (strcmp(response, "y") == 0) {
	      // delete the media and remove from vector
	      delete media;
	      it = mediaList.erase(it);
	      continue;
	    }
	  }
	  ++it;
	}	
      } else if (strcmp(criteria, "year") == 0) {
	// delete by year
        cout << "Enter year to delete: ";
        int searchYear;
        cin >> searchYear;
        cin.ignore();


	// iterate over medialist and compare years

        while (it != mediaList.end()) {
	  Media* media = *it;
	  
          if (media->getYear() == searchYear) {
	    media->print();
            cout << "Do you want to delete this item? (y/n): ";
            char response[10];
            cin.getline(response, 10);

            if (strcmp(response, "y") == 0) {

	      // delete the media and remove from vector
              delete media;
              it = mediaList.erase(it);
              continue;
	    }
	  }
          ++it;
	}
      } else {
        cout << "Unknown delete criteria!" << std::endl;
      }
    } else if (strcmp(command, "QUIT") == 0) {
      // QUIT command to exit the program
      break;
    } else {
      cout << "Unknown command!" << std::endl;
    }
  }

  // clean up dynamically allocated memory before exiting
  for (Media* media : mediaList) {
    delete media;
  }
}
