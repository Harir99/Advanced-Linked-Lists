#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Charlist.h"


void print_list_sorted_char (Sorted_list* userSortedList)
{
    Node* sortNodeIdx = userSortedList->head_sort; //start at head
    printf("print sort: Key Sort Order\n");

    while (sortNodeIdx != NULL)     //Loop through key sorted list until end
    {
        printf("\n%2d %s\n",sortNodeIdx->key, sortNodeIdx->value);
        sortNodeIdx = sortNodeIdx->sort;
    }
}
