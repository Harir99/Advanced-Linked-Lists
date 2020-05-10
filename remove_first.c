#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortedList.h"


//removes first node
int remove_first (Sorted_list* userSortedList, value_t* userValue, Key_t* userKey)
{
    Node* tempNode = userSortedList->head;

    rmX_nNodeFromList(userSortedList, userSortedList->head);
    *userValue = tempNode->value;
    *userKey = tempNode->key;
    free((Node*)tempNode);

    return SUCCESS;
}
