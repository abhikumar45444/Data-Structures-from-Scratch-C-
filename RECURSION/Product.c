#include<stdio.h>

int f(int x, int y) {

	// base case

	if (y == 0) {
		// compute x*0
		return 0;
	}

	// recursive case

	// 1. recursively compute x*y-1 i.e. add 'x' (y-1) times i.e. call recursion to find x*(y-1)

	// int A = f(x, y - 1);

	return x + f(x, y - 1);

}

int main() {

	int x = 7;
	int y = 2;

	printf("%d\n", f(n));

	return 0;
}