#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "sortedList.h"
Sorted_list * map ( Sorted_list * list, value_t (*fn_ptr)(value_t) ){
  int i = 0;
 Node * node = list->head;
 Sorted_list * new_list = create_list();
 for ( i = 0; i < size(list) ; i++) {
   append ( new_list, fn_ptr ( node->value ),node->key );
   node = node->next;
 }
 return new_list;
}
