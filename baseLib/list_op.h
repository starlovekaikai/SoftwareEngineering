#ifndef _LIST_OP_
#define _LIST_OP_
#endif
#include "my_list.h"
//链表中查找某一元素并删除包含该元素的全部节点，原链表保持不变
p_list_v list_del_val(p_list_v data_list, uint (*cond)(void *, uint));
//两个链表，取最小长度
uint lists_len_min(p_list_c data_list_a, p_list_c data_list_b);
/*
 * 两个链表，取同样长度的前面元素，按元素遍历运算，便于定义链表比较等函数
 * 返回一个运算结果的数组
 */
p_list_v lists_itm_op(p_list_v data_list_a, p_list_v data_list_b, void *(*op)(void *, void *, uint));
//按元素遍历运算（便于将来的大小写匹配和汉字匹配等）
p_list_v list_itm_op(p_list_v data_list, void (*op)(void *, uint));
//删除链表首尾的无效数据（如空格）而保留中间的数据不动
p_list_v list_del_bil(p_list_v data_list, uint (*cond)(void *, uint));
