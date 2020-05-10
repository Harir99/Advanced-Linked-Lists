#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortedList.h"
void print_list_all (Sorted_list* userSortedList)
{
    Node* sortNodeIdx = userSortedList->head; //start at head
    printf("print all: Insertion Order\n");

    while (sortNodeIdx != NULL)     //Loop through insertion sorted list until end
    {
        printf("%lf %2d\n",sortNodeIdx->key, sortNodeIdx->value);
        sortNodeIdx = sortNodeIdx->next;
    }
}
