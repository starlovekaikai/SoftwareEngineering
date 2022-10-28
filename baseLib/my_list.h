#ifndef _MY_LIST_
#define _MY_LIST_
#endif
#include "my_list.c"
//新建
node_data *new_empty_list();
//压栈
node_data *list_cat(node_data *data_list, void *data_next);
//弹栈
void *list_out(node_data *data_list);
//栈判空
uint list_is_empty(const node_data *data_list);
//反向复制
node_data *list_inv_cpy(const node_data *src_list);
//按输入顺序反序打印为任意类型的数组，可能会报警告
void **print_list(node_data *data_list);
//清空
void list_del(node_data *data_list);
//取长度，时间成本大
uint list_len(node_data *data_list);
