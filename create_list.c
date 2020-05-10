#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortedList.h"

Sorted_list* create_list(){
  Sorted_list* new_list = malloc(sizeof(Sorted_list));
  if( new_list != NULL){
      new_list->head = NULL;
      new_list->head_sort = NULL;
      new_list->tail = NULL;
      new_list->tail_sort = NULL;
      new_list->prev_tail = NULL;
      new_list->prev_tail_sorted = NULL;
      new_list->size = 0;

  }
  return new_list;
}
