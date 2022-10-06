#ifndef _my_ctype_new_H_INCLUDE_
#define  _my_ctype_new_H_INCLUDE_
/*
IsNumber用于判断字符是否为数字字符
input：字符c
output：是返回1，否返回0
*/
int IsNumber(char c);
/*
IsAlpha用于判断字符是否为字母字符
input：字符c
output：是返回1，否返回0
*/
int IsAlpha(char c);
/*
IsAlandNum用于判断字符是否为数字字符和字母
input：字符c
output：是返回1，否返回0
*/
int IsAlandNum(char c);
/*
IsInvisible用于判断字符是否为不可见字符
input：字符c
output：是返回1，否返回0
*/
int IsInvisible(char c);
/*
IsTable用于判断字符是否为制表符
input：字符c
output：是返回1，否返回0
*/
int IsTable(char c);
/*
IsSpace用于判断字符是否为空格符
input：字符c
output：是返回1，否返回0
*/
int IsSpace(char c);
/*
IsUpper用于判断字符是否为大写字母字符
input：字符c
output：是返回1，否返回0
*/
int IsUpper(char c);
/*
IsLower用于判断字符是否为小写字母字符
input：字符c
output：是返回1，否返回0
*/
int IsLower(char c);
/*
Upper2Lower用于将字母字符转换为大写
input：字符c
output：当输入是合法字母字符时返回对应大写，否则返回'\0'
*/
char Upper2Lower(char c);
/*
Lower2Upper用于将字母字符转换为小写
input：字符c
output：当输入是合法字母字符时返回对应小写，否则返回'\0'
*/
char Lower2Upper(char c);

#endif