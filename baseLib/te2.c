#include <stdio.h>
#include "my_list.h"

void main()
{
  char *a = (char *)calloc(1, sizeof(char));
  node_data *list = list_new();
  // while ((*a = getchar()) != EOF)
  while ((*a = getchar()) != EOF)
  {
    if (*a == '\n')
    {
      continue;
    }
    list = list_cat(list, a);
    a = (char *)calloc(1, sizeof(char));
    // node_data *temp = list_inv_cpy(list);
    /* code */
  }

  uint len = list_len(list);
  void **M = (void **)calloc(len, sizeof(void *));
  node_data* sub_list=list_sub(list,0,12);
  len=list_len(sub_list);
  M = list_prt(sub_list);
  int i = 0;
  printf("string is ");
  while (i < 4)
  {
    char d = *(char *)(*(M + i));
    printf("%c", d);
    i++;
  }
  printf("\nint is %f",float_from_char_list(sub_list));
  free(M);
  M = (void **)calloc(1, sizeof(void *));
  M=list_ind(list,1);
  printf("\nchar is %c",*(char*)(*M));
}