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
   char line[25];
   cout << " Type a line terminated by carriage return \n>";
   cin.get(line, 25 );
   cout << "Line is " << line  << endl;
// In this example, you can type up to 24 characters and a terminating character. Any remaining characters can be extracted later.
    
    system("PAUSE");
    return 0;
}   // end of main()
