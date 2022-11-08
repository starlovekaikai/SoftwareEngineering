#include <stdio.h>
#include "cJSON.c"

int main(void)
{
    /* 要解析的json对象 */
    char *str_json = "                                          \
        {                                                       \
            \"students\" : {                                    \
                \"total\" : 3,                                  \
                \"student\" : [                                 \
                    {                                           \
                            \"id\" : 1,                         \
                            \"name\" : \"xiaoming\",            \
                            \"age\" : 18,                       \
                            \"hobby\" : \"basketball\"          \
                    },                                          \
                    {                                           \
                            \"id\" : 2,                         \
                            \"name\" : \"xiaolan\",             \
                            \"age\" : 17,                       \
                            \"hobby\" : \"tennis\"              \
                    },                                          \
                    {                                           \
                            \"id\" : 3,                         \
                            \"name\" : \"xiaohong\",            \
                            \"age\" : 18,                       \
                            \"hobby\" : \"piano\"               \
                    }                                           \
                ]                                               \
            },                                                  \
            \"grade\" : \"senior three\",                       \
            \"subject\": [\"Chinese\", \"math\", \"English\"]   \
        }                                                       \
    ";

    cJSON *root = cJSON_Parse(str_json);
    cJSON *students = cJSON_GetObjectItem(root, "students");    
    
    cJSON *total = cJSON_GetObjectItem(students, "total");      // 获取总数
    
    cJSON *stu_arr = cJSON_GetObjectItem(students, "student");  // 获取 student 数组
    int stu_arr_size = cJSON_GetArraySize(stu_arr);             // 获取 student 数组中元素的个数
    
    cJSON *grade = cJSON_GetObjectItem(root, "grade");
    
    cJSON *subject_arr = cJSON_GetObjectItem(root, "subject");  // 获取 subject 数组
    int subject_arr_size = cJSON_GetArraySize(subject_arr);     // 获取 subject 数组中元素的个数
    
    cJSON *item, *id, *name, *age, *hobby, *sub_value;
    int i;

    printf("total: %d\n", total->valueint);

    printf("\nstu_arr_size: %d\n", stu_arr_size);     // 打印 student 数组中元素的个数
    for(i=0; i<stu_arr_size; ++i)
    {
        item = cJSON_GetArrayItem(stu_arr, i);      // 获取 student 数组中的具体项
        id = cJSON_GetObjectItem(item, "id");
        name = cJSON_GetObjectItem(item, "name");
        age = cJSON_GetObjectItem(item, "age");
        hobby = cJSON_GetObjectItem(item, "hobby");
        printf("id:%-1d, name:%-8s, age:%-2d, hobby:%-10s\n", id->valueint, name->valuestring, age->valueint, hobby->valuestring);
    }

    printf("\ngrade: %s\n", grade->valuestring);

    printf("\nsubject_arr_size: %d\n", subject_arr_size);     // 打印 subject 数组中元素的个数
    printf("subject is: ");
    for(i=0; i<subject_arr_size; ++i)
    {
        sub_value = cJSON_GetArrayItem(subject_arr, i);
        printf("%s ", sub_value->valuestring);
    }
    printf("\n");

    /* 释放空间 */
    if(root != NULL)
    {
        cJSON_Delete(root);
        root = NULL;
        students = NULL;
        total = NULL;
        stu_arr = NULL;
        grade = NULL;
    }

    return 0;
}