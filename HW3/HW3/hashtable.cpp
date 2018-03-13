//  Sid A.
//  hashtable.cpp
//  CS 163 HW3
//  This is the .cpp file for the hashtable class abstraction. This includes all of the implementaions fro all the
//  member functions from the hashtable class.
//
//

#include "hashtable.h"



using namespace std;


//hashtable constructor
hashtable::hashtable()
{
    hash_table = new node * [TABLE_SIZE];

    for (int i = 0; i < TABLE_SIZE; ++i)
    {

        hash_table[i] = NULL;

    }


}


//hashtable destructor, deallocate dynamic memory
hashtable::~hashtable()
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
int hashtable::hash_function(char Job_Title[])
{
    int index = 0;

    if (!Job_Title) return 1;

    for (int i = 0; i < strlen(Job_Title); ++i)
	  {	
	     
	     index += Job_Title[i];
	  
	  }
	      
              index %= TABLE_SIZE;
	  	
	      return index;


}



//This function loads the jobs into the hash function based on the index provided by the input
int hashtable::loadjobs(jobs & to_add, char * input)
{
    int i;
    hash_function(input);
    i = hash_function(input);

    node * temp = new node;
    temp -> a_job.copy(to_add);
    temp -> next = hash_table[i];
    hash_table[i] = temp;

    return 1;
}



//This function will search through the hash table to locate a job match if one is found
int hashtable::retrieve(jobs & found, char * job_search)
{
    int i;
    hash_function(job_search);
    i = hash_function(job_search);

    node * temp = hash_table[i];
    while (temp)
    {
        temp -> a_job.retrieve(found, job_search);
        temp = temp -> next;
    }

    return 1;
}




//Thsi function displays all the jobs in the list
int hashtable::display_all()
{
    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        node * current = hash_table[i];
        while (current)
        {
            current -> a_job.display();
            current = current -> next;

        }

    }
    return 0;

}






