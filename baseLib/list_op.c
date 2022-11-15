/*by牛泽坤，链表运算库，用于字符串处理*/
#include <stdlib.h>
#include "my_ctype.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>
#include "list_op.h"

p_list_v list_itm_op(p_list_v data_list, void (*op)(void *, uint))
{
  assert(data_list != NULL);
  uint len = list_len(data_list);
  p_list_v temp_list = list_data_cpy(data_list);
  //这个函数要改变原序列对应的内存
  p_list_v temp = temp_list;
  while (list_emp(temp) == _NOT_EMPTY_)
  {
    op(node_val(temp), node_size(temp));
    temp = node_next(temp);
  }
  return temp_list;
}
uint lists_len_min(p_list_c data_list_a, p_list_c data_list_b)
{
  assert(data_list_a != NULL && data_list_b != NULL);
  p_list_v temp_a = list_inv_cpy(data_list_a);
  p_list_v temp_b = list_inv_cpy(data_list_b);
  uint len = 0;
  while (list_emp(temp_a) == _NOT_EMPTY_ && list_emp(temp_b) == _NOT_EMPTY_)
  {
    len++;
    temp_a = node_next(temp_a);
    temp_b = node_next(temp_b);
  }
  list_del_innate(temp_a);
  list_del_innate(temp_b);
  return len;
}
p_list_v lists_itm_op(p_list_v data_list_a, p_list_v data_list_b, void *(*op)(void *, void *, uint))
{
  assert(data_list_a != NULL && data_list_b != NULL && node_size(data_list_a) == node_size(data_list_b));
  p_list_v temp_a = list_inv_cpy(data_list_a);
  p_list_v temp_b = list_inv_cpy(data_list_b);
  uint i = 0;
  p_list_v result_list = list_new_blank();
  while (list_emp(temp_a) == _NOT_EMPTY_ && list_emp(temp_b) == _NOT_EMPTY_)
  {
    assert(sizeof(node_val(temp_a)) == sizeof(node_val(temp_a)));
    result_list = list_cat(result_list, op(node_val(temp_a), node_val(temp_b), node_size(temp_a)), node_size(temp_a));
    temp_a = node_next(temp_a);
    temp_b = node_next(temp_b);
    i++;
  }
  if (list_emp(temp_a) == _NOT_EMPTY_ || list_emp(temp_b) == _NOT_EMPTY_)
  {
    printf("Warning! The two lists are not in the same size!\nSame size sublists are worked out only.");
  }
  list_del_innate(temp_a);
  list_del_innate(temp_b);
  return result_list;
}
p_list_v list_del_bil(p_list_v data_list, uint (*cond)(void *, uint))
{
  assert(data_list != NULL);
  uint len = list_len(data_list);
  p_list_v temp_cpy = list_data_cpy(data_list);
  p_list_v temp_now = temp_cpy;
  //清空尾部的无效字符
  while (cond(node_val(temp_cpy), node_size(temp_cpy)))
  {
    temp_cpy = node_next(temp_now);
    list_out(temp_now);
    temp_now = temp_cpy;
    temp_now = node_next(temp_now);
  }
  temp_cpy = list_inv_cpy(temp_now);
  temp_now = temp_cpy;
  //清空头部的无效字符
  while (cond(node_val(temp_cpy), node_size(temp_cpy)))
  {
    temp_cpy = node_next(temp_now);
    list_out(temp_now);
    temp_now = temp_cpy;
    temp_now = node_next(temp_now);
  }
  return list_inv_cpy(temp_cpy);
}
p_list_v list_del_val(p_list_v data_list, uint (*cond)(void *, uint))
{
  assert(data_list != NULL && cond != NULL);
  p_list_v temp_cpy = list_data_cpy(data_list);
  p_list_v temp_now = temp_cpy;
  p_list_v temp_pre = temp_now;
  uint head_flag = 0;
  while (list_emp(temp_now) == _NOT_EMPTY_)
  {
    if (head_flag == 0 && cond(node_val(temp_now), node_size(temp_now)))
    {
      temp_cpy = node_next(temp_now);
      list_out(temp_now);
      temp_now = temp_cpy;
      temp_pre = temp_now;
      temp_now = node_next(temp_now);
    }
    else if (cond(node_val(temp_now), node_size(temp_now)))
    {
      head_flag = 1;
      node_del(temp_pre, temp_now);
      temp_now = node_next(temp_pre);
    }
    else
    {
      head_flag = 1;
      temp_pre = temp_now;
      temp_now = node_next(temp_pre);
    }
  }
  return list_inv_cpy(temp_cpy);
}