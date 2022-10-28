#ifndef _MY_LIST_
#define _MY_LIST_
#endif
#include "my_list.c"
//新建
node_data *list_new();
//压栈
node_data *list_cat(node_data *data_list, void *data_next);
/*
 * 弹出最上层的一个元素，可以为任意类型
 * 使用方法：
 * void **M = (void **)calloc(len, sizeof(void *));
 * M = print_list(sub_list);
 * char d = *(char *)(*(M + i));
 * 改变指针强制类型转换的类型名即可实现调用任意类型数据
 * 
 */
void **list_out(node_data *data_list);
//栈判空
uint list_emp(const node_data *data_list);
//反向复制
node_data *list_inv_cpy(node_data *data_list);
//正向复制
node_data *list_cpy(node_data *data_list);
/*
 * 按输入顺序反序打印为任意类型的数组，可能会报警告
 * 使用方法：
 * void **M = (void **)calloc(len, sizeof(void *));
 * M = print_list(sub_list);
 * char d = *(char *)(*(M + i));
 * 改变指针强制类型转换的类型名即可实现打印任意类型数据
 * 
 */
void **list_prt(node_data *data_list);
//清空
void list_del(node_data *data_list);
//取长度，使用的是循环，时间成本大，能不用就不用
uint list_len(node_data *data_list);
//返回某一索引值
void **list_ind(node_data *data_list, uint ind);
//返回某一节点索引的值
void **list_nod(node_data*node);
/*
 * 返回某一子列
 * 输入参数：源列表指针data_list，子列在原列表上的起始位置ind，子列长度len
 * 输出参数：子列表指针
 *
 */
node_data *list_sub(node_data *data_list, uint ind, uint len);
//查找某一元素，返回一个链表，其对应于本节点索引和后一个节点索引
node_data*list_fid_val(node_data*data_list,void*val);
//查找某一元素串，返回一个链表，其对应于本节点索引和邻接的下一个索引
node_data*list_fid_sub(node_data*data_list,void*str);
//链表中删除某一节点
node_data*list_del_nod(node_data*data_list,node_data*node);
//链表中删除某一连续节点
node_data*list_del_sub(node_data*data_list,node_data*sub_node);
//特别地，从字符型链表返回一个int型数值
int int_from_char_list(node_data *data_list);
//特别地，从字符型链表返回一个float型数值
float float_from_char_list(node_data *data_list);
