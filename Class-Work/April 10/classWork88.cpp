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

struct Point3d
{
    double x;
    double y;
    double z;
};
 
Point3d getZeroPoint();
 
int main()
{
    Point3d zero = getZeroPoint();
 
    if (zero.x == 0.0 && zero.y == 0.0 && zero.z == 0.0)
        cout << "The point is zero\n";
    else
        cout << "The point is not zero\n";
 
    system("PAUSE");
    return 0;
}
Point3d getZeroPoint()
{
    Point3d temp = { 0.0, 0.0, 0.0 };
    return temp;
}
