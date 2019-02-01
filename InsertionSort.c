#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void InsertionSort(int* numbers, int len) {
  int temp = 0;
  for ( int i = 0 ; i < len; i++) {
    if ( numbers[i] > numbers[i+1] )  {
      temp = numbers[i+1];
      numbers[i+1] = numbers[i];
      numbers[i] = temp;
    }
  }
}

int main(int len, char** array)  {
  if ( len < 2) {
    printf("Please enter the size of your array behind the program name\n");
    printf("./InsertionSort <ArrayLength>\n\n");
    exit(1);
  }

  int arrayLength = atoi(array[1]);

  int* numbers = calloc(arrayLength, sizeof(int));
  srand((unsigned int) time(NULL));

  for ( int i = 0; i < arrayLength; i++) {
    numbers[i] = rand() % 100;
    printf("%d:\t%d\n", i, numbers[i]);
  }

  InsertionSort(numbers, arrayLength);
  for ( int i = 0 ; i < arrayLength; i++) {
    printf("%d\n", numbers[i]);
  }

  free(numbers);
  return 0;
}
