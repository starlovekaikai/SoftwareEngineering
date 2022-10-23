#include "my_math.h"
#include "src_comm.h"
/*
 * This function uses 2 ui_points to form a line 
 * eqution and returns a quantified coordinate in 
 * axe "y".
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
int line_equ(ui_point point, int len, vector uni_vec, int x_val)
{
  //其实这个长度len是没有用的，因为这里不需要它，只是保留着
  float dx,dy;
  
}