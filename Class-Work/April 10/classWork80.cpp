/* 
Name:     		Logan Falkenberg
Date: 			March 13 2021
Assignment #:	classwork55
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments


*/
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
   string firstname;
   string lastname;
   string fullname;
   cout << "First name: ";
   getline (cin, firstname);
   
   cout << "Last name: ";
   getline (cin, lastname);
   fullname = lastname + ", " + firstname;
   cout << "Fullname: " << fullname << endl;
    
    system("PAUSE");
    return 0;
}
