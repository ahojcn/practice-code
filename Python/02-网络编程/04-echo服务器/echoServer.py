"""
复读机
"""

from socket import *

if __name__ == '__main__':
    s = socket(AF_INET, SOCK_DGRAM)
    s.bind(('', 41366))


    while True:
        recvInfo = s.recvfrom(1024)
        print('[%s:%s]> %s' % (recvInfo[1][0], recvInfo[1][1], recvInfo[0].decode('gb2312')))

        s.sendto(recvInfo[0], recvInfo[1])

    # s.close()