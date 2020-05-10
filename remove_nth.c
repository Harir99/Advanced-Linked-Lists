#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortedList.h"

int remove_nth (Sorted_list* userSortedList, value_t* userValue, Key_t* userKey,int n,int order)
{
  if( n >= size(userSortedList)){
    printf("FAILED,n >= size where size = %d\n",size(userSortedList));
    return FAIL;
  }
  if(order == INSERTED_ORDER){
    Node* tempNode = nth_node(userSortedList->head,n);
    rmX_nNodeFromList(userSortedList, tempNode);
    *userValue = tempNode->value;
    *userKey = tempNode->key;
    printf("%lf %d\n",tempNode->key,tempNode->value );
    free((Node*)tempNode);

  }
  if (order == SORTED_ORDER){
    Node* tempNode = nth_node(userSortedList->head_sort,n);
    rmX_nNodeFromList(userSortedList, tempNode);
    *userValue = tempNode->value;
    *userKey = tempNode->key;
    free((Node*)tempNode);
  }

    return SUCCESS;
}
