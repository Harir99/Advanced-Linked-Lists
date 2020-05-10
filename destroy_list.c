#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortedList.h"


void destroy_list (Sorted_list* userSorted_list)
{
    empty_list(userSorted_list);
    free((Sorted_list*)userSorted_list);
}
