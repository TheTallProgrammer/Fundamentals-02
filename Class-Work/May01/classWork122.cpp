/* 
Name:     		Gia Rivera
Date: 			May 01 2021
Assignment #:	classWork122
Status: 		Completed
Language:		C++
-------------------------------------------------------------------------
Comments
more pointers
*/

#include <iostream>
using namespace std;
int main()
{
    /* x is an integer variable. */
    int x = 42;
    
    /* x_ptr is a pointer to an integer variable. */
    int * x_ptr = & x;
    
    printf ("x = %d\n", x);
    printf ("x_ptr = %p\n", x_ptr);
    
  	system("PAUSE");
  	return 0;
} // end of main()
