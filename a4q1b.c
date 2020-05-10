#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "sortedList.h"

int main(int argc, char const *argv[]) {
Sorted_list * sortedList = create_list();
Sorted_list * sortedList2 = create_list();
Sorted_list * sortedList3 = create_list();


char String[5][100];
char filename[100];

//open and get the file handle
FILE* fh;
if(fopen(argv[1], "r") != NULL){

fh = fopen(argv[1], "r");
}
else{
  printf("Enter the file name: \n");
  scanf("%s", filename);
  fh = fopen(filename, "r");

}
//read line by line
const size_t line_size = 200;
char* input;

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

int order = 0;
char string[200];

      printf("%s:           %s    %s",String[0], String[1],String[2]);
      // printf("%s|%s:           %s    %s",String[0],String[1], String[2],String[3]);

      if (strcmp(String[0],"p") == 0) //indentical
      {

          push(sortedList, atoi(String[2]),atof(String[1]));

      }
      else if (strcmp(String[0],"a") == 0) //indentical
      {
          append(sortedList, atoi(String[2]),atof(String[1]));
      }
    else if (strcmp(String[0],"sum") == 0) //indentical //remove first
    {
        printf("Sum INSERTED ORDER: \n");
        printf("sum = %d\n",sum(sortedList,INSERTED_ORDER));
        printf("\n" );
        printf("Sum SORTED ORDER:\n");
        printf("sum = %d\n",sum(sortedList,SORTED_ORDER));
        printf("\n" );

    }
    else if (strcmp(String[0],"square") == 0) //indentical  //Remove last
    {
      sortedList2 = square(sortedList);
      print_list_all(sortedList2);
      printf("\n" );


    }
    else if (strcmp(String[0],"diff") == 0) //indentical  //Remove smallest
    {
      printf("diff INSERTED ORDER: \n");
      sortedList3 = diff(sortedList,sortedList2,INSERTED_ORDER);
      print_list_all(sortedList3);
      printf("\n" );
      printf("Diff SORTED ORDER:\n");
      sortedList3 = diff(sortedList,sortedList2,SORTED_ORDER);
      print_list_all(sortedList3);
      printf("\n" );


    }
    else if (strcmp(String[0],"sum_of_sq_diff") == 0) //indentical  //Remove largest
    {
      printf(" sum_of_sq_diff INSERTED ORDER: \n");
      printf("sum_of_sq_diff = %d\n",sum_of_sq_diff(sortedList,sortedList2,INSERTED_ORDER));
      printf("\n" );
      printf(" sum_of_sq_diff SORTED ORDER:\n");
      printf("sum_of_sq_diff = %d\n",sum_of_sq_diff(sortedList,sortedList2,SORTED_ORDER));
      printf("\n" );

    }
    else if (strcmp(String[0],"empty") == 0) //indentical  //empty list
    {
        empty_list(sortedList);
    }
    else if (strcmp(String[0],"print_all") == 0) //indentical  //empty list
    {
          print_list_all(sortedList);
          printf("\n" );

    }
    else if (strcmp(String[0],"print_sort") == 0) //indentical  //empty list
    {
        print_list_sort(sortedList);
        printf("\n" );
    }

  }


printf("\n");
fclose (fh);   /* close file if not stdin */
free(line);    // dont forget to free heap memory


  return 0;
}
