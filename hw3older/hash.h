/*
 
 Sid Abdullahi 
 CS163
 Assignment 3
 
 hash.h file
 
 */




#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
#include <math.h>


using namespace std;


// This structure will hold all info pretaining to song information
struct song 
{
   
    char * title;
    char * artist_name;
    char * album_name;
    char * num_of_mins;
    char * played;
    
};

// This structure will organize each song
struct node
{
    song data;
    node * next;
};


//Class prototype and functions
class table
{
	public:
		table();
		~table();
		int hash(char []);
        int display();
        void display_song(song listing);
        int retrieve(char [], int );
		int make(node * , song & );
		int remove(char []);
	private:
	//Hash table will be an array of linked lists
    node ** hash_table;

};
