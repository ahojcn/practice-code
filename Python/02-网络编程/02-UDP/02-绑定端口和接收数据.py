from socket import *

if __name__ == '__main__':
    s = socket(AF_INET, SOCK_DGRAM)

    bindAddr = ('', 7778)  # ip 不写表示本机，绑定别人的 ip 是会崩
    s.bind(bindAddr)

    # 1024 表示本次接收的最大数据字节数
    recvMsg = s.recvfrom(1024)

    print(recvMsg)

    content, address = recvMsg  # 解包
    print('content : %s' % content.decode('gb2312'))
    print('address : %s' % str(address))

    s.close()
