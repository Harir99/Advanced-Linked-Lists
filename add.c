#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "sortedList.h"


value_t add(value_t userValue, int number){
  Sorted_list * list = create_list();
  Node* node = list->head;
 return (node != NULL) ? userValue + number: 0;
}
