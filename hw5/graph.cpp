#include "graph.h"

using namespace std;

//const int SIZE = 10;




//Here a constructor is defined for the graph
graph::graph(int size)
{
	list_size = size;
    adjacency_list = new vertex[list_size];

    for (int i=0; i < list_size; ++i)
	{
		adjacency_list[i].ride = NULL;
		adjacency_list[i].head = NULL;
	}

}

//Destructor for the graph data structure
graph::~graph()
{
	
    for (int i=0; i < list_size ; ++i)
    {

		node * current = adjacency_list[i].head;
		while(current)
		{
			node * temp = current;
			current = current->next;
			delete temp;
			adjacency_list[i].ride = NULL;
		}
    }

    delete [] adjacency_list;
}


//Function to insert a vertex into the adjacency list
int graph::insert_vertex(vertex & to_add, char ride_name [])
{
    for (int i=0; i <list_size ; ++i)
	{
        if (!adjacency_list[i].ride)
		{
		
          adjacency_list[i].ride = new char[strlen(ride_name)+1];
          strcpy(adjacency_list[i].ride, ride_name);

          return 0;
		}
    }
    return 1;
}




//Find location is the retrieve function which searches the list to find a match if one is present
int graph::find_location(char * key_value)
{
	int index_location = 0;
	
    for (int i=0; i < list_size; ++i)
	{
	    
        if(strcmp(adjacency_list[i].ride,key_value) == 0)
	    index_location =i;

    }
	return index_location;
}


//This function will display relevant rides based on the input provided
int graph::display_vertices(char * key_value)
{
	int i = find_location(key_value);
	node * current = adjacency_list[i].head;

    while(current)
	{
        cout << adjacency_list[i].ride << " -> ";
		current = current->next;

	}
    return 1;
}

//This function inserts a new edge into the list, and attachs an adjacent ride to the vertex
int graph::insert_edge(char * current_vertex, char * to_attach)
{
	int current_index = find_location(current_vertex);
	int to_attach_index = find_location(to_attach);

	node * temp = new node;
	temp->adjacent = &adjacency_list[to_attach_index];
	temp->next = adjacency_list[current_index].head;
	adjacency_list[current_index].head = temp;

	return 1;

}


//Display Function.. 
int graph::displayall()
{
    for (int i = 0; i < list_size; ++i)
	{

        cout << adjacency_list[i].ride << " -> ";

	}

    return 0;

}
