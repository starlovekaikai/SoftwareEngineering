#include <stdio.h>
#include "my_list.h"

void main()
{
  char *a = (char *)calloc(1, sizeof(char));
  node_data *list = new_empty_list();
  while ((*a = getchar()) != EOF)
  {
    // char c = getchar();
    list = list_cat(list, a);
    a = (char *)calloc(1, sizeof(char));
    // node_data *temp = list_inv_cpy(list);
    /* code */
  }
  uint len = list_len(list);
  void **M = (void **)calloc(len, sizeof(void *));
  M = print_list(list);
  int i = 0;
  printf("string is ");
  while (i < len)
  {
    char d = *(char *)(*(M + i));
    printf("%c", d);
    i++;
  }

  // int *a = (int *)calloc(1, sizeof(int));
  // node_data *list = new_empty_list();
  // while (scanf("%d", a) != EOF)
  // {
  //   list = list_cat(list, a);
  //   a = (int *)calloc(1, sizeof(int));
  // }
  // int c[10] = {0};
  // int *p = c;
  // int **M = p;
  // M = print_list(list);
  // int i = 0;
  // printf("string is ");
  // while (**(M + i) != 0)
  // {
  //   int d = **(M + i);
  //   printf("%d", d);
  //   i++;
  // }
  // return 0;
}