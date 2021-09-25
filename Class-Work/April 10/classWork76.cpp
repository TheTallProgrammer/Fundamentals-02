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
#include <string>
using namespace std;

int main()
{
    string name;
    cout << "Enter your name: " ;
    getline (cin, name);  // read a whole line into the string name
    
    if (name == "")
    {
        cout << "You entered an empty string, "
             << "assigning default\n";
        name = "John";
    }
    else
    {
        cout << "Thank you " << name
             << " for running this simple program!"
             << endl;
    }
    
    system("PAUSE");
    return 0;
}  // end of main()
