from socket import *

if __name__ == '__main__':
    # 创建套接字
    udpSocket = socket(AF_INET, SOCK_DGRAM)

    # 准备接收方的地址
    sendAddr = ('192.168.1.100', 8080)

    # 从键盘获取输入数据
    sendMsg = input('请输入要发送的数据 :')

    # 发送到指定电脑上
    udpSocket.sendto(sendMsg.encode('utf-8'), sendAddr)

    # 关闭套接字
    udpSocket.close()
