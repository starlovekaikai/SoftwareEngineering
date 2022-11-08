#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
    int size;
} ;
union myunion test[10];
int find_union(union myunion *p, int union_size,int find_size){
    for(int i=0; i < union_size; i++){
        if(p[i].size==find_size)
            return i;
    }
    return -1; //²»´æÔÚ
}
void delete_union(union myunion *p, int pos){
    p[pos].size = 0;
}
int main(){

    for(int i=0;i<sizeof(test)/sizeof(test[0]);i++){
        test[i].size = 0;
    }
    char cc1[10]  = "ab",cc2[10] = "abcd";
    for(int i=0;i<strlen(cc1);i++){
        test[0].name1.a[i] = cc1[i];
    }
    for(int i=0;i<strlen(cc2);i++){
        test[0].name2.b[i] = cc2[i];
    }
    test[0].size=strlen(cc1), test[1].size = strlen(cc2);

    int a = find_union(test, sizeof(test)/sizeof(test[0]), strlen(cc2));
    printf("%d", a);
    char cc[10];
    return 0 ;
}