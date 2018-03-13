#include "bst.h"

using namespace std;

int main()
{


table bst;
nominee an;




char test[20];


int voting = 0;

char choice;

do{

cout << "Enter in a nominee name " <<endl;
	cin.get(test, 20, '\n');
			cin.ignore(20,'\n');

    
    cout << " H0w many votes for this nominee ? " <<endl;
    cin >>voting;

bst.add(an, test, voting);







//bst.vote(an,voting);






cout << " Would you like to add another nominee ? "<<endl;
        cin >> choice;
        cin.ignore(3,'\n');



 } while (toupper(choice)=='Y');




cout << "Here are the nominees : " <<endl;
bst.displayall();


char remove[15];

cout << "Enter a nominee to remove : " <<endl;

cin.get(remove, 15, '\n');

cin.ignore(15,'\n');



cout << '\n';

bst.remove(remove);





cout << '\n';
cout << " The nominees after deletion : " <<endl;

cout << '\n';

bst.displayall();



cout << '\n';
/*

char find[15];


cout << " Enter a  nominee to search for  : " <<endl;


cin.get(find, 15, '\n');

cin.ignore(15,'\n');


bst.retrieve(an,find);


*/

return 0;

}
