#include <sys/types.h>  
#include <sys/socket.h>  
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>  
#include <string.h>  
#include <arpa/inet.h>  
#include "calculate.h"  //最优数字分配计算的函数头文件

#define PORT 9990   //端口号  



int Creat_socket()    //创建套接字和初始化以及监听函数  
{  
    int listen_socket = socket(AF_INET, SOCK_STREAM, 0);   //创建一个负责监听的套接字
    if(listen_socket == -1)  
    {
        perror("socket");  
        return -1;  
    }
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    
    addr.sin_family = AF_INET;  /* Internet地址族 */  
    addr.sin_port = htons(PORT);  /* 端口号 */  
    addr.sin_addr.s_addr = htonl(INADDR_ANY);   /* IP地址 */
      
    int ret = bind(listen_socket, (struct sockaddr *)&addr, sizeof(addr));  //连接  
    if(ret == -1)  
    {  
        perror("bind");  
        return -1;  
    }  
      
    ret = listen(listen_socket, 5);        //监听  
    if(ret == -1)  
    {  
        perror("listen");  
        return -1;  
    }  
    return listen_socket;  
}  
  
int wait_client(int listen_socket)  
{  
    struct sockaddr_in cliaddr;  
    int addrlen = sizeof(cliaddr);  
    printf("\t等待连接 ......\n");
    int client_socket = accept(listen_socket, (struct sockaddr *)&cliaddr, &addrlen);   //创建一个和客户端交流的套接字
    if(client_socket == -1)  
    {  
        perror("accept");  
        return -1;  
    }  
      
    printf("\t成功连接客户端：%s！\n", inet_ntoa(cliaddr.sin_addr));
      
    return client_socket;  
}

void hanld_client(int listen_socket, int client_socket)   //信息处理
{
    int buf;
    int *p = &buf;
    int *pg=&finally_grade;
    while(1)
    {
        //int ret = read(client_socket, p, sizeof(int)); //ret为返回字节数
        read(client_socket, p, sizeof(int));
        
        if((*p) == 0)
        {
            printf("\t客户端已断开连接！\n");
            *p=-1;
            break;
        }
        if((*p)==1)
        {
            printf("\t%d.计算并返回结果\n", *p);
            readFile();
            initSpace_sign_gradeCnt();
            calculate();
            Grade();
            toFile();
            write(client_socket, pg, sizeof(int));
            *pg=0;
            *p=-1;
        }
        if((*p) == 2)
        {
            system("rm ./output.csv");
            *p=-1;
        }
        if((*p)==3)
        {
            FILE *fp = fopen("testData","w");
            if(!fp)
            {
                printf("打开文件错误！\n");
                *p=-1;
                //continue;
            }
            fseek(fp,0L,SEEK_SET);
            int *rp;
            read(client_socket, rp, sizeof(int));
            fprintf(fp,"%d,",*rp);
            *p=-1;
        }// 3
        
        
    }
    close(client_socket);
}

int main()
{
	
    int listen_socket = Creat_socket();
      
    int client_socket = wait_client(listen_socket);  
      
    hanld_client(listen_socket, client_socket);
    
    close(listen_socket);   //停止监听
    
    return 0;  
}
