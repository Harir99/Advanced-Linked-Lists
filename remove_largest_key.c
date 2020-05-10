#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortedList.h"
int remove_largest_key (Sorted_list* userSortedList, value_t* userValue, Key_t* userKey)
{
    //find the smallest key
    Node* largestKey = userSortedList->tail_sort;

    rmX_nNodeFromList(userSortedList, largestKey);
    *userValue = largestKey->value;
    *userKey = largestKey->key;
    free((Node*)largestKey);

    return SUCCESS;
}
