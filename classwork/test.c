#include <stdio.h>

struct addr {
	char street[32];
	char city[10];
};

struct student {
	char name[32];
	int year;
	struct addr home;
};

int main() {
	char name[50];
	int num[5];
	int *x = 0;
	int y;
	x = &y;
	struct student ikrom;
	struct student *s2;
	s2 = &ikrom;


	printf("Enter your age: \n");
	scanf("%d", &(*s2).year);
	printf("What is your name?:\n");
	scanf("%s", (*s2).name);

	printf("Enter your street address:\n");
	scanf("%s", (*s2).home.street);
	printf("Enter your city name:\n");
	scanf("%s", (*s2).home.city);

	/**
	printf("Enter another age:\n");
	scanf("%d", &s2.year);
	printf("Enter another name:\n");
	scanf("%s", s2.name);
	*/

	/**
	printf("Enter 5 numbers:\n");
	
	for (int i=0; i<5; i++) {
		printf("Enter a number d: \n");
		scanf("%d", (num+i)); // as opposed to &num[i];
	}
	*/

	printf("Nice to meet you %s. You are %d years old.\n", (*s2).name, (*s2).year);
	printf("Your street name is %s. And your city name is: %s\n", (*s2).home.street, (*s2).home.city);

	/**
	for (int i=0; i<5; i++) {
		printf("%d\n", *(num+i)); // as opposed to num[i];
	}
	*/
	return 0;
}
