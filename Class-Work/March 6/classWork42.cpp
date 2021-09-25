/* 
Name:     		Logan Falkenberg
Date: 			March 6 2021
Assignment #:	classWork40
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments
learning for loops - display numbers between 1 and 100

*/
#include <iostream>				// for cin, cout, endl
using namespace std;

//prototype declerations


int main()
{
	
	for (int ctr = 1; ctr <= 100; ctr++){
		if (ctr % 2 == 0){
			cout << ctr << endl;
		}
	}
	
	cout << "\nI am exiting the loop" << endl;

	// Ends the function 
    cin.get();
    return 0;
    
}// end of main



