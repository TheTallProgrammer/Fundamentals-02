/* 
Name:     		Logan Falkenberg
Date: 			March 27 2021
Assignment #:	classwork61
Status: 		Completed
Language: C++
With whom I got help: 
-------------------------------------------------------------------------
Comments

4 students each having 2 letter grades
*/
#include <iostream>				// for cin, cout, endl
using namespace std;

//prototype declerations


int main(){
    int numRows = 10;
    int numCols = 10;
 
    int product[numRows][numCols]{}; // Declare a 10x10 array. {} means an empty cell
 
    // Calculate a multiplication table
    for (int row{ 1 }; row < numRows; ++row)
    {
        for (int col{ 1 }; col < numCols; ++col)
        {
            product[row][col] = row * col;
        }
     }
 
    // Print the table
    for (int row{ 1 }; row < numRows; ++row)
    {
        for (int col{ 1 }; col < numCols; ++col)
        {
            cout << product[row][col] << '\t';
        }
        cout << '\n';
    }
    return 0;
}
