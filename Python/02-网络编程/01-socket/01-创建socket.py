import socket


if __name__ == '__main__':
    # tcp 通信
    s1 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # udp
    s2 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    print('socket created')