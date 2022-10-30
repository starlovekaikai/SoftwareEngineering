#include <stdlib.h>
#include "my_ctype.h"
#include <malloc.h>
#include <assert.h>
#include "my_list.h"
#include <stdio.h>
#include "list_op.h"
node_data *list_itm_op(node_data *data_list, void **(*op)(void *))
{
  assert(data_list != NULL);
  //这个函数要改变原序列对应的内存
  node_data *temp_list = list_inv_cpy(data_list);
  node_data *temp = (node_data *)malloc(sizeof(node_data));
  temp = temp_list;
  while (temp->next != NULL)
  {
    temp->val = *op(temp->val);
    temp = temp->next;
  }
  temp = NULL;
  free(temp);
  return list_inv_cpy(temp_list);
}
uint lists_len_min(node_data *data_list_a, node_data *data_list_b)
{
  assert(data_list_a != NULL && data_list_b != NULL);
  node_data *temp_a = (node_data *)malloc(sizeof(node_data));
  node_data *temp_b = (node_data *)malloc(sizeof(node_data));
  temp_a = data_list_a;
  temp_b = data_list_b;
  uint len = 0;
  while (temp_a->next != NULL && temp_b->next != NULL)
  {
    len++;
    temp_a = temp_a->next;
    temp_b = temp_b->next;
  }
  temp_a = NULL;
  temp_b = NULL;
  free(temp_a);
  free(temp_b);
  return len;
}
void **lists_itm_op(node_data *data_list_a, node_data *data_list_b, void **(*op)(void *, void *), uint len)
{
  assert(data_list_a != NULL && data_list_b != NULL);
  node_data *temp_a = (node_data *)malloc(sizeof(node_data));
  node_data *temp_b = (node_data *)malloc(sizeof(node_data));
  temp_a = data_list_a;
  temp_b = data_list_b;
  uint i = 0;
  void **result_list = (void **)malloc(len * sizeof(void *));
  while (i < len)
  {
    *(result_list + i) = *op(temp_a->val, temp_b->val);
    temp_a = temp_a->next;
    temp_b = temp_b->next;
    i++;
  }
  temp_a = NULL;
  temp_b = NULL;
  free(temp_a);
  free(temp_b);
  return result_list;
}
node_data *list_del_bil(node_data *data_list, uint (*cond)(void *))
{
  assert(data_list != NULL);
  node_data *temp_list = list_inv_cpy(data_list);
  node_data *temp_now = (node_data *)malloc(sizeof(node_data));
  temp_now = temp_list;
  //清空尾部的无效字符
  while (cond(temp_list->val))
  {
    temp_now = temp_list->next;
    free(temp_list);
    temp_list = temp_list->next;
  }
  temp_list = list_inv_cpy(temp_now);
  temp_now = temp_list;
  //清空头部的无效字符
  while (cond(temp_list->val))
  {
    temp_now = temp_list->next;
    free(temp_list);
    temp_list = temp_list->next;
  }
  temp_list = NULL;
  free(temp_list);
  return temp_now;
}
node_data *list_del_val(node_data *data_list, void *val, uint (*comp)(void *, void *))
{
  assert(data_list != NULL);
  node_data *temp_now = list_inv_cpy(data_list);
  node_data *temp_list = (node_data *)malloc(sizeof(node_data));
  temp_list = temp_now;
  node_data *temp_pre = list_new();
  uint head_flag = 0;
  while (temp_now->next != NULL)
  {
    if (head_flag == 0 && comp(val, temp_now->val))
    {
      temp_list = temp_now->next;
      temp_pre->next = temp_now->next;
      free(temp_now);
      temp_now = temp_pre->next;
    }
    else if (comp(val, temp_now->val))
    {
      head_flag = 1;
      temp_pre->next = temp_now->next;
      free(temp_now);
      temp_now = temp_pre->next;
    }
    else
    {
      head_flag = 1;
      temp_pre = temp_now;
      temp_now = temp_now->next;
    }
  }
  temp_pre = NULL;
  free(temp_pre);
  temp_now = NULL;
  free(temp_now);
  return list_inv_cpy(temp_list);
}