#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "sortedList.h"

value_t mult(value_t userValue, int value){
  Sorted_list* list = create_list();
  Node*node = list->head;
 return (node != NULL) ? userValue * value : 0;
}
