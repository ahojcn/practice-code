/*
 1.约瑟夫环（通过指针的形式），要求顺序输出出圈的序号以及最后剩下的人。
 2.输入一行字符串，要求统计其中字母，空格，数字以及其他字符的数目，要求用数组和指针两种形式。
 3.用指向指针的指针的方法对5个字符串排序并输出。
 4.建立一个链表，每个结点包括：学号，姓名，年龄，性别。要求输入3个人的信息，将他们按照年龄正序/逆序排序输出他们的信息。
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct Student
{
    char *id;
    char *name;
    int age;
    char *sex;
}Stu;

typedef Stu ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
} *LinkedList, Node;

void InitLinkedList(LinkedList *L)
{
    *L = (LinkedList)malloc(sizeof(Node));
    (*L)->next = *L;
}

void CreateInfo(LinkedList L)
{
    
}

int main()
{
    LinkedList L;
    InitLinkedList(&L);
    
    return 0;
}


// 3
/*
#include <stdio.h>
#include <string.h>
#define M 5
#define MAXSIZE 1024

int main()
{
    
    
    
    
    
    
    
    
    
    return 0;
}
 */









// 2
/*
#include <stdio.h>
#define MAX_SIZE 1024

int main()
{
    int english = 0; //字母
    int space = 0; //空格
    int number = 0; //数字
    
    // 数组
    char arr1[MAX_SIZE] = "abcd 123 abcd";
    int i = 0;
    while (arr1[i] != '\0')
    {
            if (arr1[i]>=48 && arr1[i]<=57) //number
            {
                ++number;
            }
            if (arr1[i] == ' ')
            {
                ++space;
            }
            if ((arr1[i]>=65 && arr1[i]<=90) || (arr1[i]>=97 && arr1[i]<=122))
            {
                ++english;
            }
            i++;
    }
    printf("number = %d\nspace = %d\nenglish = %d\n", number, space, english);
    
    
    // 指针
    number = 0;
    space = 0;
    english = 0;
    char *p = arr1;
    while (*p != '\0')
    {
        if (*p>=48 && *p<=57) //number
        {
            ++number;
        }
        if (*p == ' ')
        {
            ++space;
        }
        if ((*p>=65 && *p<=90) || (*p>=97 && *p<=122))
        {
            ++english;
        }
        p++;
    }
    printf("number = %d\nspace = %d\nenglish = %d\n", number, space, english);
    
    return 0;
}
*/










// 1
/*
#include <stdio.h>
#define MAX_PEOPLE 1000

int main(int argc, const char * argv[])
{
    // init
    int people[MAX_PEOPLE] = {0};
    int n = 0,num = 0;
    scanf("%d%d", &n, &num);
    int *p = people;
    for (int i=0; i<n; i++)
    {
        *(p+i) = i+1;
    }
    
    // play
    int alive = n;
    int i = 0;
    int cnt = 1;
    p = people;
    
    while (alive > 1)
    {
        if (i == n-1)
        {
            i = 0;
        }
        
        if (*(p+i) != -1)
        {
            if (cnt == num)
            {
                printf("%d,",*(p+i));
                *(p+i) = -1;
                alive--;
                cnt = 1;
                i++;
            }
            else
            {
                cnt++;
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    
    for (int i=0; i<n; i++)
    {
        if (*(p+i) != -1)
        {
            printf("%d,",*(p+i));
        }
    }
    
    return 0;
}
*/
