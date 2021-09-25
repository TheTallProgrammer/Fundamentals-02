/* 
Name:     		Gia Rivera
Date: 			Feb 27 2021
Assignment #:	classWork29
Status: 		Completed
Language:		C++
-------------------------------------------------------------------------
Comments
Learning while loop
display the numbers between 1 and 100 which are
divisible by 7 and not divisible by 5
*/

#include <iostream>				// for cin, cout, endl
using namespace std;

int main()
{
	int count;
	
	count = 1;
	
	while (count <=100)
	{
		if (count % 7 == 0 && count % 5 != 0)
		{
			cout << count << endl;	
		}
		count = count + 1;
	}
	
    system("PAUSE");
    return 0;
} // end of main()

