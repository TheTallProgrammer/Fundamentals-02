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
double num;
  int inputVar = 0;
  // Enter the do while loop and stay there until either
  // a non-numeric is entered, or -1 is entered.  Note that
  // cin will accept any integer, 4, 40, 400, etc.
  do {
    cout << "Enter a number (-1 = quit): ";
    // The following line accepts input from the keyboard into // variable input_var.
    // cin returns false if an input operation fails, that is, if
    // something other than an int (the type of input_var) is entered.
    
    if (!(cin >> inputVar)) {
      cout << "Please enter numbers only." << endl;
      cin.clear();
      cin.ignore(100,'\n');
    }
    if (inputVar != -1) {
      cout << "You entered " << inputVar << endl;
    }
  } while (inputVar != -1);
  
  cout << "All done." << endl;
    
    system("PAUSE");
    return 0;
} // end of main()
