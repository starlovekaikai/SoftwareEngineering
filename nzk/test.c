#include <stdio.h>
#include <malloc.h>
typedef struct shape
{
  int x;
  void *y, *z;
} shape;

int main()
{
  shape sss;
  sss.x = 0;
  int *temp_y = (int *)calloc(1, sizeof(int));
  *temp_y = 5;
  char *temp_z = (char *)calloc(1, sizeof(char));
  *temp_z = 'r';
  sss.y = temp_y;
  sss.z = temp_z;
  printf("x:%d,y:%d,z:%c", sss.x, *(int *)sss.y, *(char *)sss.z);
}