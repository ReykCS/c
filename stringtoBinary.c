#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ressources.h"

int convertChartoBinary(char buchstabe) {
  int ascii = (int) buchstabe;
  ascii = convertDezimaltoBinary(ascii);
  printf("%c:\t%d\n", buchstabe, ascii);
  return ascii;
}

int* convertStringtoBinary(char* string)  { // GIBT ÜBERSETZTEN STRING ALS INT ARRAY MIT BUCHSTABEN ALS DUALzAHL ZURÜCK
  int len = strlen(string);
  int* numbers = calloc(len, sizeof(int));
  for ( int i= 0 ; i < strlen(string); i++)  {
    numbers[i] = convertChartoBinary(string[i]);
  }
  return numbers;
}

int main(int len, char** string)  {
  if ( len < 3) {
    printf("Gib ein oder mehrere Wörter hinter dem Programmnamen ein\n");
    printf("\n\t./stringtoBinary <Zu übersetzende Wörter>\n\n");
    exit(1);
  }

  printf("\nDer eingegebenen Wörter sind:\t");
  for ( int i = 1; i < len; i++)  {
    printf("%s ", string[i]);
  }
  printf("\n\nÜbersetzt:\n\n");

  for (int i = 1; i < len; i++) {
    convertStringtoBinary(string[i]);
    printf("\n");
  }
  return 0;
}
