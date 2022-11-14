/*by张国勇，形状库，存放不同的形状信息，用于从源命令行到目标数据体的转换*/
#ifndef _MY_SHAPES_
#define _MY_SHAPES_

#ifdef __cplusplus
extern "C"
{
#endif
  //形状类型的定义
  struct point;
  struct line;
  struct circ;
  struct rect;
  struct poly;
  typedef const struct point *p_point_c;
  typedef struct point *p_point_v;
  typedef const struct line *p_line_c;
  typedef struct line *p_line_v;
  typedef const struct circ *p_circ_c;
  typedef struct circ *p_circ_v;
  typedef const struct rect *p_rect_c;
  typedef struct rect *p_rect_v;
  typedef const struct poly *p_poly_c;
  typedef struct poly *p_poly_v;
  //创建点
  p_point_v new_point();
  //调用形状的函数
  float read_x_point(p_point_c point);
  float read_y_point(p_point_c point);
  //读取直线的数据
  void read_line_point(p_line_c line, p_point_v point_1, p_point_v point_2);
  //读取矩形的数据
  void read_rect_point(p_rect_c rect, p_point_v point_1, p_point_v point_2);

  float read_circ_radius(p_circ_c circ);
  p_point_v read_circ_center(p_circ_c circ);
  //生成某一形状的点列表
  void point_list_new(uint num_point);
  void point_list_del(p_circ_v raw_list);
  void point_list_from_circ(p_circ_c raw_circ);
  void point_list_from_rect(p_circ_c raw_rect);
  void point_list_from_poly(p_circ_c raw_poly);
//
#ifdef __cplusplus
}
#endif

#endif