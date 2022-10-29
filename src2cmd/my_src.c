#include "my_ctype.h"
#include "my_list.h"
#include <malloc.h>
#ifndef NULL
#define NULL ((void *)0)
#endif
int lists_cmp(node_data *data_list_a, node_data *data_list_b)
{

}
//按括号匹配输入值
void node_match(node_data *data_list, node_data *top, char *val)
{
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
  char *temp = (char *)malloc(sizeof(char));
  if ((temp = getchar()) != '\n')
  {
    *char_out = temp;
    return 1;
  }
  else
  {
    return 0;
  }
}
