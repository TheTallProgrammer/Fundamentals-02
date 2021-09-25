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
#include <string>
using namespace std;

int main ()
{
    char name[20] = "Tarzan He Man";
    cout << name  << endl;
    
    name[5] = '\0';
    cout << name[0] << endl;
    cout << name  << endl;
     
    system("PAUSE");
    return 0;
}
