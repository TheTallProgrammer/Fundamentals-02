/* 
Name:     		Gia Rivera
Date: 			Feb 27 2021
Assignment #:	classWork32
Status: 		Completed
Language:		C++
-------------------------------------------------------------------------
Comments
Learning while loop
how many even numbers are there between 1 and 100?
what is the sum of even numbers between 1 and 100?
what is the average of even numbers between 1 and 100?
*/

#include <iostream>				// for cin, cout, endl
using namespace std;

int main()
{
	int count;
	int evenCount;
	int tally;
	float average;
	
	count = 1;
	evenCount = 0;
	while (count <=100)
	{
		if (count % 2 == 0)
		{
			evenCount = evenCount + 1;
			tally = tally + count;	
		}
		count = count + 1;
	}
	
	average = tally / evenCount;
	cout << "The number of even numbers b/w 1 & 100: " << evenCount << endl;
    cout << "The sum of the even numbers b/w 1 & 100: " << tally << endl;
    cout << "The average of the even numbers b/w 1 & 100: " << average << endl;
    
	system("PAUSE");
    return 0;
} // end of main()

