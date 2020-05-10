#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortedList.h"

void free_list (Sorted_list* sorted_list){
  Node * new_head = sorted_list->head;
  Node *old_node = NULL;
  while(new_head != NULL){
    old_node = new_head;
    new_head = new_head->next;
    free(old_node);
  }
}
