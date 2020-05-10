#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "sortedList.h"

value_t deduct(value_t userValue,int number){
  Sorted_list* list = create_list();
  Node* node = list->head;
 return (node != NULL) ? number - userValue : 0;
}
