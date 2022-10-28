#include <stdlib.h>
#include "my_ctype.h"
#include <malloc.h>
#ifndef NULL
#define NULL ((void *)0)
#endif
#define _IS_EMPTY_ 1
#define _NOT_EMPTY_ 0
typedef unsigned int uint;
typedef struct node_data
{
  void *val;
  struct node_data *next;
} node_data;
void node_free_innate(node_data *node)
{
  free(node->next);
  free(node);
}
node_data *list_new()
{
  node_data *temp = (node_data *)calloc(1, sizeof(node_data));
  temp->next = NULL;
  temp->val = NULL;
  return temp;
}
node_data *list_new_val(void *val)
{
  node_data *temp = (node_data *)calloc(1, sizeof(node_data));
  temp->next = NULL;
  temp->val = val;
  return temp;
}
node_data *list_cat(node_data *data_list, void *data_next)
{
  node_data *temp = (node_data *)calloc(1, sizeof(node_data));
  temp->val = data_next;
  temp->next = data_list;
  return temp;
}
void list_out(node_data *data_list, void *out_val)
{
  out_val = data_list->val;
  free(data_list);
}

void list_del_innate(node_data *data_list)
{
  node_data *temp = (node_data *)calloc(1, sizeof(node_data));
  temp = NULL;
  while (data_list->next != NULL)
  {
    temp = data_list->next;
    free(data_list);
    data_list = temp;
  }
  free(data_list->next);
  free(data_list);
}
void list_del_usr(node_data *data_list)
{
  node_data *temp = (node_data *)calloc(1, sizeof(node_data));
  temp = NULL;
  while (data_list->next != NULL)
  {
    free(data_list->val);
    temp = data_list->next;
    free(data_list);
    data_list = temp;
  }
  free(data_list->val);
  free(data_list->next);
  free(data_list);
}
uint list_len(node_data *data_list)
{
  uint iter = 0;
  node_data *temp = (node_data *)calloc(1, sizeof(node_data));
  temp = data_list;
  if (temp == NULL)
  {
    return 0;
  }
  while (temp->next != NULL)
  {
    iter++;
    temp = temp->next;
  }
  temp = NULL;
  free(temp);
  return iter;
}
uint list_emp(const node_data *data_list)
{
  if (data_list->next == NULL)
  {
    return _IS_EMPTY_;
  }
  else
  {
    return _NOT_EMPTY_;
  }
}
node_data *list_inv_cpy(node_data *data_list)
{
  node_data *temp = list_new();
  while (data_list->next != NULL)
  {
    temp = list_cat(temp, data_list->val);
    data_list = data_list->next;
  }
  return temp;
}
node_data *list_inv(node_data *data_list)
{
  node_data *temp = list_new();
  while (data_list->next != NULL)
  {
    temp = list_cat(temp, data_list->val);
    data_list = data_list->next;
  }
  list_del_innate(data_list);
  return temp;
}
node_data *list_cpy(node_data *data_list)
{
  node_data *temp1 = list_inv_cpy(data_list);
  return list_inv_cpy(temp1);
}

// char *print_list(node_data *data_list)
// {
//   uint i = 0;
//   char *buff = (char *)calloc(sizeof(*data_list) / sizeof(node_data), sizeof(node_data));
//   while (data_list->next != NULL)
//   {
//     *(buff + i) = *(char *)(data_list->val);
//     data_list = data_list->next;
//     i++;
//   }
//   return buff;
// }
void list_prt(node_data *data_list, void **buff)
{
  uint i = 0;
  node_data *temp = (node_data *)calloc(1, sizeof(node_data));
  temp = list_inv_cpy(data_list);
  node_data *stor = (node_data *)calloc(1, sizeof(node_data));
  stor = temp;
  while (temp->next != NULL)
  {
    *(buff + i) = (temp->val);
    temp = temp->next;
    i++;
  }
  list_del_innate(temp);
  list_del_innate(stor);
}

