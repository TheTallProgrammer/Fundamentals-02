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
#include <cstring>
using namespace std;

int main ()
{
   char str1[10] = "Hello";
   char str2[10] = "World";
   char str3[10];
   int  len ;
   
   strcpy( str3, str1); // copy str1 into str3
   cout << "strcpy( str3, str1) : " << str3 << endl;

   strcat( str1, str2); // concatenates str1 and str2
   cout << "strcat( str1, str2): " << str1 << endl;
 
   len = strlen(str1); // total lenghth of str1 after concatenation
   cout << "strlen(str1) : " << len << endl;
   
   system("PAUSE");
   return 0;
}//end of main()
