//  Sid A.
//  main.cpp
//  HW3
//  This program simulates a job search engine where a user can choose to display a host of jobs that are available
//  to the user or the user can choose search through the available jobs by keyword. This program uses a hashtable abstraction to store and retreive the elements.
//
//

#include "hashtable.h"


using namespace std;

const int TEST = 375;


int main()
{
    
    hashtable table; //hashtable ADT object is created here....
    jobs post; //jobs ADT object created here to store the jobs
    jobs finder; //This object will hold the matches for a job if found

    //Arrays to load information from the text file are defined here
    char file_Employers_name[TEST];
    char file_Location[TEST];
    char file_Job_Title[TEST];
    char file_Job_Description[TEST];
    char file_Required_Experience[TEST];
    char file_Pay_rate[TEST];
    
    
    //These variables will be used to store the user input
    int request;
    char choice;
    char entry[100];

    //Reading jobs from the text file is defined below
    ifstream file_in;
    file_in.open ("jobs.txt");
    if (file_in.is_open())
   {
          do
          {
            file_in.get(file_Employers_name, TEST,'|');
            file_in.ignore(100,'|');
    
            file_in.get(file_Location, TEST,'|');
            file_in.ignore(100,'|');
            file_in.get(file_Job_Title, TEST,'|');
            file_in.ignore(100,'|');
            file_in.get(file_Job_Description, TEST, '|');
            file_in.ignore(100,'|');
            file_in.get(file_Required_Experience,TEST,'|');
            file_in.ignore(100,'|');
            file_in.get(file_Pay_rate, TEST, '\n');
            file_in.ignore(100,'\n');

            //This function will fill in the the jobs from the input provided here into the hashtable
            post.create(file_Employers_name, file_Location, file_Job_Title, file_Job_Description, file_Required_Experience, file_Pay_rate);
            //Load jobs function loads jobs from the text file into the hashtable
            table.loadjobs(post, file_Job_Title);
          }while(!file_in.eof());

     }
        file_in.close();
        file_in.clear();
    

    
    do{
        
        cout << '\n';
        cout << " Welcome To The Job Search Engine "  << '\n' <<endl;
        cout << " Please Enter An Option " << '\n' <<endl;
        cout << " Enter 1 To Display All Current Jobs " << '\n' <<endl;
        cout << " Enter 2 To Search For a Job " << '\n' <<endl;
        
        
        cin >> request;
        cin.ignore(3,'\n');
        
        
        if(request == 1)
        {
            
            cout << " These Are The Current Job Postings : "<<endl;
            table.display_all();
        }
        
        if(request == 2)
        {
            
            cout << " Please Enter A Job Posting To Search For : "<<endl<<endl;
            
            
            cin.get(entry, 100, '\n');
            cin.ignore(100,'\n');
            
            table.retrieve(finder, entry);
            finder.display();
        }
        
        
        
        cout << " Would you like to return to the main menu ? "<<endl;
        cin >> choice;
        cin.ignore(3,'\n');
    
    } while (toupper(choice)=='Y');
    

    
    return 0;
  


}




