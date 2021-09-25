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
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */
using namespace std;
int main ()
{
  int integer;
  char buffer[256] = "12";
  

 integer = atoi (buffer);
  
  printf ("The value entered is %d. Its double is %d.\n", integer, integer * 2);
  
  cout << "The value entered is " << integer << " Its double is " << integer * 2 << endl;
  
   system("PAUSE");
   return 0;
}
