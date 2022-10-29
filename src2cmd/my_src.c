#include "my_ctype.h"
#include "my_list.h"
#include "my_math.h"
#include <malloc.h>
#ifndef NULL
#define NULL ((void *)0)
#endif
//按字符类型比较
void **char_comp(void *a, void *b)
{
  void **temp = (void **)malloc(sizeof(void *));
  if (*(char *)a == *(char *)b)
  {
    *(uint *)*temp = 0;
  }
  else
  {
    *(uint *)*temp = 1;
  }
  return temp;
}
uint lists_cmp(node_data *data_list_a, node_data *data_list_b, void **(*op)(void *, void *))
{
  assert(data_list_a != NULL &&data_list_b ! = NULL);
  uint len = lists_len_min(data_list_a, data_list_b);
  void **result_list = (void **)malloc(len * sizeof(void *));
  result_list = lists_itm_op(data_list_a, data_list_b, op, len);
  uint i = 0, temp = 0;
  while (i < len)
  {
    temp += *(uint *)*(result_list + i);
  }
  return temp;
}
uint list_char_cmp(node_data *data_list_a, node_data *data_list_b)
{
  assert(data_list_a != NULL &&data_list_b ! = NULL);
  return lists_cmp(data_list_a, data_list_b, char_comp);
}
point *pnt_from_char_list(node_data *data_list)
{
  //包括格式化：去除空格，
  //
}
//按括号匹配输入值
void node_match(node_data *data_list, node_data *top, char *val)
{
  assert(data_list != NULL);
  //返回值就是top，即当前最外层的子链
  if (*val == '(')
  {
    top = list_new();
  }
  else if (top != NULL && *val == ')')
  {
    data_list = list_cat(data_list, top);
    top = data_list;
  }
  else if (top != NULL && is_valid_char(*val))
  {
    top = list_cat(top, val);
  }
  else if (top != NULL && is_valid_char(*val) != 1)
  {
    printf("ERROR!There is INVALID character in input serials.");
    top = NULL;
  }
  else
  {
    printf("ERROR!There is MISMATCH in left and right bracket.");
    top = NULL;
  }
}
char *list_get_std(uint *char_out)
{
  //目前未考虑动态过程，仅能实现一次性输入命令，全部绘制结果
}
