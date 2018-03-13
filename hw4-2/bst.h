#include <iostream>
#include <cstring>
#include <cctype>



struct nominee
{

    char * name;
    int vote;

};


struct node
{
    nominee data;
    node * left;
    node * right;

};


class table
{

    public:
	table();
	~table();
	int displayall();
	int retrieve(nominee & found, char * actor);
	int remove(char * match);
	int destroy(node * & root);

    int vote(nominee & to_add, int num);

    

    int add(nominee & to_add, char key [], int num);

    private:

	node * root;

	int insert(node * & root_2, char key [],  nominee & to_add, int num);
	int retrieve(node * & root_2, nominee & found, char * actor);
    
    

    int vote(node * & root_2, nominee & to_add, int num);

    

    int retrieve();
	int displayall(node * root_2);
	int remove(node * & root_2, char * match);
};










