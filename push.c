#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortedList.h"
int push (Sorted_list* userSortedList, value_t userValue, Key_t userKey)
{
    //Create Node & use malloc to put it somewhere in mem.
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = userKey;
    newNode->value = userValue;
    newNode->sort = NULL;
    newNode->next = NULL;

    //Set Nodes next
    newNode->next = userSortedList->head;

    sortList(userSortedList, newNode);



    //First node in list, special handling
    if (userSortedList->head == NULL)
    {
        userSortedList->tail = newNode;
        userSortedList->prev_tail = NULL;
    }
    else if (userSortedList->head != NULL && userSortedList->prev_tail == NULL) //second node - special handling
    {
        userSortedList->prev_tail = newNode;
    }


    //move list's head
    userSortedList->head = newNode;


    userSortedList->size++;
    return SUCCESS;
}
