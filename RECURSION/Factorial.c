#include<stdio.h>

int f(int n) {

	// base case

	if (n == 0) {
		// compute 0!
		return 1;
	}

	// recursive case

	// 1. call recursion to compute n-1!

	int A = f(n - 1);

	return n * A;

}

int main() {

	int n = 4;

	printf("%d\n", f(n));

	return 0;
}