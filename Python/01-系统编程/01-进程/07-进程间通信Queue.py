from multiprocessing import Process, Queue
import os, time, random


# 写数据
def write(q):
    for val in ['A', 'B', 'C']:
        print('put %s to queue...' % val)
        q.put(val)
        time.sleep(random.random())


# 读数据
def read(q):
    while True:
        if not q.empty():
            val = q.get(True)
            print("get %s from queue..." % val)
            time.sleep(random.random())
        else:
            break


if __name__ == '__main__':
    # 父进程创建 Queue 并传给各个子进程
    q = Queue()
    pw = Process(target=write, args=(q,))
    pr = Process(target=read, args=(q,))

    # 启动子进程 pw
    pw.start()
    # 等待 pw 结束
    pw.join()

    # 启动子进程 pr
    pr.start()
    pr.join()

    print('')
    print('所有数据写入、读取完毕')
