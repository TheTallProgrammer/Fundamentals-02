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

struct Movies 
{
  string title;
  int year;
};

void printMovie(Movies);

int main(){
	
	Movies myMovies;
	
	cout << "Enter title: ";
	getline(cin, myMovies.title);
	
	cout << "Enter year: ";
	cin >> myMovies.year;
	
	printMovie(myMovies);
	
	return 0;
}

void printMovie(Movies movie){
	cout << movie.title;
	cout << "(" << movie.year << ")" << endl;;
}
