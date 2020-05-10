#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "sortedList.h"

Sorted_list* square(Sorted_list * list){
 return map(list,squares);
}
