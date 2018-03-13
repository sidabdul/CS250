//  Sid A.
//  jobs.h
//  CS163 HW3
//  This is the .h file which contains the prototypes for the jobs class


#include <iostream>
#include <cstring>
#include <fstream>
#include <cctype>


const int SIZE = 25;

//The jobs class which manages a job and the associated attributes
class jobs
{
	public:
		jobs();
		~jobs();
		int create(char emp_name[], char locus[], char job_name[], char job_descrip[], char exp_req[], char pay[]);
		int copy(jobs & dest);
		int retrieve(jobs & found, char * match);
		int display ();

		private:
            char * Employers_name;
	        char * Location;
    		char * Job_Title;
    		char * Job_Description;
    		char * Required_Experience;
    		char * Pay_rate; 
   
		
};

