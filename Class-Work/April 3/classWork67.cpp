/* 
Name:     		Logan Falkenberg
Date: 			March 13 2021
Assignment #:	classwork55
Status: 		Completed
Language: C++
-------------------------------------------------------------------------
Comments

BUBBLE SORT
*/
#include<iostream>
using namespace std;

// prototypes
void swapping(int &, int &);
void display(int *, int); // * means pointer, storing the memory address of the array
void bubbleSort(int *, int);

int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];     //create an array with given number of elements
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
	 }
   cout << "Array before Sorting: ";
   display(arr, n);
   bubbleSort(arr, n);
   cout << "Array after Sorting: ";
   display(arr, n);
} // end of main()

// Uses bubblesort to rearrange the elements in the array
void bubbleSort(int *array, int size) {
   for(int i = 0; i<size; i++) {
      int swaps = 0;         //flag to detect any swap is there or not
      for(int j = 0; j<size-i-1; j++) {
         if(array[j] > array[j+1]) {       //when the current item is bigger than next
            swapping(array[j], array[j+1]);
            swaps = 1;    //set swap flag
         }
      }
      if(!swaps)
         break;       // No swap in this pass, so array is sorted
   }
} // end of bibbleSort()

void swapping(int &a, int &b) {      //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}
// Displays the data
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
} // end 


