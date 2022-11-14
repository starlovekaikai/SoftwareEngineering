/*by陈博非，链表库，用于存放不定大小的数据，如多边形或者组合图形*/
#include <stdlib.h>
#include "my_ctype.h"
#include <malloc.h>
#include <assert.h>
#include "my_list.h"
#include <stdio.h>
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct node_data
{
  byte *val; //指向类型不定的数据，使用字节存放其初始地址
  uint size; //对应数据的字节数，上限是2^31-1，已经非常大了
  struct node_data *next;
} node_data;
p_list_v list_new()
{
  p_list_v temp = (p_list_v)malloc(sizeof(node_data));
  temp->size = 0;
  temp->next = NULL;
  temp->val = NULL;
  return temp;
}
p_list_v list_new_blank()
{
  p_list_v temp = (p_list_v)malloc(sizeof(node_data));
  temp->size = 0;
  temp->next = NULL;
  temp->val = NULL;
  return temp;
}
byte *node_val(p_list_c node)
{
  assert(node != NULL);
  return node->val;
}
p_list_v node_next(p_list_c node)
{
  assert(node != NULL);
  return node->next;
}
uint node_size(p_list_c node)
{
  assert(node != NULL);
  return node->size;
}
void node_del(p_list_v node_pre, p_list_v node_now)
{
  assert(node_pre != NULL && node_now != NULL);
  node_pre->next = node_now->next;
  my_free(node_now->val, node_now->size);
  free(node_now);
  node_now = node_pre->next;
}
p_list_v list_new_val(void *val, uint size)
{
  p_list_v temp = (p_list_v)malloc(sizeof(node_data));
  temp->size = size;
  temp->next = NULL;
  temp->val = (byte *)malloc(size * sizeof(byte));
  my_memcpy(temp->val, val, size);
  return temp;
}
uint data_size(p_list_c data_list)
{
  p_list_v temp = (p_list_v)malloc(sizeof(node_data));
  temp = list_inv_cpy(data_list);
  uint temp_size = 0;
  while (temp->next != NULL)
  {
    temp_size += temp->size;
    temp = temp->next;
  }
  temp = NULL;
  free(temp);
  return temp_size;
}
p_list_v list_cat(p_list_v data_list, void *data_next, uint size)
{
  assert(data_list != NULL && data_next != NULL && &size != NULL);
  p_list_v temp = list_new_val(data_next, size);
  my_memcpy(temp->val, data_next, size);
  temp->next = data_list;
  return temp;
}

void *list_out(p_list_v data_list)
{
  assert(data_list != NULL);
  p_list_v temp = data_list;
  void *out_val = (void *)malloc(data_list->size * sizeof(char));
  my_memcpy(out_val, data_list->val, data_list->size);
  free(data_list->val);
  data_list = data_list->next;
  free(temp);
  return out_val;
}

