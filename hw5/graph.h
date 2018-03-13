// Sid Abdullahi
// CS 163 Program 5
// These are the prototypes for the graph class and structure definitions for the vertex

#include <iostream>
#include <cstring>
#include <fstream>
#include <cctype>




struct vertex
{
        char * ride;
        struct node * head;

};



struct node
{
        vertex * adjacent;
        node * next;

};



class graph
{
        public:
                graph(int size = 9);
                 ~graph();
                int insert_vertex(vertex & to_add , char ride_name []);
                int find_location(char * key_value);
                int display_vertices(char * key_value);
                int insert_edge(char * current_vertex, char * to_attach);
                int displayall(void);

        private:
                vertex * adjacency_list;
                int list_size;
};

