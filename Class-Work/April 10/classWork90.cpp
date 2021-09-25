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
void getMovieData(Movies []);
void printMovieData(Movies []);

int main()
{
    Movies films[3];
    getMovieData(films);
    printMovieData(films);
    return 0;
}

void printMovieData(Movies film[])
{
    string spacer(10, ' ');
    for (int n = 0; n < 3; n++)
    {
        cout << spacer << film[n].title;
        cout << " (" << film[n].year << ")\n";
    }
}
void getMovieData(Movies films[])
{
    for (int n = 0; n < 3; n++)
    {
        cout << "Enter title: ";
        getline (cin, films[n].title);
    
        cout << "Enter year: ";
        cin >> films[n].year;
    
        cin.ignore();
    }
}
