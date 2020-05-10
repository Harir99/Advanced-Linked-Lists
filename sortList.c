#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortedList.h"



int sortList (Sorted_list* userSortedList, Node* newNode)
{
    //sort list head by key order --> head_sort
    Node* tempHdSrtPtr = userSortedList->head_sort;
    Node* tempHdPtrSort = NULL;




    if (userSortedList->head_sort == NULL) //first push to be sorted - special handling
    {
        userSortedList->head_sort        = newNode;
        userSortedList->tail_sort        = newNode;
        userSortedList->prev_tail_sorted = NULL;
    }
    else if (userSortedList->head_sort != NULL && userSortedList->prev_tail_sorted == NULL) //2nd to sort - special case
    {
        if (newNode->key < tempHdSrtPtr->key )  //if new node has smaller key than head
        {
            newNode->sort = tempHdSrtPtr;
            userSortedList->head_sort = newNode;
            userSortedList->prev_tail_sorted = newNode;
        }
        else
        {
            userSortedList->prev_tail_sorted = tempHdSrtPtr;
            userSortedList->tail_sort = newNode;        //This is our new tail
            tempHdSrtPtr->sort = newNode;
        }
    }
    else  //typical sorting - rest of cases
    {
        tempHdPtrSort = tempHdSrtPtr;                              //current node
        int sortNotDone = 1;

        if (newNode->key < tempHdPtrSort->key)   //smaller than head, move head and finish sort
        {
            sortNotDone = 0;
            newNode->sort = tempHdPtrSort;
            userSortedList->head_sort = newNode;
        }
        else if (newNode->key > userSortedList->tail_sort->key)  //larger than tail largest (>tail key), mv -> tail
        {
            sortNotDone = 0;
            newNode->sort = NULL;  //no more nodes after the tail
            userSortedList->prev_tail_sorted = userSortedList->tail_sort;
            userSortedList->tail_sort->sort = newNode;  //link this node to one before
            userSortedList->tail_sort= newNode;


        }
        while(sortNotDone)
        {

            if (newNode->key >= tempHdPtrSort->key && newNode->key < tempHdPtrSort->sort->key)
            {
                sortNotDone = 0;
                newNode->sort = tempHdPtrSort->sort;                  //Point to the next larger key
                tempHdPtrSort->sort = newNode;

            }
            tempHdPtrSort = tempHdPtrSort->sort;                //We switch to the next sorted node
        }


    }
    return SUCCESS;
}
