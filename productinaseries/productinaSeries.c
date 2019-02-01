#include <stdio.h>
#include <stdlib.h>

#define XMAX 50
#define YMAX 20

#define SERIESLENGTH 13

#define KRED  "\x1B[31m"
#define KNRM  "\x1B[0m"

void read_file(char* filename, int* numbers)  {
  FILE* fp = fopen(filename, "r");

  if (fp == NULL) {
    printf("Datei konnte nicht geöffnet werden.\n");
    exit(1);
  }

  char temp;

  int x = 0;

  while( (temp = fgetc(fp)) != EOF)  {
    if ( temp == '\n' ) {
      continue;
    }
    numbers[x] = atoi(&temp);
    x++;
  }
  fclose(fp);
  return;
}

long getProduct(int* numbers, int*loc)  {
  long maxProduct = 1;
  for ( int i = 0; i < YMAX * XMAX; i++) {
    long product = 1;
    for ( int x = 0; x < SERIESLENGTH; x++)  {
      product *= numbers[i+x];
    }
    if ( product > maxProduct ) {
      maxProduct = product;
      *loc = i;
    }
  }
  return maxProduct;
}

void printArray(int* numbers, int y)  {
  for ( int i = 0 ; i < YMAX * XMAX; i++)  {
    if ( i % 50 == 0 ) printf("\n");
    if ( i == y ) printf("%s", KRED);
    if ( i == y + SERIESLENGTH ) printf("%s", KNRM);
    printf("%d", numbers[i]);
  }
  printf("\n");
  return;
}

int main()  {

  int * numbers = calloc(YMAX * XMAX, sizeof(int*));
  if ( numbers == NULL)  {
    printf("Keinen Speicher reserviert.\n");
    exit(1);
  }

  read_file("NumberGrid.txt", numbers);

  int productLoc = 0;

  long product = getProduct(numbers, &productLoc);

  printf("\n\nBiggest product in a series of %d numbers:\t%lu\n\n", SERIESLENGTH, product);
  printf("\nProduct Location:\t%d\n", productLoc);

  printArray(numbers, productLoc);

  printf("\n");

  free(numbers);

  return 0;
}
