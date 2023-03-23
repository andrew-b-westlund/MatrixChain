// File: Matrix Chain Optimization
// Author: Andrew Westlund
// Date: 11/22/2021
// Purpose: Given a chain of matrices <A1, A2,..., An>, where Ai has 
// dimensions p[i - 1] * p[i], fully parenthisize the product A1*A2*...*An 
// in a way that minimizes scalar operations.
// Implements dynamic programming, two-dimensional matrices, and recursion.

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>

using namespace std;

void matrixChainOrder(int *p, int **&m, int **&s, int n) {
	int a, i, j, k, l, q;
		
	for (a = 0; a < n; a++) {
		m[a][a] = 0;
	}
	
	// For each chain length (and a chain length less than 2 would not make sense)s
	for (l = 2; l <= n; l++) {
		// For each subproblem starting from Ai to the last array with enough room
		// for a chain with length l
		for (i = 0; i < (n - l + 1); i++) {
			j = (i + l - 1);		// Set j to be the end index of the subproblem
			m[i][j] = INT_MAX;		// Set the default cost to infinity
		
			// For each position starting from i and ending before j (For each subproblem)
			for (k = i; k <= (j - 1); k++) {
				// q equals the cost of computing the matrices Ai to Ak plus the cost
				// of computing Ak+1 to Aj plus the cost of multiplying them together
				q = m[i][k] + m[k+1][j] + (p[i] * p[k + 1] * p[j + 1]);
				// If that cost is less than the cost currently stored
				if (q < m[i][j]) {
					m[i][j] = q;	// Set the cost to q
					s[i][j] = k + 1;// Set the index of the optimal split from Ai to Aj to k
				}
			}
		}
	}
}


void printOptParens(int **s, int i, int j) {
	// If there are no more subsolutions to split up
	if (i == j) {
		// Print out the array
		cout << "A" << (i + 1);
	
	// If there are more subsolutions to split up
	} else {
		cout << "(";
		// Recurse with the subsolution from the beginning to the splitting index
		printOptParens(s, i, s[i][j] - 1);
		// Recurse with the subsolution starting from after the splitting index to the end
		printOptParens(s, s[i][j], j);
		cout << ")";
	}
}


main(int argc, char *argv[]) {
	// Create an array of matrix dimensions
	int p[7] = {10, 20, 15, 5, 8, 17, 4};
	//int p[7] = {30, 35, 15, 5, 10, 20, 25};
	// Find the length of the array
	int pLength = sizeof(p) / sizeof(p[0]);
	// Set n to be pLength - 1
	int n = pLength - 1;
	// Stores the minimal number of scalar operations for matrices
	int **m = new int*[n];
	// Stores the order in which the optimal parenthisization can be found
	int **s = new int*[n - 1];
	
	// Initialize the two dimensional array
	for (int i = 0; i < n; i++) {
		m[i] = new int[n];
		// s has one less row than columns
		if (i != n - 1) {
			s[i] = new int[n];
		}
	}
	
	// Pass the array of dimensions, m and s(which can be changed) and n
	// to put the appropriate values in m and s
	matrixChainOrder(p, m, s, n);
	
	
	cout << "The correct optimization of the matrix multiplication is : ";
	printOptParens(s, 0, n - 1);
	
	cout << "\n\nThe minimum total operations needed is : " << m[0][n - 1] << endl;
}