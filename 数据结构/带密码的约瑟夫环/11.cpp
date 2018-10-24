
#include "stdio.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
struct node{
    int num;//结点编号
    int pwd;//结点密码数据
    node *next;//下个结点地址
};

int main(int argc, char* argv[])
{
    int m,n,i,j;
    node *p,*q,*first;
    cout<<"输入m的初始值：";
    cin>>m;
    cout<<"输入人数n:";
    cin >>n;
    for(i=1;i<=n;i++)//输入n个结点的密码
    {
        if(i==1)
        {
            first=p=(node*)malloc(sizeof(node));
            if(p==0)
                return 0;
        }
        else
        {
            q=(node*)malloc(sizeof(node));
            if(q==0)
                return 0;
            p->next=q;
            p=q;
        }
        cout<<"输入第"<<i<<"个人的密码：";
        cin>>p->pwd;
        p->num=i;
    }
    p->next=first;//输入n个结点后，将尾指针指向表头，形成循环链表
    p=first;
    cout<<"出列顺序为：";
    for(j=1;j<=n;j++)
    {
        for(i=1;i<m;i++,p=p->next)
        {
            ;
        }
        
        m=p->pwd;
        cout<<p->num<<" ";
        p->num=p->next->num;
        p->pwd=p->next->pwd;
        q=p->next;
        p->next=p->next->next;
        free(q);
        
    }
    cout<<endl;
    
    return 0;
}
