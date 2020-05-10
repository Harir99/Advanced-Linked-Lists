#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortedList.h"

int remove_smallest_key (Sorted_list* userSortedList, value_t* userValue, Key_t* userKey)
{
    //find the smallest key
    Node* smallestKey = userSortedList->head_sort;

    rmX_nNodeFromList(userSortedList, smallestKey);
    *userValue = smallestKey->value;
    *userKey = smallestKey->key;
    free((Node*)smallestKey);

    return SUCCESS;
}
