/* 
Name:     		Gia Rivera
Date: 			Feb 27 2021
Assignment #:	classWork28
Status: 		Completed
Language:		C++
-------------------------------------------------------------------------
Comments
Learning while loop
display the numbers between 20 and 200 which are
divisible by 7 and 5
*/

#include <iostream>				// for cin, cout, endl
using namespace std;

int main()
{
	int count;
	
	count = 20;
	
	while (count <=200)
	{
		if (count % 7 == 0 && count % 5 == 0)
		{
			cout << count << endl;	
		}
		count = count + 1;
	}
	
    system("PAUSE");
    return 0;
} // end of main()

