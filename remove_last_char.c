#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Charlist.h"



int remove_last_char (Sorted_list* userSortedList, value_t* userValue, Key_t* userKey)
{
    Node* tempNode = userSortedList->tail;
    rmX_nNodeFromListChar(userSortedList, userSortedList->tail);
    strcpy(*userValue,tempNode->value);
    *userKey = tempNode->key;
    free((Node*)tempNode);

    return SUCCESS;
}
