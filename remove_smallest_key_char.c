#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Charlist.h"


int remove_smallest_key_char (Sorted_list* userSortedList, value_t* userValue, Key_t* userKey)
{
    //find the smallest key
    Node* smallestKey = userSortedList->head_sort;
    rmX_nNodeFromListChar(userSortedList, smallestKey);
    strcpy(*userValue,smallestKey->value);
    *userKey = smallestKey->key;
    free((Node*)smallestKey);

    return SUCCESS;
}
