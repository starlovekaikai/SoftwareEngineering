#ifndef _MY_SRC_
#define _MY_SRC_
#endif
#include "my_src.c"
//比较两个链表的内容，类型待定义
uint lists_cmp(node_data *data_list_a, node_data *data_list_b, void **(*op)(void *, void *));
//强制把链表内容格式化为字符类型，进行比较
uint list_char_cmp(node_data *data_list_a, node_data *data_list_b);
//链表中按规定值分割，得到一个复合链表，既元素也是链表的链表
node_data *list_clp(node_data *data_list, uint (*rule)(void *, void *));
//输入括号匹配（一边接收输入一边就完成了括号匹配），得到一个非常复杂的嵌套链表
char *list_get_std(uint *char_out);
//从文件中得到输入
node_data *list_get_file(char *file_path);
//强制把链表内容格式化为2元数类型（主要是点）
point *pnt_from_char_list(node_data *data_list);
