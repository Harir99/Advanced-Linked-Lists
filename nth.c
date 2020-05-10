#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortedList.h"
int nth  ( Sorted_list * list , int n, value_t*  value,Key_t* key,int order) {
int result = FAIL;
Node * node = nth_node(list->head, n);
  if(order == INSERTED_ORDER){
    if ( node != NULL )
   {
     *value = node->value;
     *key = node->key;
     result = SUCCESS;
   }
  }
  else if(order == SORTED_ORDER){
    if ( node != NULL )
   {
     *value = node->value;
     *key = node->key;
     result = SUCCESS;
   }
  }

  printf("%lf %d\n",node->key,node->value );
  printf("\n");
return result;
}
