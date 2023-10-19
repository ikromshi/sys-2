#include <stdio.h>
#include <stdlib.h>

extern int factorial(int n);
int main(int argc, char *argv[]) {
	int n, i=0, x;
	if (argc==1) {
		printf("Enter value of n: ");
		scanf("%d", &n);
	}
	else {
		n = atoi(argv[1]);
	}

	if (n>=0) {
		while (n>=0) {
			x = factorial(i);
			printf("Factorial (%d)=%d\n", i, x);
			i++;
			n--;
		}
	}
	else {
		printf("Fact of a negative is undefined\n");
	}
}
