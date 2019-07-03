import os

if __name__ == '__main__':
    ret = os.fork()
    print("ret = %d" % ret)
    if ret == 0:
        print('child process pid = %d, my father pid = %d' % (os.getpid(), os.getppid()))
    elif ret > 0:
        print('father process pid = %d, my father pid = %d' % (os.getpid(), os.getppid()))
    else:
        print('error')