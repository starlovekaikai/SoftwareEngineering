#include "my_math.h"
/*
 * This function uses a ui_point, a length value
 * and a unit vector to form a line eqution and
 * returns a quantified coordinate in axe "y".
 *
 * - point   : the beginning point in the ui coordinate（图形坐标下，单位是像素）
 * - len     : the length of line
 * - uni_vec : a unit vector representing the
 *             direction of line.
 * - x_val   : the x axe coordinate of input
 *             point
 *  Output   : the y axe coordinate of input
 *             point
 */
int line_equ(shape line, int x_val)
{
  ui_point point = line.point;
  vector uni_vec = line.vec;
  float dx, dy;
  dx = x_val - point.x_val;
  // zero是非常小的一个数，防止除数为0的
  if (abs(uni_vec.x_com) < ZERO)
  {
    dy = 0;
  }
  else
  {
    dy = dx * uni_vec.y_com / uni_vec.x_com;
  }
  return (int)point.y_val + dy;
}
/*
 * This function uses a ui_point, a length value
 * and a unit vector to form a circle eqution and
 * returns a quantified coordinate in axe "y".
 *
 * - point   : the beginning point in the ui coordinate（图形坐标下，单位是像素）
 * - len     : the length of radius
 * - uni_vec : a unit vector representing the
 *             direction of circle.
 * - x_val   : the x axe coordinate of input
 *             point
 *  Output   : the y axe coordinate of input
 *             point
 */
//只考虑为y值为正的情况，为负另一半取反就可以生成了
int circle_equ(ui_point center, int radius, vector uni_vec, int x_val)
{
}
/*
 * This function uses a ui_point, a length value
 * and a unit vector to form a polygon eqution and
 * returns a quantified coordinate in axe "y".
 *
 * - point   : the beginning point in the ui coordinate（图形坐标下，单位是像素）
 * - len     : the length of radius
 * - uni_vec : a unit vector representing the
 *             direction of circle.
 * - x_val   : the x axe coordinate of input
 *             point
 *  Output   : the y axe coordinate of input
 *             point
 */
//只考虑为y值为正的情况，为负另一半取反就可以生成了
int polygon_equ(ui_point center, int radius, vector uni_vec, int x_val)
{
  float dx, dy;
}