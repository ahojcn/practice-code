from threading import Thread

g_num = 0
g_flag = 1


def test1():
    global g_num
    global g_flag
    if g_flag == 1:
        for i in range(100000):
            g_num += 1
        g_flag = 0
        print("test 1, g_num = %d" % g_num)


def test2():
    global g_num
    global g_flag
    while True:
        if g_flag != 1:
            for i in range(100000):
                g_num += 1
            break

    print("test 2, g_num = %d" % g_num)


if __name__ == '__main__':
    t1 = Thread(target=test1)
    t2 = Thread(target=test2)

    t1.start()
    t2.start()