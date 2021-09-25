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

int main()
{
	
string str = "Welcome to Ally Baba Buger Shop";

/* 1. The length() function OR the size() function return an integer 
which is the size of the string.*/

cout << str << endl;
cout << " length(): "  << str.length() << endl;
cout << " size(): "   << str.size() << endl;

/* 2. The find function will return an integerrepresenting the 
FIRST OCCURRENCE of a certain string, here the functions argument.*/

cout << " find(\"to\"): " << str.find("to") << " position" << endl;

/* 3. The substr() function "substring" will return a string 
which starts and ends at a determined index(es), the arguments of the function.  
If only 1 argument is given, it will begin at that index and continue all the way to end.*/

cout << " substr(0,2): " << str.substr(0,2) << endl;
cout << " substr(1,5): " << str.substr(1,5) << endl;
cout << " substr(4): "   << str.substr(4) << endl;

/* 4. The insert() function will look at a designated index and 
insert the string, as the second parameter, in that place. */

cout << " insert(\"Mr.\") at 0 location " << str.insert(10," Mr.") << endl;

/* 5. The append() function will add the string argument to the END of the string.*/

str.append(" - $ Deal Day");
cout << " added \" - $ Deal Day\": " << str << endl;
    
    system("PAUSE");
    return 0;
}
