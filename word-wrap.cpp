#include <iostream>
using namespace std;
// #define INF INT_MAX;
int INF = 111111;
// http://www.geeksforgeeks.org/find-a-partition-point-in-array/


// utility to print 1d array
void print1dArray(int arr[], int m) {

	for(int i=0; i<m; i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int printSolution (int p[], int n) {
    int k;
    if (p[n] == 1)
        k = 1;
    else
        k = printSolution (p, p[n]-1) + 1;
    printf ("Line number %d: From word no. %d to %d \n", k, p[n], n);
    return k;
}

// l[] represents lengths of different words in input sequence. For example, 
// l[] = {3, 2, 2, 5} is for a sentence like "aaa bb cc ddddd".  n is size of 
// l[] and M is line width (maximum no. of characters that can fit in a line)
void solveWordWrap (int l[], int n, int M) {

    // For simplicity, 1 extra space is used in all below arrays 
 
    // extras[i][j] will have number of extra spaces if words from i 
    // to j are put in a single line
    int extras[n+1][n+1];  
 
    // lc[i][j] will have cost of a line which has words from 
    // i to j
    int lc[n+1][n+1];
  
    // c[i] will have total cost of optimal arrangement of words 
    // from 1 to i
    int c[n+1];
 
    // p[] is used to print the solution.  
    int p[n+1];
 
    int i, j;
 
    // calculate extra spaces in a single line.  The value extra[i][j]
    // indicates extra spaces if words from word number i to j are
    // placed in a single line
    for (i = 1; i <= n; i++)
    {
        extras[i][i] = M - l[i-1];
        for (j = i+1; j <= n; j++)
            extras[i][j] = extras[i][j-1] - l[j-1] - 1;
    }
 
 	// print2dArray(&extras, n+1, n+1);
    cout<<"start print extras space 2d array"<<endl;
 	for(int i=0; i<=n; i++) {
		for (int j=0; j<=n; j++) {
			cout<<extras[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"end print extras space 2d array"<<endl;

    // Calculate line cost corresponding to the above calculated extra
    // spaces. The value lc[i][j] indicates cost of putting words from
    // word number i to j in a single line
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (extras[i][j] < 0) {
                lc[i][j] = INF;
            } else if (j == n && extras[i][j] >= 0) {
                lc[i][j] = 0;
            } else {
                lc[i][j] = extras[i][j]*extras[i][j];
            }
        }
    }
    // print2dArray(lc, n+1, n+1);
    cout<<"start print cost array space 2d array"<<endl;
    for(int i=0; i<=n; i++) {
		for (int j=0; j<=n; j++) {
			cout<<lc[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"start print cost array space 2d array"<<endl;

	// Calculate minimum cost and find minimum cost arrangement.
    // The value c[j] indicates optimized cost to arrange words
    // from word number 1 to j.
    c[0] = 0;
    for (j = 1; j <= n; j++)
    {
        c[j] = INF;
        for (i = 1; i <= j; i++)
        {
        	if (c[i-1] != INF && lc[i][j] != INF && (c[i-1] + lc[i][j] < c[j])) {
        		c[j] = c[i-1] + lc[i][j];
        		p[j] = i;
        	}
        }
    }
 
 	print1dArray(c, n+1);
 	print1dArray(p, n+1);
    printSolution(p, n);
}


 
// Driver program to test above functions
int main() {
    int l[] = {3, 2, 2, 5};
    int n = sizeof(l)/sizeof(l[0]);
    int M = 6;
    solveWordWrap (l, n, M);
    return 0;
}