#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "sortedList.h"


Sorted_list* diff(Sorted_list * list,Sorted_list * list2, int order){
   Sorted_list * new_list = create_list();
  if( size(list) == size(list2)){
    new_list = map_2_array(list,list2,deduct,order);
  }
  else {
    printf("Error - Sizes are not equal! Thus, cannot find diff\n" );

  }
 return new_list;
}
