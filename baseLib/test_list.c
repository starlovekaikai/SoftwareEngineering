#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*总结构为：struct node 包含union和两个前后向指针，union中的struct为需要更改的内容*/
struct mystruct1
{
  char a[5];
};
struct mystruct2
{
  char b[100];
};

union myunion
{
  struct mystruct1 name1;
  struct mystruct2 name2;
  int size; //每次更改union内的元素，均应更改size大小
};
struct node
{
  union myunion val; //指向union
  struct node *next, *pre;
};

int find_union(struct node *p, int find_size)
{ //返回查找的元素在链表中的位置，dummyhead视为第0个
  p = p->next;
  int ans = 1;
  while (p->next != NULL)
  {
    if (p->val.size == find_size)
    {
      return ans;
    }
  }
  return -1; //不存在
}
void delete_union(struct node *p, int pos)
{
  //删除第pos个node,最小值为1
  p->val.size = p->val.size - 1;
  for (int i = 0; i < pos; i++)
  {
    p = p->next;
  }
  struct node *tmp;
  tmp = p;
  tmp->pre->next = tmp->next;
  tmp->next->pre = tmp->pre;
  free(tmp);
  tmp = NULL;
}
void add_union(struct node *head, struct node *tail)
{
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  //此处请填写要对new_node增加的内容，并增加add_union函数输入参数，也可以在main函数中添加new_node的内容
  new_node->pre = tail->pre;
  tail->pre->next = new_node;
  new_node->next = tail;
  tail->pre = new_node;
  //新添加的node被dummy_tail->pre所指向
  head->val.size = head->val.size + 1;
}
int get_length(struct node *head)
{
  return head->val.size;
}
int main()
{
  //初始化
  struct node dummy_head, dummy_tail;
  dummy_head.pre = NULL;
  dummy_head.next = &dummy_tail;
  dummy_tail.pre = &dummy_head;
  dummy_tail.next = NULL;
  dummy_head.val.size = 0; //这个size用来存放此链表的有效长度，不包含dummy_head和dummy_tail

  //使用实例
  add_union(&dummy_head, &dummy_tail);
  add_union(&dummy_head, &dummy_tail);
  dummy_head.next->val.size = 50;
  dummy_head.next->next->val.size = 60;
  printf("%d\n", get_length(&dummy_head));
  delete_union(&dummy_head, 2);
  printf("%d\n", get_length(&dummy_head));
  printf("%d\n", dummy_head.next->val.size);
  printf("所查元素在第%d个位置\n", find_union(&dummy_head, 50));
  /*dummy_tail.pre->val->size = 10;
  printf("%d",dummy_head.next->val->size);*/
  return 0;
}