#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "sortedList.h"

value_t map_2_reduce ( Sorted_list * list,Sorted_list * list2, value_t (*map)(value_t,value_t),value_t (*reduce)(value_t,value_t),int order){
  int i = 0;
  Node * node = list->head;
  Node * node2 = list2->head;
  Sorted_list * new_list = create_list();
  value_t result = order;
  if( order == INSERTED_ORDER){
    for ( i = 0; i < size(list) ; i++) {
      append ( new_list, map ( node->value,node2->value),node->key );
      Node * new_node = new_list->head;
      result = reduce( new_node->value, result);
      node = node->next;
    }
  }
  Node * nodeSort= list->head_sort;
  Node * node2Sort= list2->head_sort;
  if( order == SORTED_ORDER){
    for ( i = 0; i < size(list) ; i++) {
      append ( new_list, map ( nodeSort->value,node2Sort->value),nodeSort->key );

      Node * new_nodeSort = new_list->head_sort;
      result = reduce( new_nodeSort->value, result);
      nodeSort = nodeSort->sort;
    }
  }
  return result;
}
