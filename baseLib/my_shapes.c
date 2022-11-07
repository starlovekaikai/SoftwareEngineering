#include "my_shapes.h"
#include "my_list.h"
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
p_list_c p_apex_list;

} poly;
