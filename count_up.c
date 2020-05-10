#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortedList.h"
int count_up(int n){
  printf("count_up from 0 to %d\n",n );
  int i;
  for ( i = 0; i < n; i++) {
    printf("%d, ",i );
  }
  printf("%d",n);
  printf("\n");
  return SUCCESS;
}
