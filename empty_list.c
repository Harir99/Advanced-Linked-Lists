#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortedList.h"

void empty_list(Sorted_list* userSortedList)
{
    userSortedList->tail_sort = NULL;
    userSortedList->tail = NULL;
    userSortedList->head = NULL;
    userSortedList->head_sort = NULL;
    userSortedList->prev_tail_sorted = NULL;
    userSortedList->prev_tail = NULL;
    userSortedList->size = 0;
    printf("empty:             size = %d",userSortedList->size);
}
