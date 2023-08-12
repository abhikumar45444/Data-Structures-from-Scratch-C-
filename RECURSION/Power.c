#include<stdio.h>

// time : O(n)

// int f(int x, int y) {

// 	// base case
// 	if (y == 0) {
// 		// compute x^0
// 		return 1;
// 	}

// 	// recursive case

// 	// 1. call recursion to compute x^y-1 i.e. call recursion for the result of multiplying x, y-1 times

// 	int A = f(x, y - 1);

// 	return x * A;

// }


// time : O(logn)

int f(int x, int y) {

	// base case
	if (y == 0) {
		// compute x^0
		return 1;
	}

	// recursive case

	// 1. call recursion to compute x^(y/2)

	int A = f(x, y / 2);

	if (y % 2 == 0) {
		// y is even
		return A * A;
	}

	// y is odd
	return A * A * x;

}

int main() {

	int x = 3;
	int y = 6;

	printf("%d\n", f(x, y));

	return 0;
}