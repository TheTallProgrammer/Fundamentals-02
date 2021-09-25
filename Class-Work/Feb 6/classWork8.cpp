/* 
Name:     		Logan Falkenberg
Date: 			Feb 6
Assignment #:	classWork8
Status: 		Completed
Language: 		C++
-------------------------------------------------------------------------
Comments
The program is about functions
*/

#include <iostream>				// for cin, cout, endl
using namespace std;

// Declaration of function prototypes
void header(string);

int main()
{
	header("classwork9"); // Calling the header() function
    system("PAUSE");
    return 0;
} // end of main()

// header() function displays 
void header(string prompt)
{
	cout << "-----------------------------------------------------------------"
	cout << prompt << endl;
	cout << "Written by Logan" << endl;
	cout << "Feb 6, 2021" << endl;
	cout << "-----------------------------------------------------------------"
} // End of header()
