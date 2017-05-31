// Simple C++ program to find a partition point in
// an array
//#include<bits/stdc++.h>

#include <iostream>
using namespace std;
// http://www.geeksforgeeks.org/find-a-partition-point-in-array/


// Returns an element that has all the element to its
// left smaller and to its right greater
void FindElement(int a[], int n)
{

	int curMax = a[0];
	int foundAt = -1;

	for (int i=1; i<n; i++) {

		if (foundAt != -1 && a[i] <= a[foundAt]) {
			foundAt = -1;	
		} else if (a[i] > curMax && foundAt == -1 && i != (n-1)) {
			foundAt = i;
			curMax = a[i];
		} else if (a[i] > curMax) {
			curMax = a[i];
		}
	}

	if (foundAt == -1) {
		cout << "Nothing found"<<endl;	
	} else {
		cout << "found at "<< a[foundAt]<<endl;	
	}
}

// driver program to test above function
int main()
{
    int A[] = {4, 3, 2, 5, 2, 6, 8 ,6 , 7 } ;
    // int A[] = {4, 3, 2, 1 } ;
    //int A[] = {5, 6, 2, 8, 10, 9, 8} ;
    int n = sizeof(A)/sizeof(A[0]);
    FindElement ( A , n ) ;
    return 0;
}