#ifndef _BASE_LIB_
#define _BASE_LIB_
#endif
#ifndef UI_SIZE_X
#define UI_SIZE_X 512
#define UI_SIZE_Y 512
#endif
#define ZERO 1e-6
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
//已知一个图形点，一个长度和一个方向矢量，求一个直线方程
int line_equ(ui_point point, int len, vector uni_vec, int x_val);
//已知圆心图形点，一个半径长度和一个方向矢量（这个参数先不管，到时候如果要画不完整的圆弧再用），求一个圆的方程
int circle_equ(ui_point center, int radius, vector uni_vec, int x_val);
//已知圆心图形点，一个半径长度和一个初始方向矢量，求一个正多边形的方程？
int polygon_equ(ui_point center, int radius, vector uni_vec, int x_val);
