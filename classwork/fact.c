#include <stdio.h>

int main() {
	int rslt = 1, n = 5;
	while (n>0) {
		rslt = rslt * n--;
	}
	printf("%d", rslt);
}
