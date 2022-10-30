#ifndef _LIST_OP_
#define _LIST_OP_
#endif
//链表中查找某一元素并删除包含该元素的全部节点
node_data *list_del_val(node_data *data_list, void *val, uint (*comp)(void *, void *));
//两个链表，取最小长度
uint lists_len_min(node_data *data_list_a, node_data *data_list_b);
//两个链表，取同样长度的前面元素，按元素遍历运算，便于定义链表比较等函数
void **lists_itm_op(node_data *data_list_a, node_data *data_list_b, void **(*op)(void *, void *), uint len);
//按元素遍历运算（便于将来的大小写匹配和汉字匹配等）
node_data *list_itm_op(node_data *data_list, void **(*op)(void *));
//删除链表首尾的无效数据（如空格）而保留中间的数据不动
node_data *list_del_bil(node_data *data_list, uint (*cond)(void *));
void *memcpy(void *dest, const void *src, size_t count);