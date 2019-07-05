from socket import *

if __name__ == '__main__':
    # 创建套接字
    clientSocket = socket(AF_INET, SOCK_STREAM)

    # 连接
    clientSocket.connect(('192.168.1.100', 7778))

    # 发送数据
    clientSocket.send("你好".encode('gb2312'))

    # 接收数据
    recvData = clientSocket.recv(1024)

    print("recvData:%s" % recvData)

    clientSocket.close()
