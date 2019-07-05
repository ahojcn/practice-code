import socket, sys

if __name__ == '__main__':
    # 这里可以填 xxx.xxx.xxx.255
    # 填写 <broadcast> 更合适
    dest = ('<broadcast>', 7778)

    # 创建 udp 套接字
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    # 必要的设置，对这个需要发送广播数据的套接字进行修改设置，否则不能发送广播数据
    s.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

    # 以广播的形式发送数据到本网络的所有电脑中
    s.sendto("Hi".encode('utf-8'), dest)

    while True:
        (buf, addr) = s.recvfrom(2048)
        print("received from %s:%s" % (addr, buf))