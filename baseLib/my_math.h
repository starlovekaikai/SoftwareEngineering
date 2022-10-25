#ifndef _BASE_LIB_
#define _BASE_LIB_
#endif
#ifndef UI_SIZE_X
#define UI_SIZE_X 512
#define UI_SIZE_Y 512
#endif
#define ZERO 1e-6
#include "my_math.c"
//绘图坐标系下的点，坐标值的单位是像素pixel
typedef struct ui_point
{
  int x_val;
  int y_val;
} ui_point;
//用户界面坐标下的点，坐标值的单位不是像素。
typedef struct user_point
{
  int x_val;
  int y_val;
} user_point;
//向量
typedef struct vector
{
  //两个坐标轴上的分量component
  float x_com;
  float y_com;
} vector;
//存放全部形状的数据
typedef struct shape
{
  //某一形状需要的一个点数据
  ui_point point;
  //某一形状需要的一个向量数据，可以是单位向量也可以不是
  vector vec;
  /* 
   * 某一形状需要的其他的一些数据，类型待定，可以是标量数据，如半径、长度或者其他什么的，也可以是矢量数据，
   * 使用的不完全类型定义以备用。
   * 强制类型转化后可以存储相应的数据，例子见直线方程。
   *
   * 如何使用这几个备用的类型待定数据，可以按以下例子：
   * 例如，在圆的数据中，需要一个半径，则可以
   * //circle是一个shape类型的结构体变量
   * int* radius = (int *)calloc(1,sizeof(int));
   * *radius = 50;//需要或已知的半径
   * circle.val_1 = radius;//让不完全定义的指针强制类型为int并将其指向的内容初始化为radius指针的值，即50
   * //调用不完全定义类型时，需要如下使用其值：
   * *(int*)circle.val_1，这种形式可以进行运算之类的。
   * //这里就把val_1强制转化成了int类型的数据，并求取指向的内容（即括号的*），得到了相应的半径数据
   * 详细的例子见test.c
   */
  void *val_1, *val_2, *val_3;
} shape;

//已知一个图形点，一个长度和一个方向矢量，求一个直线方程
int line_equ(shape line, int x_val);
//已知圆心图形点，一个半径长度和一个方向矢量（这个参数先不管，到时候如果要画不完整的圆弧再用），求一个圆的方程
int circle_equ(shape circle, int x_val);
//已知圆心图形点，一个半径长度和一个初始方向矢量，求一个正多边形的方程？
int polygon_equ(shape polygon, int x_val);
//求坐标系的旋转变换
//求坐标系的平移变换
//求坐标系的伸缩变换

