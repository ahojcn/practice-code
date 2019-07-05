from socket import *

if __name__ == '__main__':
    # 买个手机
    tcpServerSocket = socket(AF_INET, SOCK_STREAM)

    # 插手机卡
    tcpServerSocket.bind(('', 7778))

    # 开启响铃模式
    # 使用socket创建的套接字默认的属性是主动的，使用 listen 将其变为被动的，这样就可以接收别人的链接了
    tcpServerSocket.listen(5)

    # 等待连接
    # 如果有新的客户端来链接服务器，那么就产生一个新的套接字专门为这个客户端服务器
    # newSocket 用来为这个客户端服务
    # tcpSerSocket 就可以省下来专门等待其他新客户端的链接
    newSocket, clientAddr = tcpServerSocket.accept()

    # 接收数据
    recvData = newSocket.recv(1024)
    print("收到%s的消息：%s" % (str(clientAddr), recvData))

    # 发送数据
    newSocket.send('收到收到，over'.encode('utf-8'))

    # 关闭和这个客户端的连接
    newSocket.close()

    # 关闭监听套接字
    tcpServerSocket.close()
