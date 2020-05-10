#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortedList.h"

void print_list_sort (Sorted_list* userSortedList)
{
    Node* sortNodeIdx = userSortedList->head_sort; //start at head
    printf("print sort: Key Sort Order\n");

    while (sortNodeIdx != NULL)     //Loop through key sorted list until end
    {
        printf("%lf %2d\n",sortNodeIdx->key, sortNodeIdx->value);
        sortNodeIdx = sortNodeIdx->sort;
    }
}
