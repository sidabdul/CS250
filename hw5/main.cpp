#include "graph.h"

using namespace std;

int main()
{

  char test[20];
  graph map;
  vertex amusement;

  char choice;

  do{

  cout << "Please Enter in a ride : " <<endl;
  cin.get(test,20,'\n');
  cin.ignore(20,'\n');    
  map.insert_vertex(amusement, test);
  //map.insert_edge(amusement, test);



  //map.displayall();




  cout << " Would you like to add another ride ? "<<endl;
  cin >> choice;
  cin.ignore(3,'\n');



 } while (toupper(choice)=='Y');

  cout << "gets here tho1" <<endl;

  cout << " Rides Currently In The List Related That Are Related Are : ";

  map.displayall();

  cout << "gets here tho 2 " <<endl;




  cout << '\n' <<endl;

}
