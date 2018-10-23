#include <sys/types.h>  
#include <sys/socket.h>  
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  
#include <string.h>  
#include <arpa/inet.h>  

#define PORT 9990
#define BUFFER_SIZE 1024
#define FILE_NAME_MAX_SIZE 512

int main(int argc, char **argv)
{  
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);   //创建和服务器连接套接字  
    if(client_socket == -1)  
    {  
        perror("socket");
        return -1;  
    }  
    struct sockaddr_in addr;  
    memset(&addr, 0, sizeof(addr));  
      
    addr.sin_family = AF_INET;  /* Internet地址族 */  
    addr.sin_port = htons(PORT);  /* 端口号 */  
    addr.sin_addr.s_addr = htonl(INADDR_ANY);   /* IP地址 */  
    //inet_aton("127.0.0.1", &(addr.sin_addr));
    inet_aton("192.168.12.1", &(addr.sin_addr));
	//
  
    int addrlen = sizeof(addr);  
    int listen_socket =  connect(client_socket,  (struct sockaddr *)&addr, addrlen);  //连接服务器  
    if(listen_socket == -1)  
    {  
        perror("\n\t\t服务端未启动!\n");
        return -1;  
    }  
      
    printf("\n\t\t成功连接!\n");
      
    int buf;
    int *p=&buf;
    
    while(1)        //发送数据
    {
        printf("\t\t-------------------------------\n");
        printf("\t\t0.  退出");
        printf("\n\t\t1.  计算并返回结果");
        printf("\n\t\t2.  删除服务端计算结果文件");
        printf("\n\t\t3.  上传测试文件");
        printf("\n\t\t4.  下载计算结果文件");
        printf("\n\t\t-------------------------------");
        printf("\n\t\t    输入编号:");
        scanf("%d", &buf);
        if(buf==0)
        {
            write(client_socket, p, sizeof(int));
            break;
        }
        if(buf==1)
        {
            write(client_socket, p, sizeof(int));
            read(client_socket, p, sizeof(int));
            printf("\n\t\t本次计算的违约分为： %d\n\n", buf);
        }
        if(buf==2)
        {
            write(client_socket, p, sizeof(int));
        }
        if(buf==3)
        {
            char filename[81];
            int *pFileName = filename;
            printf("输入要上传的文件名：");
            scanf("%s",filename);
            FILE *fp = fopen(filename,"r");
            if(!fp)
            {
                printf("上传文件失败！可能是名称不对，请检查！\n");
                continue;
            }
            while(fp!=EOF)
            {
                write(client_socket, fp, sizeof(int));
            }
            fclose(fp);
            
        }// 3
        if(buf==4)
        {
            FILE *fp = fopen("./download_from_server.csv","a+");
            int *rp;
            if(!fp)
            {
                printf("写入本地文件失败!\n");
                continue;
            }
            do
            {
                read(client_socket, rp, sizeof(int));
                fprintf(fp,"%d",*rp);
            }while(rp!=EOF);
            fclose(fp);
        }// 4
        
        
        
    }/*while*/
    close(listen_socket);  
      
    return 0;  
}

void reciveFILE()
{
    
}







