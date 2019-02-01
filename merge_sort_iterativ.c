
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "input_merge_sort.h"


void merge(int* array, int first, int middle, int last)
{

  int* tmpArray = malloc((last-first+1) * sizeof(int));
  int i = first;
  int j = middle + 1;
  int arrayCounter = 0;
  while (i <= middle && j <= last){
      if(array[i] <= array[j]){
          tmpArray[arrayCounter++] = array[i++];
      } else{
          tmpArray[arrayCounter++] = array[j++];
      }
  }
  while (i <= middle){
      tmpArray[arrayCounter++] = array[i++];
  }
  while (j <= last){
      tmpArray[arrayCounter++] = array[j++];
  }
  arrayCounter = 0;
  for(int counter = first; counter <= last; counter++){
      array[counter] = tmpArray[arrayCounter++];
  }
  free(tmpArray);
}

void merge_sort(int* array, int first, int last)
{

  int step = 1;
  while (step <= last){
      int left = 0;
      while (left <= last-step){
          int middle = left + step - 1;
          if(middle > last) {
              middle = last;
          }
          int right = left + 2 * step - 1;
          if(right > last) {
              right = last;
          }
          merge(array, left, middle, right);
          left = left + 2 * step;
      }
      step *= 2;
  }
}

int main (int argc, char *argv[])
{
    if (argc!=3){
        printf ("usage: %s <maximale anzahl>  <dateipfad>\n", argv[0]);
        exit(2);
    }
    
    char *filename = argv[2];

    int* array = malloc(sizeof(int) * atoi(argv[1]));

    int len = read_array_from_file(array, atoi(argv[1]), filename);

    printf("Eingabe:\n");
    print_array(array, len);

    merge_sort(array, 0, len-1);

    printf("Sortiert:\n");
    print_array(array, len);

    free(array);
    return 0;
}
