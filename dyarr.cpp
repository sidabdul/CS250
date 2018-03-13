#include <iostream>
#include <cctype>

using namespace std;


int main()
{

char str[20];
cout << "Enter string " <<endl;
cin.get(str,20);
char * arr = new char[strlen(str) + 1];



cout << arr<<endl;

cout<<str<<endl;

return 0;

}
