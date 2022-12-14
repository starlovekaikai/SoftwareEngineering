/*by张国勇，形状库，存放不同的形状信息，用于从源命令行到目标数据体的转换*/
#include "my_shapes.h"
#include "my_list.h"
#include <assert.h>
#include <malloc.h>
typedef struct point
{
  float x_val;
  float y_val;
} point;
typedef struct line
{
  point point_1;
  point point_2;
} line;
typedef struct circ
{
  point center;
  float radius;
} circ;
typedef struct rect
{
  point left_up;
  point right_down;
} rect;
typedef struct poly
{
  uint num_apex;
  p_list_c p_apex_list;
} poly;
typedef struct group
{
  uint num_shape;
  p_list_c p_shape_list;
} gtoup;
void read_point(p_point_c point, float *x_val, float *y_val)
{
  *x_val = point->x_val;
  *y_val = point->y_val;
}
void read_line_point(p_line_c line, p_point_v point_1, p_point_v point_2)
{
  my_memcpy(point_1, &(line->point_1), sizeof(point));
  my_memcpy(point_2, &(line->point_2), sizeof(point));
}
//实际上，矩形的存储与线是一样的，都是两个点的坐标，但为了区分，还是单独写一个read_rect_point函数
void read_rect_point(p_rect_c rect, p_point_v point_1, p_point_v point_2)
{
  my_memcpy(point_1, &(rect->left_up), sizeof(point));
  my_memcpy(point_2, &(rect->right_down), sizeof(point));
}
