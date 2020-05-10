#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "sortedList.h"
value_t  map_reduce ( Sorted_list * list, value_t (*map)(value_t),value_t (*reduce)(value_t, value_t),value_t init,int order){
int i = 0;
  Node * node = list->head;
  Sorted_list * new_list = create_list();
  Node * new_node = new_list->head;
  value_t result = init;
  if( order == INSERTED_ORDER){

    for ( i = 0; i < size(list) ; i++) {
      append ( new_list, map ( node->value ),node->key );
      result = reduce( new_node->value, result );
      node = node->next;
    }
  }
  Node * nodeSort= list->head_sort;
  Node * new_nodeSort = new_list->head_sort;
  if( order == SORTED_ORDER){
    for ( i = 0; i < size(list) ; i++) {
      append ( new_list, map ( nodeSort->value ),nodeSort->key );
      result = reduce( new_nodeSort->value, result );
      nodeSort = nodeSort->sort;
    }
  }
  return result;
}
