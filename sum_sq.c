#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "sortedList.h"
value_t sum_sq(value_t userValue, int value){
  Sorted_list* list = create_list();
  Node*node = list->head;
  value += (userValue * userValue);
 return (node != NULL) ? value : 0;
}
