#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Charlist.h"


int remove_largest_key_char (Sorted_list* userSortedList, value_t* userValue, Key_t* userKey)
{
    //find the smallest key
    Node* largestKey = userSortedList->tail_sort;

    rmX_nNodeFromListChar(userSortedList, largestKey);
    strcpy(*userValue,largestKey->value);
    *userKey = largestKey->key;
    free((Node*)largestKey);

    return SUCCESS;
}
