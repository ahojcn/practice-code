#include <stdio.h>
#include <string.h>
#include <errno.h>

#define N 12
#define MAX 30

typedef struct people
{
    char name[20];
    char id[20];
}people;

int inx[MAX*2];

void hash(people *peo, int m, int p)
{
    memset(inx, 0, MAX*2);
    int tmp[MAX] = {0}; // tmp用来保存name的ascii码之和
    for(int i=0; i<N; i++)
    {
        for(int j=0; peo[i].name[j]; j++)
        {
            tmp[i] += peo[i].name[j];
        }
//        printf("%s -> %d\n", peo[i].name, tmp[i]);
    }
    
    for(int i=0; i<MAX; i++)
    {
        // 除留余数法
        int tmp_ = tmp[i] % (MAX*2);
//        printf("%d\n", tmp_);
//        if(inx[tmp_] == 0)
//        {
//            inx[tmp_] = 1;
//        }
//        else
//        {
//            while(inx[tmp_] == 1)
//            {
//                tmp_++;
//            }
//        }
    }
    
}

int main()
{
    people p[MAX];
    FILE * fp = fopen("test.txt", "r");
    if(fp == NULL)
    {
        printf("%s\n", strerror(errno));
    }
    
    printf("name\tid\n");
    for(int i=0; i<N; i++)
    {
        fscanf(fp, "%s", p[i].name);
        fscanf(fp, "%s", p[i].id);
        printf("%s\t%s\n", p[i].name, p[i].id);
    }
    
    hash(p, MAX*2, MAX*2);
    
    
    
    return 0;
}
