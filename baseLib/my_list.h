#ifndef _MY_LIST_
#define _MY_LIST_
#endif
#include "my_list.c"
typedef unsigned int uint;
typedef struct node_data node_data;
//新建
node_data *list_new();
//从一个值新建
node_data *list_new_val(void *val);
//压栈
node_data *list_cat(node_data *data_list, void *data_next);
//入队
node_data *list_que(node_data *data_list, void *data_next);
/*
 * 弹出最上层的一个元素，可以为任意类型
 * 使用方法：
 * void **M = (void **)calloc(len, sizeof(void *));
 * M = print_list(sub_list);
 * char d = *(char *)(*(M + i));
 * 改变指针强制类型转换的类型名即可实现调用任意类型数据
 *
 */
void list_out(node_data *data_list, void *out_val);
//栈判空
uint list_emp(const node_data *data_list);
//反向复制，保留源数据
node_data *list_inv_cpy(node_data *data_list);
//不保留源数据，使数据反向
node_data *list_inv(node_data *data_list);
//正向复制，保留源数据
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
void list_prt(node_data *data_list, void **buff);
//内部使用清空，只删除指针不删除数据
void list_del_innate(node_data *data_list);
//用户使用清空，数据和指针通通归零
void list_del(node_data *data_list);
//取长度，使用的是循环，时间成本大，能不用就不用
uint list_len(node_data *data_list);
//返回某一索引值
void **list_ind(node_data *data_list, uint ind);
//返回某一节点索引的值
void **list_nod(node_data *node);
/*
 * 返回某一子列
 * 输入参数：源列表指针data_list，子列在原列表上的起始位置ind，子列长度len
 * 输出参数：子列表指针
 *
 */
node_data *list_sub(node_data *data_list, uint ind, uint len);
//链表中查找某一元素并删除包含该元素的全部节点
node_data *list_del_val(node_data *data_list, void *val, uint (*comp)(void *, void *));
//两个链表，取最小长度
uint lists_len_min(node_data *data_list_a, node_data *data_list_b);
//两个链表，取同样长度的前面元素，按元素遍历运算，便于定义链表比较等函数
void **lists_itm_op(node_data *data_list_a, node_data *data_list_b, void **(*op)(void *, void *), uint len);
//按元素遍历运算（便于将来的大小写匹配和汉字匹配等）
node_data *list_itm_op(node_data *data_list, void **(*op)(void *));
//特别地，从字符型链表返回一个int型数值
int int_from_char_list(node_data *data_list);
//特别地，从字符型链表返回一个float型数值
float float_from_char_list(node_data *data_list);
//删除链表首尾的无效数据（如空格）而保留中间的数据不动
node_data *list_del_bil(node_data *data_list, uint (*cond)(void *));
void *memcpy(void *dest, const void *src, size_t count);