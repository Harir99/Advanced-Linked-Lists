//
// Created by harir on 2020-03-29.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortedList.h"
int main(int argc, char const *argv[]) {
  Sorted_list * sortedList = create_list();
  int i;
  int tempVal=0;
  double tempKey = 0.0;
  Key_t  tmpkey = 0.0;
  value_t  tmpVal = 0;
  char filename[100];
  char command[10];
  char String[200];

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
      int n = 0;
      int order;
      while(fgets(String,200,fh)!= NULL){
        int flag = 1;
        if(flag == 1){
          sscanf(String,"%s %lf %d", command,&tmpkey,&tmpVal);
          if (strcmp(command,"p") == 0) //indentical
          {
              printf("%s:           %lf    %d\n",command, tmpkey, tmpVal);
              push(sortedList, tmpVal,tmpkey);
          }
          else if (strcmp(command,"a") == 0) //indentical
          {
              printf("%s:           %lf    %d\n",command, tmpkey, tmpVal);
              append(sortedList, tmpVal,tmpkey);
          }
          else if (strcmp(command,"print_all") == 0) //indentical
          {

            print_list_all(sortedList);
            printf("\n");
          }
          else if (strcmp(command,"print_sort") == 0) //indentical
          {
            print_list_sort(sortedList);
            printf("\n" );
          }
        }
        flag = 0;
        if(flag == 0){
          sscanf(String,"%s %d %lf %d", command,&n,&tmpkey,&tmpVal);
          if (strcmp(command,"count_up") == 0) //indentical
          {
             count_up(n);
             printf("\n");
          }
          else if (strcmp(command,"count_down") == 0) //indentical
          {
           count_down(n);
           printf("\n");
          }
          else if (strcmp(command,"nth") == 0) //indentical
          {
           printf("%s:\n",command );
           nth(sortedList,n+1,&tmpVal,&tmpkey,SORTED_ORDER);
           printf("\n");
          }
          else if (strcmp(command,"remove_nth") == 0) //indentical
          {
           printf("%s:\n",command );
           printf("n = %d\n",n );
           remove_nth(sortedList,&tmpVal,&tmpkey,n+1,INSERTED_ORDER);
           printf("\n");
          }
        }

      }

  return 0;
}
