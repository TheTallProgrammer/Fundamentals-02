/* 
Name:     		Gia Rivera
Date: 			Feb 27 2021
Assignment #:	classWork30
Status: 		Completed
Language:		C++
-------------------------------------------------------------------------
Comments
Learning while loop
how many even numbers are there between 1 and 100?
*/

#include <iostream>				// for cin, cout, endl
using namespace std;

int main()
{
	int count;
	int evenCount;
	
	count = 1;
	evenCount = 0;
	while (count <=100)
	{
		if (count % 2 == 0)
		{
			evenCount = evenCount + 1;	
		}
		count = count + 1;
	}
	
	cout << "The number of even numbers b/w 1 & 100: " << evenCount << endl;
    
	system("PAUSE");
    return 0;
} // end of main()

