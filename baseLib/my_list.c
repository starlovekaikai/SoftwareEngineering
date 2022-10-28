#include <stdlib.h>
#include "my_ctype.h"
#define NULL ((void *)0)
#define _IS_EMPTY_ 1
#define _NOT_EMPTY_ 0
typedef unsigned int uint;
typedef struct node_data
{
  void *val;
  struct node_data *next;
} node_data;
node_data *list_new()
{
  node_data *temp = (node_data *)calloc(1, sizeof(node_data));
  temp->next = NULL;
  temp->val = NULL;
}
node_data *list_new_val(void *val)
{
  node_data *temp = (node_data *)calloc(1, sizeof(node_data));
  temp->next = val;
  temp->val = NULL;
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
void list_del(node_data *data_list)
{
  node_data *temp = (node_data *)calloc(1, sizeof(node_data));
  temp = data_list;
  while (data_list->next != NULL)
  {
    free(data_list->val);
    temp = data_list;
    data_list = data_list->next;
    free(temp);
  }
  free(data_list->val);
  free(data_list->next);
  free(data_list);
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
  list_del(data_list);
  return temp;
}
void list_cpy(node_data *src_list, node_data *dst_list)
{
  node_data *temp1 = list_inv_cpy(src_list);
  dst_list = list_inv_cpy(temp1);
  list_del(src_list);
}
uint list_len(node_data *data_list)
{
  uint iter = 0;
  node_data *temp = data_list;
  while (temp->next != NULL)
  {
    iter++;
    temp = temp->next;
  }
  return iter;
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
  node_data *temp = data_list;
  while (temp->next != NULL)
  {
    *(buff + i) = (temp->val);
    temp = temp->next;
    i++;
  }
}

void **list_ind(node_data *data_list, uint ind)
{
  uint iter = 0;
  void **temp = (void **)calloc(1, sizeof(void *));
  node_data *data_inv = list_inv(data_list);
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
      return list_inv(temp);
    }
    temp = list_cat(temp, data_temp->val);
    data_temp = data_temp->next;
    iter++;
  }
  return list_inv(temp);
}
int int_from_char_list(node_data *data_list)
{
  int temp = 0, sign = 1;
  node_data *temp_list = data_list;
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
      return 0;
    }
  } while (temp_list->next != NULL);
  return temp * sign;
}
float float_from_char_list(node_data *data_list)
{
  float temp_int = 0, temp_dec = 0, sign = 1.0;
  node_data *temp_list = data_list;
  char temp_char = *(char *)temp_list->val;
  if (temp_char == '-')
  {
    sign = -1.0;
    temp_list = temp_list->next;
  }
  //整数部分
  do
  {
    if (*(char *)(temp_list->val) == '.')
    {
      temp_list = temp_list->next;
      temp_list = list_inv(temp_list);
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
      return 0.0;
    }
  } while (temp_list->next != NULL);
  //小数部分
  while (temp_list->next != NULL)
  {
    if (is_number(*(char *)temp_list->val))
    {
      temp_dec = (temp_dec + *(char *)temp_list->val - '0') * 0.1;
      temp_list = temp_list->next;
    }
    else
    {
      printf("\n----------------****----------------\nERROR!\nThere are INVALID characters in DECIMAL number.\nPlease check your input or COMFIRM the type of list value is CHAR!\n----------------****----------------\n");
      return 0.0;
    }
  }
  return (temp_int + temp_dec) * sign;
}
node_data *list_del_val(node_data *data_list, void *val, int (*comp)(void *, void *))
{
  node_data *temp_list = list_inv(data_list);
  node_data *temp = list_new();
  while (temp_list->next != NULL)
  {

    if (comp(val, temp_list->val))
    {
      temp->next = temp_list->next;
      free(temp_list->val);
      free(temp_list);
      temp_list = temp->next;
    }
    else
    {
      temp = temp_list;
      temp_list = temp_list->next;
    }
  }
  list_del(data_list);
  return temp_list;
}