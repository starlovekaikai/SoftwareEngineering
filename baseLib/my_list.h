#ifndef _MY_LIST_
#define _MY_LIST_
#endif
#define _IS_EMPTY_ 1
#define _NOT_EMPTY_ 0
typedef unsigned int uint;
typedef char byte;
struct node_data;
typedef struct node_data *p_list_v;
typedef const struct node_data *p_list_c;
//新建
p_list_v list_new();
//新建
p_list_v list_new_blank();
//从一个值新建
p_list_v list_new_val(void *val, uint size);
//从一个数组新建
// p_list_ list_new_arr(void **arr, uint size);
//输出节点值
byte *node_val(p_list_c node);
//输出下一个节点地址
p_list_v node_next(p_list_c node);
//删除一个节点
void node_del(p_list_v node_pre, p_list_v node_now);
//输出节点指向的数据的内存字节数
uint node_size(p_list_c node);
//返回一个链表对应数据所占的全部内存大小，单位是字节数
uint data_size(p_list_c data_list);
//压栈
p_list_v list_cat(p_list_v data_list, void *data_next, uint size);
/*
 * 弹出最上层的一个元素，可以为任意类型
 * 使用方法：
 * void **M = (void **)calloc(len, sizeof(void *));
 * M = print_list(sub_list);
 * char d = *(char *)(*(M + i));
 * 改变指针强制类型转换的类型名即可实现调用任意类型数据
 *
 */
void *list_out(p_list_v data_list);
//栈判空
uint list_emp(const p_list_c data_list);
//真正的复制，内存中要新增存放数据的空间
p_list_v list_data_cpy(p_list_c data_list);
//指向的数据不改变，反向复制链表指针，在内存中不新增存放数据的空间
p_list_v list_inv_cpy(p_list_c data_list);
//指向的数据不改变，正向复制链表指针，在内存中不新增存放数据的空间
p_list_v list_cpy(p_list_c data_list);
/*
 * 按输入顺序反序打印为任意类型的数组，可能会报警告
 * 使用方法：
 * void **M = (void **)calloc(len, sizeof(void *));
 * M = print_list(sub_list);
 * char d = *(char *)(*(M + i));
 * 改变指针强制类型转换的类型名即可实现打印任意类型数据
 *
 */
void list_prt(p_list_c data_list, void *buff);
//按字节打印，便于进行复制，从链表起始开始，按输入顺序逐字节打印
byte *byte_from_list(p_list_c data_list);
//内部使用清空，只删除指针不删除数据
void list_del_innate(p_list_v data_list);
//用户使用清空，数据和指针通通归零
void list_del_usr(p_list_v data_list);
/*
 * 取长度，注意与字节数不一定相等，
 * 因为链表里面的数据不一定都是同一类型的，
 * 且存放的数据不一定都是一个字节的
 */
uint list_len(p_list_c data_list);
//返回某一索引值
void *list_ind(p_list_c data_list, uint ind, uint size);
/*
 * 返回某一子列
 * 输入参数：源列表指针data_list，子列在原列表上的起始位置ind，子列长度len
 * 输出参数：子列表指针
 *
 */
p_list_v list_sub(p_list_c data_list, uint ind, uint len);

//特别地，从字符型链表返回一个int型数值
int int_from_list(p_list_c data_list);
//特别地，从字符型链表返回一个float型数值
float float_from_list(p_list_c data_list);
//内存拷贝函数原型，只能复制一系列连续地址指向的值
void my_memcpy(void *dest, const void *src, uint count);
//释放内存的函数，释放从指针指向地址开始的连续一定数量字节内存
void my_free(void *data, uint size);