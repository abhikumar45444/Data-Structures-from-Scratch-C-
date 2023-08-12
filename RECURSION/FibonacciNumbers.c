#include<stdio.h>

int f(int n) {

	// base case

	// if (n == 0) {
	// 	// compute 0th fibonacci no.
	// 	return 0;
	// }

	// if (n == 1) {
	// 	// compute 1st fibonacci no.
	// 	return 1;
	// }

	if (n == 0 || n == 1) {
		return n;
	}

	// recursive case

	// 1. call recursion for the value of n-1th fibonacci no.
	int A = f(n - 1);

	// 2. call recursion for the value of n-2th fibonacci no.
	int B = f(n - 2);

	return A + B;

}

int main() {

	int n = 7;

	printf("%d\n", f(n));

	return 0;
}