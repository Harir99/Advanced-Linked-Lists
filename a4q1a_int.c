//
// Created by harir on 2020-03-29.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortedList.h"

//------------Definitions & Includes-----------------//
#define SUCCESS 0
#define FAIL 1
#define DATA_SIZE 1000

int main(int argc, char const *argv[])
{
    int tempVal=0;
    double tempKey = 0.0;
    Key_t  tmpkey = 0.0;
    value_t  tmpVal = 0;

    //init Sorted List
    Sorted_list * mySortedList = create_list();

    char String[5][100];
    char filename[100];


    //open and get the file handle
    FILE* fh;
 if(fopen(argv[1], "r") != NULL){
   strcpy(filename, argv[1]);
}
else {
  printf("Enter the file name: \n");
  scanf("%s",filename);
}
fh = fopen(filename,"r");

//read line by line
    const size_t line_size = 200;

    char* line = malloc(line_size);
    while (fgets(line, line_size, fh) != NULL)
    {

        int i,j,ctr;

        j=0; ctr=0;
        for(i=0;i<=(strlen(line));i++)
        {
            if(line[i]==' ' || line[i]=='\0') //if char is space
            {
                String[ctr][j]='\0';
                ctr++;
                j=0;
            }
            else
            {
                String[ctr][j]=line[i];
                j++;
            }
        }
        printf("%s:           %s    %s",String[0], String[1], String[2]);

        if (strcmp(String[0],"p") == 0) //indentical
        {
            push(mySortedList, atoi(String[2]),atof(String[1]));

        }
        else if (strcmp(String[0],"a") == 0) //indentical
        {
            append(mySortedList, atoi(String[2]),atof(String[1]));
        }
        else if (strcmp(String[0],"remove_first") == 0) //indentical //remove first
        {
            remove_first(mySortedList, &tmpVal, &tmpkey);
        }
        else if (strcmp(String[0],"remove_last") == 0) //indentical  //Remove last
        {
            remove_last(mySortedList, &tmpVal, &tmpkey);
        }
        else if (strcmp(String[0],"remove_small") == 0) //indentical  //Remove smallest
        {
            remove_smallest_key(mySortedList, &tmpVal, &tmpkey);
        }
        else if (strcmp(String[0],"remove_large") == 0) //indentical  //Remove largest
        {
            remove_largest_key(mySortedList, &tmpVal, &tmpkey);
        }
        else if (strcmp(String[0],"empty") == 0) //indentical  //empty list
        {
            empty_list(mySortedList);
        }
        else if (strcmp(String[0],"print_all") == 0) //indentical  //empty list
        {
              print_list_all(mySortedList);
        }
        else if (strcmp(String[0],"print_sort") == 0) //indentical  //empty list
        {
            print_list_sort(mySortedList);
        }
        else if (strcmp(String[0],"size") == 0) //indentical  //empty list
        {
          int length = 0;
            length = size(mySortedList);
            printf("List size = %d\n",length );
        }

    }


      Node * new_head = mySortedList->head;
      Node *old_node = NULL;
      while(new_head != NULL){
        old_node = new_head;
        new_head = new_head->next;
        free(old_node);
      }
      free(mySortedList);
    printf("\n");
    fclose (fh);   /* close file if not stdin */
    free(line);    // dont forget to free heap memory

// }
    //------------------------------------------------------------------------------//
    return SUCCESS;
}



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
