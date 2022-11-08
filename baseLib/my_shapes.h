#ifndef _MY_SHAPES_
#define _MY_SHAPES_

#ifdef __cplusplus
extern "C"
{
#endif
  //形状类型的定义
  struct point;
  struct circ;
  struct rect;
  struct poly;
  typedef point *p_point_c;
  typedef point *p_point_v;
  typedef circ *p_circ_c;
  typedef circ *p_circ_v;
  typedef rect *p_rect_c;
  typedef rect *p_rect_v;
  typedef poly *p_poly_c;
  typedef poly *p_poly_v;
  //生成点列表
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