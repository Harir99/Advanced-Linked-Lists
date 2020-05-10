#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Charlist.h"


int append_char (Sorted_list* userSortedList, value_t userValue, Key_t userKey)
{
    //Create Node & use malloc to put it somewhere in mem.
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = userKey;
    strcpy(newNode->value,userValue);
    newNode->sort = NULL;
    newNode->next = NULL;

    //First node in list, special handling
    if (userSortedList->tail == NULL)
    {
        userSortedList->head = newNode;
        userSortedList->prev_tail = NULL;
    }
    else //not first - typical case
    {
        //move our current tail to prev-tail
        userSortedList->prev_tail = userSortedList->tail;

        Node* tailNode = userSortedList->tail;
        tailNode->next = newNode;
    }

    sortList(userSortedList, newNode);


    //move our current head to tail
    userSortedList->tail = newNode;
    userSortedList->size++;
    return SUCCESS;
}
