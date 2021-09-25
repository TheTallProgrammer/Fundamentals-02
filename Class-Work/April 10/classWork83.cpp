/* 
Name:     		Logan Falkenberg
Date: 			March 13 2021
Assignment #:	classwork55
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments


*/
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi, atol */
using namespace std;
int main ()
{
  long int line;
  char buffer[256];
  
  printf ("Enter a long number: ");
  
  fgets (buffer, 256, stdin);
  
  line = atol(buffer);
  
  printf ("The value entered is %ld. Its double is %ld.\n", line, line * 2);
  
   system("PAUSE");
   return 0;
}
