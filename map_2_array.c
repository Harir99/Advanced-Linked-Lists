#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "sortedList.h"

Sorted_list * map_2_array( Sorted_list * list,Sorted_list * list2, value_t (*fn_ptr)(value_t,value_t),int order){
  int i = 0;
  Node * node = list->head;
  Node * node2 = list2->head;
  Sorted_list * new_list = create_list();
  if( order == INSERTED_ORDER){

    for ( i = 0; i < size(list) ; i++) {
      append ( new_list, fn_ptr ( node->value ,node2->value),node->key );
      node2 = node2->next;
      node = node->next;
    }
  }
  Node * nodeSort= list->head_sort;
  Node * node2Sort= list2->head_sort;
  if( order == SORTED_ORDER){
    for ( i = 0; i < size(list) ; i++) {
      append ( new_list, fn_ptr ( nodeSort->value ,node2Sort->value),nodeSort->key );
      node2Sort = node2Sort->sort;
      nodeSort = nodeSort->sort;
    }
  }

  return new_list;
}
