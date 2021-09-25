/* 
Name:     		Logan Falkenberg
Date: 			March 13 2021
Assignment #:	classwork55
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments

1. Create a class called Rectangle. 
2. Create a constructor called simple. Constructor means method that will execute when the object is created. 

Program definition
1. Object of simple will be created
*/

#include <iostream>				// for cin, cout, endl
using namespace std;

// Declare classes
class Simple{
	
	public:
		Simple(){
			
			cout << "Constructing Simple" << endl;
			
		}
};
          
int main()
{
	Simple mySimple;
    
    
    system("PAUSE");
    return 0;
} // end of main()

