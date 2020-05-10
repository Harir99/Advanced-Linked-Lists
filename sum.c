#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "sortedList.h"
value_t sum(Sorted_list * list,int order){
 return reduce(list, add, 0,order);
}
