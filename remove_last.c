#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortedList.h"
int remove_last (Sorted_list* userSortedList, value_t* userValue, Key_t* userKey)
{
    Node* tempNode = userSortedList->tail;
    rmX_nNodeFromList(userSortedList, userSortedList->tail);
    *userValue = tempNode->value;
    *userKey = tempNode->key;
    free((Node*)tempNode);

    return SUCCESS;
}
