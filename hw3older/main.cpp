// Sid Abdullahi
// CS163
// Assignment 3
//
//This program will simulate a voiced based music player where the user will choose a song to play based on the
//response from the user by stating a few words of the title of the song, then a match will be provided based on the
//keyword the user has provided
//
//
//

#include "hash.h"

using namespace std;



int main()

{
    
    table music;
    song a_song;
    song listing;

    
    //Display songs in list
    
    cout << " Here are the listings for the songs : "<<endl;
    
    cout << "Title:  " << listing.title << endl;
    
    cout << "Artitst Name:  " << listing.artist_name << endl;
    
    cout << "Album Name:  " << listing.album_name << endl;
    
    cout << "Song Length:  " << listing.num_of_mins << endl;
    
    cout << "How many time played:  " << listing.played << endl;
    

    return 0;

}
















