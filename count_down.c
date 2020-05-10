#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortedList.h"
int count_down(int n){
  int i;
  printf("count_down from %d to 0 by 2\n",2*n);

  for ( i = 2*n; i > 0; i = i - 2) {
    printf("%d, ",i );
  }
  printf("0");
  printf("\n");
  return SUCCESS;
}
