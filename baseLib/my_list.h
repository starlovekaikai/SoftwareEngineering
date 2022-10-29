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
//链表中按规定值分割，得到一个复合链表，既元素也是链表的链表
node_data *list_clp(node_data *data_list, uint (*rule)(void *, void *));
//输入括号匹配（一边接收输入一边就完成了括号匹配），得到一个非常复杂的嵌套链表
node_data *list_get_std();
//从文件中得到输入
node_data *list_get_file(char *file_path);
//按元素遍历运算（便于将来的大小写匹配和汉字匹配等）
node_data *list_itm_op(node_data *data_list, void **(*op)(void *));
//特别地，从字符型链表返回一个int型数值
int int_from_char_list(node_data *data_list);
//特别地，从字符型链表返回一个float型数值
float float_from_char_list(node_data *data_list);
