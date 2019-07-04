"""
threading模块中定义了Lock类，可以方便的处理锁定
"""

from threading import Thread, Lock

g_num = 0
mutex = Lock()


def test1():
    global g_num

    for i in range(100000):
        mutex.acquire()
        g_num += 1
        mutex.release()
    print("test 1, g_num = %d" % g_num)


def test2():
    global g_num

    for i in range(100000):
        mutex.acquire()
        g_num += 1
        mutex.release()
    print("test 2, g_num = %d" % g_num)


if __name__ == '__main__':
    t1 = Thread(target=test1)
    t2 = Thread(target=test2)

    t1.start()
    t2.start()
