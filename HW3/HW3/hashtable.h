//  Sid A.
//  hashtable.h
//  CS163 HW3
//  This is the .h file which contains the prototypes for the hashtable class
//  
//
//

#include <iostream>
#include <cctype>
#include <fstream>
#include <cstring>

#include "jobs.h"


const int TABLE_SIZE = 17;



//This is the node struct that points to the data stored in the hash table
struct node
{
    jobs a_job;
    node * next;
};




//This is the table class that stores and manages the hash table
class hashtable
{

public:
    hashtable();
    ~hashtable();
    int hash_function(char []);
    int loadjobs(jobs & to_add, char * input);
    int retrieve(jobs & collect, char * match);
    int display_all();
    
private:
    node ** hash_table;
    
};





