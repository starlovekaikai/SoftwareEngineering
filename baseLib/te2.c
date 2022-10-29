#include <stdio.h>
#include "my_list.h"

uint is_same(void *a, void *b)
{
  char *ta = (char *)a;
  char *tb = (char *)b;
  if (*ta == *tb)
  {
    return 1;
  }
  return 0;
}
void **op(void *a)
{
  void **pa = (void **)calloc(1, sizeof(void *));
  *pa = a;
  if (*(char *)*pa == '2')
  {
    *(char *)*pa = '-';
  }
  return pa;
}
void **op2(void *a)
{
  void **pa = (void **)calloc(1, sizeof(void *));
  *pa = a;
  if (*(char *)*pa == '3')
  {
    *(char *)*pa = '+';
  }
  return pa;
}
int main()
{
  char *a = (char *)calloc(1, sizeof(char));

  while ((*a = getchar()) != EOF)
  {
    node_data *list = list_new();
    list = list_cat(list, a);
    a = (char *)calloc(1, sizeof(char));
    while ((*a = getchar()) != '\n')
    {
      list = list_cat(list, a);
      a = (char *)calloc(1, sizeof(char));
      // node_data *temp = list_inv_cpy(list);
      /* code */
    }
    char A[2] = {'1'};
    char *pA = A;
    node_data *fid = list_del_val(list, pA, is_same);
    uint len = list_len(list);
    void **M = (void **)calloc(len, sizeof(void *));
    node_data *sub_list = list_sub(fid, 0, 6);
    len = list_len(fid);
    // len = list_len(sub_list);
    list_prt(fid, M);
    // list_prt(sub_list,M);
    int i = 0;
    printf("string is ");
    while (i < len)
    {
      char d = *(char *)(*(M + i));
      printf("%c", d);
      i++;
    }
    printf("\nint is %f", float_from_char_list(sub_list));
    // free(M);
    void **N = (void **)calloc(1, sizeof(void *));
    N = list_ind(fid, 3);
    printf("\nchar is %c\n", *(char *)*N);

    node_data *List = list_itm_op(list, op);
    len = list_len(List);
    void **P = (void **)calloc(len, sizeof(void *));
    list_prt(List, P);

    i = 0;
    printf("string is ");
    while (i < len)
    {
      char d = *(char *)(*(P + i));
      printf("%c", d);
      i++;
    }
    printf("\n");

    List = list_itm_op(list, op2);
    len = list_len(List);
    P = (void **)calloc(len, sizeof(void *));
    list_prt(List, P);

    i = 0;
    printf("string is ");
    while (i < len)
    {
      char d = *(char *)(*(P + i));
      printf("%c", d);
      i++;
    }
    printf("\n");
  }

  return 0;
}