void **list_ind(node_data *data_list, uint ind)
{
  uint iter = 0;
  void **temp = (void **)calloc(1, sizeof(void *));
  node_data *data_inv = list_inv_cpy(data_list);
  while (iter != ind)
  {
    if (data_inv->next != NULL)
    {
      data_inv = data_inv->next;
    }
    else
    {
      break;
    }
    iter++;
  }
  if (iter < ind)
  {
    return NULL;
  }
  *temp = data_inv->val;
  list_del_innate(data_inv);
  return temp;
}
void **list_nod(node_data *node)
{
  void **temp = (void **)calloc(1, sizeof(void *));
  *temp = node->val;
  return temp;
}
node_data *list_sub(node_data *data_list, uint ind, uint len)
{
  node_data *data_temp = list_inv_cpy(data_list);
  node_data *temp = list_new();
  uint iter = 0;
  while (iter < ind)
  {
    if (data_temp->next == NULL)
    {
      list_del_innate(data_temp);
      list_del_innate(temp);
      return NULL;
    }
    data_temp = data_temp->next;
    iter++;
  }
  iter = 0;
  while (iter < len)
  {
    if (data_temp->next == NULL)
    {
      list_del_innate(data_temp);
      return list_inv_cpy(temp);
    }
    temp = list_cat(temp, data_temp->val);
    data_temp = data_temp->next;
    iter++;
  }
  list_del_innate(data_temp);
  return list_inv_cpy(temp);
}
int int_from_char_list(node_data *data_list)
{
  int temp = 0, sign = 1;
  node_data *temp_list = (node_data *)calloc(1, sizeof(node_data));
  temp_list = data_list;
  char temp_char = *(char *)temp_list->val;
  if (temp_char == '-')
  {
    sign = -1;
    temp_list = temp_list->next;
  }
  do
  {
    if (is_number(*(char *)temp_list->val))
    {
      temp = temp * 10 + *(char *)temp_list->val - '0';
      temp_list = temp_list->next;
    }
    else
    {
      printf("\n----------------****----------------\nERROR!\nThere are INVALID characters in DECIMAL number.\nPlease check your input or COMFIRM the type of list value is CHAR!\n----------------****----------------\n");
      temp_list = NULL;
      free(temp_list);
      return 0;
    }
  } while (temp_list->next != NULL);
  temp_list = NULL;
  free(temp_list);
  return temp * sign;
}
float float_from_char_list(node_data *data_list)
{
  float temp_int = 0, temp_dec = 0, sign = 1.0;
  node_data *temp_list = (node_data *)calloc(1, sizeof(node_data));
  node_data *fract_list = list_new();
  temp_list = data_list;
  char temp_char = *(char *)temp_list->val;
  if (temp_char == '-')
  {
    sign = -1.0;
    temp_list = temp_list->next;
  }
  //整数部分
  while (temp_list->next != NULL)
  {
    if (*(char *)(temp_list->val) == '.')
    {
      temp_list = temp_list->next;
      fract_list = list_inv_cpy(temp_list);
      break;
    }
    else if (is_number(*(char *)temp_list->val))
    {
      temp_int = temp_int * 10 + *(char *)temp_list->val - '0';
      temp_list = temp_list->next;
    }
    else
    {
      printf("\n----------------****----------------\nERROR!\nThere are INVALID characters in DECIMAL number.\nPlease check your input or COMFIRM the type of list value is CHAR!\n----------------****----------------\n");
      temp_list = NULL;
      free(temp_list);
      return 0.0;
    }
  }
  //小数部分
  while (fract_list->next != NULL)
  {
    if (is_number(*(char *)fract_list->val))
    {
      temp_dec = (temp_dec + *(char *)fract_list->val - '0') * 0.1;
      fract_list = fract_list->next;
    }
    else
    {
      printf("\n----------------****----------------\nERROR!\nThere are INVALID characters in DECIMAL number.\nPlease check your input or COMFIRM the type of list value is CHAR!\n----------------****----------------\n");
      list_del_innate(fract_list);
      return 0.0;
    }
  }
  temp_list = NULL;
  free(temp_list);
  list_del_innate(fract_list);
  return (temp_int + temp_dec) * sign;
}
node_data *list_del_val(node_data *data_list, void *val, uint (*comp)(void *, void *))
{
  node_data *temp_now = list_inv_cpy(data_list);
  node_data *temp_list = (node_data *)calloc(1, sizeof(node_data));
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