#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortedList.h"
//Removes an index Node
int rmX_nNodeFromList(Sorted_list* userSortedList, Node* nodeToRemove)
{
    Node* tmpNodeIndx = userSortedList->head; //temp init
    Node* preNodeTmpIndex = tmpNodeIndx;
    int preNodeNotFound = 1;

    //special cases
    if (userSortedList->head == NULL || userSortedList->tail == NULL || nodeToRemove == NULL)  //List is not initiated
    {
        return FAIL;
    }
    else if (userSortedList->size == 1)
    {
        empty_list(userSortedList);
        return SUCCESS;
    }
    else if (userSortedList->size == 2)  //2 nodes in list
    {
        userSortedList->prev_tail = NULL;
    }

    //rm Sorted Node
    rmSortedNode(userSortedList, nodeToRemove);

    if (nodeToRemove == userSortedList->head)
    {

        userSortedList->head = userSortedList->head->next; //move 2nd node up to head
        preNodeNotFound = 0;    //node is found
    }

    //Special case: find the node before nodeToRemove
    while (preNodeNotFound)
    {

        if (nodeToRemove == tmpNodeIndx->next)
        {

            preNodeNotFound = 0; // pre prevtail found!

            tmpNodeIndx->next = tmpNodeIndx->next->next;

            //if nodeToRemove is prevTail
            if (nodeToRemove == userSortedList->prev_tail)
            {
                userSortedList->prev_tail = tmpNodeIndx;  //move prev_tail one step upwards
            }
            else if (nodeToRemove == userSortedList->tail)
            {

                userSortedList->tail = userSortedList->prev_tail;//move tail upwards to
                if (userSortedList->prev_tail != NULL)
                {
                    userSortedList->prev_tail = preNodeTmpIndex;
                }
            }

        break;
        }

        preNodeTmpIndex = tmpNodeIndx;
        tmpNodeIndx = tmpNodeIndx->next;
    }

    userSortedList->size--;
    return SUCCESS;
}
