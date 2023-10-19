#include <stdio.h>
#include <stdlib.h> // need for atoi
#include <string.h>

#define SIZE 32


int main(){
  char state[SIZE];
  char city[SIZE];
  int i = 0;
  char zipString[SIZE];
  int zip;

   while (i < 3){
      printf("Enter a city: ");
      fgets(city, SIZE, stdin);

      printf("Enter a state: ");
      fgets(state, SIZE, stdin);

      printf("Enter a zip code: ");
      fgets(zipString, SIZE, stdin);

      zip = atoi(zipString);

      printf("\nYour city:  %s", city);
      printf("Your state:  %s", state);
      printf("Your Zip Code:  %d\n", zip);

      i++;
   }   // end while

  return 0;

}   // end main
