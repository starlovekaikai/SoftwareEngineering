#include "my_shapes.h"
#include "my_list.h"
#include <assert.h>
typedef struct point
{
  float x_val;
  float y_val;
} point;
typedef struct circle
{
  point center;
  float radius;
} circ;
typedef struct rectangle
{
  point left_up;
  point right_down;
} rect;
typedef struct polygon
{
  uint num_apex;
  p_list_c p_apex_list;
} poly;
typedef struct group
{
  uint num_shape;
  p_list_c p_shape_list;
} gtoup;