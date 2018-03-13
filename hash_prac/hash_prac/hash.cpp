//
//  hash.cpp
//  hash_prac
//
//  Created by Sid-Ali Isgow on 3/4/15.
//  Copyright (c) 2015 Sid-Ali Isgow. All rights reserved.
//

#include "hash.h"



//hashtable constructor
hash::hash()
{
    hash_table = new node * [TABLE_SIZE];
    
    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        
        hash_table[i] = NULL;
        
    }
    
    
}


//hashtable destructor, deallocate dynamic memory
hash::~hash()
{
    
    for (int i = 0; i < TABLE_SIZE - 1; ++i)
    {
        node * current = hash_table[i];
        while(current)
        {
            node * temp = current;
            current = current -> next;
            temp -> next = NULL;
            delete temp;
            hash_table[i] = NULL;
            
        }
        
    }
    delete [] hash_table;
    
    
}




//This is the hash function which takes a job title as an argument and supplies back index to store the job!
int hash::hashfunc(int key)
{
    int index = 0;
    
    if (!key) return 1;
    
   /* for (int i = 0; i < strlen(key); ++i)
    {	
        
        index += key[i];
        
    }
    */
    //index %= TABLE_SIZE;
	else
    {
    key %= TABLE_SIZE;
    }
    //return index;
    return key;
    
}

int hash::insert(int num)
{


    int i;
    i = hashfunc(num);
    
    node * temp = new node;
    temp -> x = num;
    temp -> next = hash_table[i];
    hash_table[i] = temp;
    
    return 1;




}

int hash::display()

{

    
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            node * current = hash_table[i];
            while (current)
            {
                std::cout << current -> x <<std::endl;
                current = current -> next;
                
            }
            
        }
        return 0;
    




}


// This function removes a song with the right match as supplied
int hash::remove(int match)
{
    int i;
    
    i = hashfunc(match);
    
    node * current = hash_table[i];
    node * temp = NULL;
    if(!current)
        return 0;
    while (current)
    {
        temp = current;
        current = current -> next;
        //temp -> next = NULL;
        delete temp;
    }
    hash_table[i] = NULL;
    return 1;
}










