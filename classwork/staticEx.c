#include <stdio.h>

extern int squareX(int X);

int main() {
	int x = 0, y = 0;

	printf("Enter an integer:\n");
	scanf("%d", &x);

	y = squareX(x);
	printf("x = %d and x squared = %d\n", x, y);
	return 0;
}
