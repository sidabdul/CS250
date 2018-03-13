/*
Sid Abdullahi

CS163
Assignment 3

This is the implemention for all of the functions in the table.h file.


*/

#include "hash.h"
using namespace std;

const int initial = 265;

char file_title[initial];
char file_artistname[initial];
char file_albumname[initial];
char file_numofmins[initial];
int file_played[initial];



int RANGE = 15; //SIZE

//table constructor
table::table()
{
	//set up the data structure
    hash_table = new node * [RANGE];
  	
    for (int i = 0; i < RANGE; ++i)
 		
        hash_table[i] = NULL;
}


//table deconstructor
table::~table()
{
	for (int i = 0; i < RANGE - 1; ++ i)
	{	
		node * current = hash_table[i];
		while(current)
		{
			hash_table[i] = current -> next;
			hash_table[i] -> next = current -> next;
			
            delete[] current -> data.title;
			current -> data.title = NULL;
			
            delete[] current -> data.artist_name;
			current -> data.artist_name = NULL;
			
            delete[] current -> data.album_name;
			current -> data.album_name = NULL;
			
            delete[] current -> data.num_of_mins;
			current -> data.num_of_mins = NULL;
			
            delete[] current -> data.played;
			current -> data.played = NULL;
			
			
            delete current;
			current = NULL;
			current = hash_table[i];
		}
	}	
}


//Hash function declaration
int table::hash(char file_tile[])
{
	int total = 0;
    if (!file_tile )
        return 0;
	
    
    
    for (int i = 0; i < strlen(file_tile); ++i)
		
        total += file_tile[i];
        total %= RANGE;
            return total;

}





int file_import(table & console)
{
    ifstream file_in;
    
    
    
    file_in.open ("Songs.txt");
   	if (file_in)
    {
        file_in.get(file_title, initial,'\t');
        
        
        
        file_in.ignore(100,'\t');
        
        
        while (!file_in.eof())
        {
            file_in.get(file_title, initial,'\t');
        
            file_in.ignore(100,'\t');
            
            file_in.get(file_artistname, initial,'\t');
            
            file_in.ignore(100,'\t');
            
            file_in.get(file_albumname, initial, '\t');
            
            file_in.ignore(100,'\t');
            
            file_in.get(file_numofmins,initial,'\t');
            
            file_in.ignore(100,'\t');
            
            file_in.get(file_title, initial,'\t');
            
            file_in.ignore(100,'\t');
        }
        file_in.close();
        
        file_in.clear();
    }
    
    return 0;
}


//delete a section of a course
int table::remove(char song[])
{
    int count = 0;
    count = hash(song);
    
    
    if (!song) return 0;
    
    if (!hash_table) return 0;
    
    
    
    node    * current = hash_table[count];
    
    
    
        while(current )
        {
        
        if ((current -> data.title) == 0)
        {
            node * temp = current;
            temp -> next = current -> next;
            delete[] current -> data.title;
            current -> data.title = NULL;
            
            delete[] current -> data.artist_name;
            current -> data.artist_name = NULL;
            
            delete[] current -> data.album_name;
            current -> data.album_name = NULL;
            
            delete[] current -> data.num_of_mins;
            current -> data.num_of_mins = NULL;
            
            delete[] current -> data.played;
            current -> data.played = NULL;
            
            
            
            delete current;
            current = NULL;
            
        }
    }
    current = current -> next;
    return 1;
}



int table::make(node * current, song & inspect)
{

	if (!current) return 0;
    if (inspect.title != NULL)
	{
        delete[] inspect.title;
        inspect.title = NULL;
	}
    if (inspect.artist_name != NULL)
	{		
        delete[] inspect.artist_name;
        inspect.artist_name = NULL;
	}
    if (inspect.album_name != NULL)
	{
        delete[] inspect.album_name;
        inspect.album_name = NULL;
	}
    if (inspect.num_of_mins != NULL)
	{
        delete[] inspect.num_of_mins;
        inspect.num_of_mins = NULL;
	}

    inspect.title = new char[strlen(current -> data.title) + 1];
    strcpy(inspect.title, current -> data.title);
	
    inspect.artist_name = new char[strlen(current -> data.artist_name) + 1];
    strcpy(inspect.artist_name, current -> data.artist_name);
	
    inspect.album_name = new char[strlen(current -> data.album_name) + 1];
    strcpy(inspect.album_name, current -> data.album_name);
	
    inspect.num_of_mins = new char[strlen(current -> data.num_of_mins) + 1];
    strcpy(inspect.num_of_mins, current -> data.num_of_mins);
	
    inspect.played = new char[strlen(current -> data.played) + 1];
    strcpy(inspect.played, current -> data.played);
	
	
    return 1;
}




void display_song(song listing)
{
    
    //Display songs in list
    
    cout << " Here are the listings for the songs : "<<endl;
    
    cout << "Title:  " << listing.title << endl;
    
    cout << "Artitst Name:  " << listing.artist_name << endl;
    
    cout << "Album Name:  " << listing.album_name << endl;
    
    cout << "Song Length:  " << listing.num_of_mins << endl;
    
    cout << "How many time played:  " << listing.played << endl;
    
    
}






int table::display()
{
	if (!hash_table) return 0;
	for (int i = 0; i < RANGE - 1; ++i)
	{
		node * current = hash_table[i];


                    while (current)
		{
            cout << "Title:  " << current -> data.title << endl;

            cout << "Artist Name:  " << current -> data.artist_name << endl;

            cout << "Album Name:  " << current -> data.album_name;

            cout << "Num of mins:  " << current -> data.num_of_mins << endl;

            cout << "Played:  " << current -> data.num_of_mins << endl;

			current = current -> next;
		
        
        
        
        }
	
       
        
    
    
    }
    
     return 3;
}







