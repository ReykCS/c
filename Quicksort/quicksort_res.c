/* === INTROPROG ABGABE ===
 * Blatt 10, Aufgabe 1
 * Tutorium: t21
 * Gruppe: g18
 * Gruppenmitglieder:
 *  - Erik Rygiel
 *  - Reyk Carstens
 * ========================
 */

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "quicksort.h"

/*****************************************************
 * Die benoetigten structs findet Ihr in quicksort.h *
 *****************************************************/

void init_list(list* mylist)
{
  // HIER Liste initialisieren
  //mylist = malloc(sizeof(list));
  mylist->first = NULL;
  mylist->last = NULL;
}



// Diese Funktion fügt Listenelemente an die Liste an
void insert_list(list_element* le, list* mylist)
{
    // HIER Code einfügen
  // printf("liste: %s, %d\n", le->password, le->count);
  if ( mylist->first == NULL )  {
    mylist->first = le;
    mylist->last = le;
    return;
  }
  mylist->last->next = le;
  mylist->last = le;
  mylist->last->next = NULL;
}

// Speicher für Listenelemente wieder freigeben
void free_list(list* mylist)
{
  if ( mylist->first == NULL )  {
    return;
  }
  free(mylist->first->password);
  list_element* temp = mylist->first;
  mylist->first = mylist->first->next;
  free(temp);
  free_list(mylist);
}


// Namen, Zahlen Paare in Liste einlesen
void read_data(char* filename, list* mylist)
{
		// HIER Code einfügen:
        // * Speicher allozieren
        // * Daten in list_element einlesen
        // * insert_list benutzen, um list_element in Liste einzufügen
  FILE *fp;

  fp = fopen(filename, "r");
  if (fp == NULL)
        return;
  int c = 0;
  char* line = calloc(50, sizeof(char));
  int count = 0;
  while ( (c = fgetc(fp)) ) {
    if ( c == EOF ) break;
    if ( (char) c == '\n' ) {
      char* token = strtok(line, " ");
      char* password = calloc((strlen(token)+1), sizeof(char));
      int number = 0;
      strcpy(password, token);
      token = strtok(NULL, " ");
      while(token != NULL ) {
        if ( atoi(token) != 0 ) {
          number = atoi(token);
          break;
        }
        char* temp = malloc((strlen(password) + 1) * sizeof(char));
        strcpy(temp, password);
        free(password);
        password = calloc((strlen(temp) + strlen(token) + 2), sizeof(char));
        strcat(password, temp);
        strcat(password, " ");
        strcat(password, token);
        free(temp);
        break;
        token = strtok(NULL, " ");
      }
      free(line);
      line = calloc(50, sizeof(char));
      count = 0;
      list_element* newElem = malloc(sizeof(list_element));
      newElem->password = malloc((strlen(password)+1) * sizeof(char));
      strcpy(newElem->password, password);
      newElem->count = number;
      newElem->next = NULL;
      insert_list(newElem, mylist);
      free(password);
      continue;
    }
    line[count] = (char) c;
    count++;
  }
  free(line);
  fclose(fp);
}

// Liste teilen. Teillisten werden in left und right zurück gegeben
list_element* partition( list* input, list* left, list* right )
{
    // HIER Code einfügen:
    // parition() Funktion implementieren
    list_element* pivot = input->first;
    list_element* next = input->first->next;
    while(next != NULL ) {//|| next == input->last )  {
      list_element* temp = next->next;
      if ( next->count < pivot->count ) {
        insert_list(next, left);
      } else {
        insert_list(next, right);
      }
      next = temp;
    }
    return pivot;
}

// Hauptfunktion des quicksort Algorithmus
void qsort_list(list* mylist)
{
    // HIER Code einfügen
    if ( mylist->first == mylist->last || mylist->first == NULL || mylist->last == NULL)  {
      return;
    }
    list *left = malloc(sizeof(list));
    init_list(left);
    list *right = malloc(sizeof(list));
    init_list(right);
    list_element* pivot = partition(mylist, left, right);
    qsort_list(left);
    qsort_list(right);

    if ( left->first == NULL )  {
      mylist->first = pivot;
    } else {
      mylist->first = left->first;
      left->last->next = pivot;
    }
    if ( right->first == NULL ) {
      mylist->last = pivot;
    } else {
      pivot->next = right->first;
      mylist->last = right->last;
    }
    free(left);
    free(right);
}

// Liste ausgeben
void print_list(list* mylist)
{
    // HIER Code einfügen:
    // * Laufe über die list_element in mylist und gebe sie aus.
    list_element *temp = mylist->first;
    while( temp != NULL ) {
      printf("%s %d\n", temp->password, temp->count);
      temp = temp->next;
    }
}
