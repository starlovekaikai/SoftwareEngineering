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
void read_line_point(p_line_c line, p_point_v point_1, p_point_v point_2)
{
  p_point_v line_points = (p_point_v)malloc(2 * sizeof(point));
}