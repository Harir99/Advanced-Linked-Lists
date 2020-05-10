#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Charlist.h"

void print_list_char (Sorted_list* userSortedList)
{
  Node* sortNodeIdx = userSortedList->head; //start at head
  printf("print all: Insertion Order\n");
  while (sortNodeIdx != NULL)     //Loop through insertion sorted list until end
  {
      printf("%2d %s\n",sortNodeIdx->key, sortNodeIdx->value);
      sortNodeIdx = sortNodeIdx->next;
  }
  printf("\n");
}
