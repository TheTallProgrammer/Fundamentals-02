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

#include <string>
#include <iostream>
using namespace std;

struct Movies {
  string title;
  int year;
} ;

int main(){
	
	Movies films[3];
	int count;
	
	for (count = 0; count < 3; count++)
	{
		cout << "Enter title: ";
	    getline (cin, films[count].title);
	    
	    cout << "Enter year: ";
	    cin >> films[count].year;
	    
	    cin.ignore();
	}
	
	cout << "\nYou have entered these movies:\n";
   	for (count = 0; count < 3; count++)
   	{    
    	printMovie (films[count]);  
   	}
  
	
	return 0;
}

void printMovie (Movies movie)
{
	string spacer(10, ' '); // Spacing variable
	cout << spacer << movie.title;
	cout << " (" << movie.year << ")\n";
}