void list_del_innate(p_list_v data_list)
{
  assert(data_list != NULL);
  p_list_v temp = (p_list_v)malloc(sizeof(node_data));
  while (data_list->next != NULL)
  {
    temp = data_list->next;
    free(data_list);
    data_list = temp;
  }
  data_list = NULL;
  free(data_list);
  temp = NULL;
  free(temp);
}
void list_del_usr(p_list_v data_list)
{
  assert(data_list != NULL);
  p_list_v temp = list_new_blank();
  while (data_list->next != NULL)
  {
    my_free(data_list->val, data_list->size);
    temp = data_list->next;
    free(data_list);
    data_list = temp;
  }
  my_free(data_list->val, data_list->size);
  free(data_list);
}
uint list_len(p_list_c data_list)
{
  assert(data_list != NULL);
  uint iter = 0;
  p_list_v temp = (p_list_v)malloc(sizeof(node_data));
  temp = list_inv_cpy(data_list);
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
uint list_emp(p_list_c data_list)
{
  assert(data_list != NULL);
  if (data_list->next == NULL)
  {
    return _IS_EMPTY_;
  }
  else
  {
    return _NOT_EMPTY_;
  }
}
p_list_v list_data_cpy(p_list_c data_list)
{
  uint temp_size = data_size(data_list);
  uint temp_len = list_len(data_list);
  p_list_v temp = list_new();
  my_memcpy(temp, list_inv_cpy(data_list), sizeof(node_data));
  uint i = 0;
  p_list_v temp_list = list_new_blank();
  while (i < temp_len)
  {
    temp_list = list_cat(temp_list, temp->val, temp->size);
    temp = temp->next;
    i++;
  }
  temp = NULL;
  free(temp);
  if (temp_list->next != NULL)
  {
    return temp_list;
  }
  else
  {
    return NULL;
  }
}
p_list_v list_inv_cpy(p_list_c data_list)
{
  assert(data_list != NULL);
  p_list_v temp_list = list_new();
  my_memcpy(temp_list, data_list, sizeof(node_data));
  p_list_v temp = list_new_blank();
  while (temp_list->next != NULL)
  {
    temp = list_cat(temp, temp_list->val, temp_list->size);
    temp_list = temp_list->next;
  }
  temp_list = NULL;
  free(temp_list);
  return temp;
}

p_list_v list_cpy(p_list_c data_list)
{
  assert(data_list != NULL);
  p_list_v temp1 = list_inv_cpy(data_list);
  p_list_v temp2 = list_inv_cpy(temp1);
  list_del_innate(temp1);
  return temp2;
}

void list_prt(p_list_c data_list, void *buff)
{
  assert(data_list != NULL && buff != NULL);
  uint i = 0;
  p_list_v temp = list_inv_cpy(data_list);
  while (temp->next != NULL)
  {
    my_memcpy((buff + i), temp->val, temp->size);
    temp = temp->next;
    i++;
  }
  temp = NULL;
  free(temp);
}
byte *byte_from_list(p_list_c data_list)
{
  assert(data_list != NULL);
  uint i = 0;
  uint size = data_size(data_list);
  p_list_v temp_list = list_inv_cpy(data_list);
  p_list_v temp = temp_list;
  byte *buff = (byte *)malloc(size * sizeof(byte));
  while (temp->next != NULL)
  {
    my_memcpy(buff + i, temp->val, temp->size);
    i += temp->size;
    temp = temp->next;
  }
  list_del_innate(temp);
  return buff;
}
void *list_ind(p_list_c data_list, uint ind, uint size)
{
  assert(data_list != NULL);
  uint iter = 0;

  p_list_v data_inv = list_inv_cpy(data_list);
  p_list_v temp_inv = data_inv;
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
  void *temp = (void *)malloc(data_inv->size * sizeof(byte));
  my_memcpy(temp, data_inv->val, data_inv->size);
  size = data_inv->size;
  list_del_innate(temp_inv);
  return temp;
}
p_list_v list_sub(p_list_c data_list, uint ind, uint len)
{
  assert(data_list != NULL);
  p_list_v temp_list = list_inv_cpy(data_list);
  p_list_v data_temp = temp_list;
  p_list_v temp = list_new_blank();
  uint iter = 0;
  while (iter < ind)
  {
    if (data_temp->next == NULL)
    {
      list_del_innate(temp_list);
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
      list_del_innate(temp_list);
      return list_inv_cpy(temp);
    }
    temp = list_cat(temp, data_temp->val, data_temp->size);
    data_temp = data_temp->next;
    iter++;
  }
  list_del_innate(temp_list);
  return list_inv_cpy(temp);
}
int int_from_list(p_list_c data_list)
{
  assert(data_list != NULL);
  int temp = 0, sign = 1;
  p_list_v temp_list = list_new();
  my_memcpy(temp_list, data_list, sizeof(node_data));
  if (*(byte *)temp_list->val == '-')
  {
    sign = -1;
    temp_list = temp_list->next;
  }
  do
  {
    if (is_number(*(byte *)temp_list->val))
    {
      temp = temp * 10 + *(byte *)temp_list->val - '0';
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
float float_from_list(p_list_c data_list)
{
  assert(data_list != NULL);
  float temp_int = 0, temp_dec = 0, sign = 1.0;
  p_list_v temp_list = list_new();
  my_memcpy(temp_list, data_list, sizeof(node_data));
  p_list_v fract_list = list_new_blank();
  if (*(byte *)(temp_list->val) == '-')
  {
    sign = -1.0;
    temp_list = temp_list->next;
  }
  //整数部分
  while (temp_list->next != NULL)
  {
    if (*(byte *)(temp_list->val) == '.')
    {
      temp_list = temp_list->next;
      fract_list = list_inv_cpy(temp_list);
      break;
    }
    else if (is_number(*(byte *)temp_list->val))
    {
      temp_int = temp_int * 10 + *(byte *)temp_list->val - '0';
      temp_list = temp_list->next;
    }
    else
    {
      printf("\n----------------****----------------\nERROR!\nThere are INVALID characters in DECIMAL number.\nPlease check your input or COMFIRM the type of list value is CHAR!\n----------------****----------------\n");
      free(fract_list);
      temp_list = NULL;
      free(temp_list);
      return 0.0;
    }
  }
  //小数部分
  while (fract_list->next != NULL)
  {
    if (is_number(*(byte *)fract_list->val))
    {
      temp_dec = (temp_dec + *(byte *)fract_list->val - '0') * 0.1;
      fract_list = fract_list->next;
    }
    else
    {
      printf("\n----------------****----------------\nERROR!\nThere are INVALID characters in DECIMAL number.\nPlease check your input or COMFIRM the type of list value is CHAR!\n----------------****----------------\n");
      list_del_innate(fract_list);
      temp_list = NULL;
      free(temp_list);
      return 0.0;
    }
  }
  list_del_innate(fract_list);
  temp_list = NULL;
  free(temp_list);
  return (temp_int + temp_dec) * sign;
}
void my_memcpy(void *dest, const void *src, uint count)
{
  assert(dest != NULL && src != NULL);

  byte *p = (byte *)dest;
  byte *q = (byte *)src;
  if (p == q)
  {
    printf("Warning!The destination and source address is the same.");
    return;
  }

  while (count--)
  {
    *p = *q;
    p++;
    q++;
  }
}
void my_free(void *data, uint size)
{
  byte *p = (byte *)data;
  while (size--)
  {
    free(p);
    p++;
  }
}