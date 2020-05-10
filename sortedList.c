#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortedList.h"


int printSortedList(SortedList* mySortedList)
{
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("| H %d | T %d | T-Pre %d | H-sort %d | T-sort %d |  T-PreSort %d | sz %d |\n",
            mySortedList->head, mySortedList->tail, mySortedList->prev_tail, mySortedList->head_sort, mySortedList->tail_sort,
            mySortedList->prev_tail_sorted, size(mySortedList));
    printf("----------------------------------------------------------------------------------------------------\n");
    return SUCCESS;

}



int size (SortedList * userSortedList)
{
    //printf("size: Calculating size...\n");
    //printf("Main: Calculated mySortedList size %d\n", userSortedList->size);
    return (userSortedList->size);
}



int sortList (SortedList* userSortedList, Node* newNode)
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



int push (SortedList * userSortedList, value_t userValue, key_t userKey)
{
    //Create Node & use malloc to put it somewhere in mem.
    Node* newNode = (Node*)malloc(sizeof(Node));
    printf("push: pushing new node (%d) of key %d value %d \n", newNode, userKey,userValue );
    newNode->key = userKey;
    newNode->value = userValue;
    newNode->sort = NULL;
    newNode->next = NULL;

    //Set Nodes next
    printf("push: assigning value %d to node-next\n", userSortedList->head);
    newNode->next = userSortedList->head;

    sortList(userSortedList, newNode);
    printf("push: assigning value %d to node-sort\n", newNode->sort);



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
    printf("push: assigning new addr. %d into head (H)...\n", newNode);
    userSortedList->head = newNode;


    userSortedList->size++;
    return SUCCESS;
}



int append (SortedList * userSortedList, value_t userValue, key_t userKey)
{
    //Create Node & use malloc to put it somewhere in mem.
    Node* newNode = (Node*)malloc(sizeof(Node));
    printf("append: appending new node (%d) of key %d value %d \n", newNode, userKey, userValue);
    newNode->key = userKey;
    newNode->value = userValue;
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
        printf("append: assigning addr.: %d into previous tail...\n", userSortedList->tail);
        userSortedList->prev_tail = userSortedList->tail;

        Node* tailNode = userSortedList->tail;
        printf("append: assigning value %d to %d's next\n", newNode, userSortedList->tail);
        tailNode->next = newNode;
    }

    sortList(userSortedList, newNode);


    //move our current head to tail
    printf("append: assigning new addr.: %d into sortedList's tail...\n", newNode);
    userSortedList->tail = newNode;
    userSortedList->size++;
    return SUCCESS;
}


//Removes an index Node
int rmX_nNodeFromList(SortedList* userSortedList, Node* nodeToRemove)
{
    Node* tmpNodeIndx = userSortedList->head; //temp init
    Node* preNodeTmpIndex = tmpNodeIndx;
    int preNodeNotFound = 1;

    printf("rmX_nNodeFromList: removing node Addr. %d key %d value %d\n", nodeToRemove, nodeToRemove->key, nodeToRemove->value);

    //special cases
    if (userSortedList->head == NULL || userSortedList->tail == NULL || nodeToRemove == NULL)  //List is not initiated
    {
        printf("rmX_nNodeFromList:failure!!!\n");
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
        printf("rmX_nNodeFromList: Rmv addr. %d  frm List & set %d to head \n",
               userSortedList->head, userSortedList->head->next);
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
                printf("rmX_nNodeFromList: preRemoved's-next is set to %d, set prevtail to %d\n",tmpNodeIndx->next->next, userSortedList->prev_tail);
            }
            else if (nodeToRemove == userSortedList->tail)
            {

                userSortedList->tail = userSortedList->prev_tail;//move tail upwards to
                if (userSortedList->prev_tail != NULL)
                {
                    userSortedList->prev_tail = preNodeTmpIndex;
                }
                printf("rmX_nNodeFromList:set prev-tail to Addr. %d & set tail to Addr. %d \n",userSortedList->prev_tail, userSortedList->tail);
            }

        break;
        }
        preNodeTmpIndex = tmpNodeIndx;
        tmpNodeIndx = tmpNodeIndx->next;
    }

    userSortedList->size--;
    return SUCCESS;
}


//Removes a node from key sorted list
int rmSortedNode (SortedList* userSortedList, Node* tempNode)
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
            printf("rmSortedNode: removing sorted %d & rplc with sorted addr. %d\n", tmpHdSortedNode->sort, tmpHdSortedNode->sort->sort);
            tmpHdSortedNode->sort = tmpHdSortedNode->sort->sort; //bypass the to-be removed key in the sorted list

            return SUCCESS;
        }
        tmpSortedPreNodeIndex = tmpHdSortedNode; //store this loop index
        tmpHdSortedNode = tmpHdSortedNode->sort;
    }
    return SUCCESS;
}


//removes first node
int remove_first (SortedList* userSortedList, value_t* userValue, key_t* userKey)
{
    Node* tempNode = userSortedList->head;

    rmX_nNodeFromList(userSortedList, userSortedList->head);
    printf("remove_first: removing first, Addr. %d\n",userSortedList->head);
    *userValue = tempNode->value;
    *userKey = tempNode->key;
    free((Node*)tempNode);

    return SUCCESS;
}



int remove_last (SortedList* userSortedList, value_t* userValue, key_t* userKey)
{
    Node* tempNode = userSortedList->tail;
    printf("remove_last: removing last, Addr. %d\n",userSortedList->tail);
    rmX_nNodeFromList(userSortedList, userSortedList->tail);
    *userValue = tempNode->value;
    *userKey = tempNode->key;
    free((Node*)tempNode);

    return SUCCESS;
}



int remove_smallest_key (SortedList* userSortedList, value_t* userValue, key_t* userKey)
{
    //find the smallest key
    Node* smallestKey = userSortedList->head_sort;
    printf("remove_smallest_key: removing smallest (key), Addr. %d\n",userSortedList->head_sort);

    rmX_nNodeFromList(userSortedList, smallestKey);
    *userValue = smallestKey->value;
    *userKey = smallestKey->key;
    free((Node*)smallestKey);

    return SUCCESS;
}



int remove_largest_key (SortedList* userSortedList, value_t* userValue, key_t* userKey)
{
    //find the smallest key
    Node* largestKey = userSortedList->tail_sort;
    printf("remove_largest_key: removing largest(key), Addr. %d\n",userSortedList->tail_sort);

    rmX_nNodeFromList(userSortedList, largestKey);
    *userValue = largestKey->value;
    *userKey = largestKey->key;
    free((Node*)largestKey);

    return SUCCESS;
}



void empty_list(SortedList* userSortedList)
{
    printf("empty_list:emptying list...\n");
    userSortedList->tail_sort = NULL;
    userSortedList->tail = NULL;
    userSortedList->head = NULL;
    userSortedList->head_sort = NULL;
    userSortedList->prev_tail_sorted = NULL;
    userSortedList->prev_tail = NULL;
    userSortedList->size = 0;
    printf("empty:             size = %d",userSortedList->size);
}


void destroy_list (SortedList* userSortedList)
{
    empty_list(userSortedList);
    printf("destroy_list:Destroying list...\n");
    free((SortedList*)userSortedList);
}
