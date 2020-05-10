#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Charlist.h"

//Removes a node from key sorted list
int rmSortedNodeChar (Sorted_list* userSortedList, Node* tempNode)
{
    Node* tmpHdSortedNode = userSortedList->head_sort;
    Node* tmpSortedPreNodeIndex = tmpHdSortedNode;
    int sortedNodeNotFound = 1;
    //special case: if head to be removed is also headSort and it is not the only item in sorted list
    if (userSortedList->size == 2)     //special case: 2 items in list
    {
        userSortedList->prev_tail_sorted = NULL;
    }

    if (tempNode == tmpHdSortedNode ) //special case: head is the same as head sorted
    {
        userSortedList->head_sort = tmpHdSortedNode->sort;
        return SUCCESS;
    }

    while (sortedNodeNotFound)
    {
        if (tempNode->key == tmpHdSortedNode->sort->key)  //find head's key in the sorted list
        {
            sortedNodeNotFound = 0;
            if (tmpHdSortedNode->sort == userSortedList->tail_sort)  //if this sorted node is also tail
            {
                userSortedList->prev_tail_sorted = tmpSortedPreNodeIndex;   //set the previously save index sorted
                userSortedList->tail_sort = tmpHdSortedNode;
            }
            else if (tmpHdSortedNode->sort == userSortedList->prev_tail_sorted)
            {
                userSortedList->prev_tail_sorted = tmpHdSortedNode;
            }
            tmpHdSortedNode->sort = tmpHdSortedNode->sort->sort; //bypass the to-be removed key in the sorted list

            return SUCCESS;
        }
        tmpSortedPreNodeIndex = tmpHdSortedNode; //store this loop index
        tmpHdSortedNode = tmpHdSortedNode->sort;
    }
    return SUCCESS;
}
