#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Charlist.h"


//removes first node
int remove_first_char (Sorted_list* userSortedList, value_t* userValue, Key_t* userKey)
{
    Node* tempNode = userSortedList->head;
    rmX_nNodeFromListChar(userSortedList, userSortedList->head);
    // deleteNode(userSortedList->head,0);
    strcpy(*userValue,tempNode->value);
    *userKey = tempNode->key;
    free((Node*)tempNode);


    return SUCCESS;
}
