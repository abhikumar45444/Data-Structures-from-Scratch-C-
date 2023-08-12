#include<stdio.h>

// f(n) : print nos. from n to 1 in the decreasing order
// f(0) : print nos. from 0 to 1 in the decreasing order

void f(int n) {

	// base case

	if (n == 0) {
		return;
	}

	// recursive case

	printf("%d ", n);

	// 1. call recursion to print nos. from n-1 to 1 in the decreasing order

	f(n - 1);

}

int main() {

	int n = 5;

	f(n);

	return 0;
}