#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortedList.h"
Node * nth_node ( Node * node , int n) {
  int i = 0;
  for ( i = 1 ; i < n && node != NULL && node->next != NULL ; i++ )
  {
    node = node->next;
  }
return node;
}
