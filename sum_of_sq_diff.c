#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "sortedList.h"

value_t sum_of_sq_diff(Sorted_list * list,Sorted_list * list2, int order){
 return map_2_reduce(list,list2,sum_sq,deduct,order);
}
