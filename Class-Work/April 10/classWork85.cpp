/* 
Name:     		Logan Falkenberg
Date: 			March 13 2021
Assignment #:	classwork55
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments


*/
/* isdigit example */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main ()
{
  char str[]="aaa1776ad";
  int year;
  
  if (isdigit(str[0]))
  {
    year = atoi (str);
    printf ("The year that followed %d was %d.\n",year,year+1);
  }
  else
    printf ("Starts with char %s.\n",str);
  return 0;
}
