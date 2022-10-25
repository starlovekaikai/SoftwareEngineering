#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "wrapper.c"
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
  (*(int *)sss.y) += 10;
  printf("x:%d,y:%d,z:%c\n", sss.x, *(int *)sss.y, *(char *)sss.z);

  char c[10] = "abcdfanc";

  PGSTRV g = NewGSTR_ByStr(c);
  printf("das ist %c\n", GSTRInd(g,4));
  char d[10];
  GSTRExport(g, d);
  printf("this is %s\n", d);
  char temp;
  while ((temp = GSTRFindChr(g, 'a')) != -1)
  {
    GSTRDel(g, temp, 1);
    printf("%d\n", temp);
  }
  printf("over\n");
}