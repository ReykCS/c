
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "input_merge_sort.h"

void merge(int* array, int first, int middle, int last)
{
  int* alternativeArray = malloc((last-first+1) * sizeof(int));
  int k = first;
  int m = middle + 1;
  int i = 0;

  while (k <= middle && m <= last){
      if(array[k] <= array[m]){
          alternativeArray[i++] = array[k++];
      } else {
          alternativeArray[i++] = array[m++];
      }
  }
  while (k <= middle){
      alternativeArray[i++] = array[k++];
  }
  while (m <= last){
      alternativeArray[i++] = array[m++];
  }
  int j = 0;
  while (j < i){
      array[first + j] = alternativeArray[j];
      j++;
  }
  free(alternativeArray);
}

void merge_sort(int* array, int first, int last)
{
    if(first < last) {
        int middle = ((float) first + last) / 2;
        merge_sort(array, first, middle);
        merge_sort(array, middle + 1, last);
        merge(array, first, middle, last);
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
