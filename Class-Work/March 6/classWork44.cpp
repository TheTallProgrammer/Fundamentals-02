/* 
Name:     		Logan Falkenberg
Date: 			March 6 2021
Assignment #:	classWork44
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments
count how many numbers between 1 - 100 which are divisible by 7 and not by 6
use while loop to do the work
*/
#include <iostream>				// for cin, cout, endl
using namespace std;

//prototype declerations


int main()
{
	int count;
	int divisibleCount;
	
	divisibleCount = 0;
	
	count = 1;
	
	while (count < 100){
		if (count % 7 == 0 && count % 6 != 0){
			divisibleCount = divisibleCount + 1;
		}
		
		count = count + 1;
	}
	
	cout << "divisibleCount: " << divisibleCount << endl;

	// Ends the function 
    cin.get();
    return 0;
    
}// end of main



