#include <stdlib.h>
#define NULL ((void *)0)
#define _IS_EMPTY_ 1
#define _NOT_EMPTY_ 0
typedef unsigned int uint;
typedef struct node_data
{
  void *val;
  struct node_data *next;
} node_data;
node_data *new_empty_list()
{
  node_data *temp = (node_data *)calloc(1, sizeof(node_data));

  temp->next = NULL;
  temp->val = NULL;
}
node_data *list_cat(node_data *data_list, void *data_next)
{
  node_data *temp = (node_data *)calloc(1, sizeof(node_data));
  temp->val = data_next;
  temp->next = data_list;
  return temp;
}
void *list_out(node_data *data_list)
{
  void *temp = data_list->val;
  free(data_list->next);
  return temp;
}
uint list_is_empty(const node_data *data_list)
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
node_data *list_inv_cpy(const node_data *src_list)
{
  node_data *temp = new_empty_list();
  while (src_list->next != NULL)
  {
    temp = list_cat(temp, src_list->val);
    src_list = src_list->next;
  }
  return temp;
}
node_data *list_inv(node_data *src_list)
{
  node_data *temp = new_empty_list();
  while (src_list->next != NULL)
  {
    temp = list_cat(temp, src_list->val);
    src_list = src_list->next;
  }
  free(src_list);
  return temp;
}
uint list_len(node_data *data_list)
{
  uint iter=0;
  while (data_list->next != NULL)
  {
    iter++;
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
void **print_list(node_data *data_list)
{
  uint i = 0;
  void **buff = (void **)calloc(list_len(data_list), sizeof(void *));
  while (data_list->next != NULL)
  {
    *(buff + i) = (data_list->val);
    data_list = data_list->next;
    i++;
  }
  return buff;
}
void list_del(node_data *data_list)
{
  free(data_list);
}