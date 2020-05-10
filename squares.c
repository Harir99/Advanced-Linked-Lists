#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "sortedList.h"

value_t squares(value_t userValue){
  Sorted_list * list = create_list();
  Node* node = list->head;
 return (node != NULL) ? userValue * userValue: 0;
}
