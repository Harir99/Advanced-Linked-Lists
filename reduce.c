#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "sortedList.h"

value_t reduce(Sorted_list * list, value_t (*reduce)(value_t, value_t), value_t init,int order ){
int i = 0;
 Node * node = list->head;
 value_t result = init;
 if( order == INSERTED_ORDER){
     for ( i = 0; i < size(list) ; i++) {
       result = reduce( node->value, result );
       node = node->next;
     }
 }
 Node * nodeSort= list->head_sort;
  if( order == SORTED_ORDER){
    int j = 0;
    for ( j = 0; j < size(list) ; j++){
         result = reduce( nodeSort->value, result );
         nodeSort = nodeSort->sort;
       }
  }
 return result;
}
