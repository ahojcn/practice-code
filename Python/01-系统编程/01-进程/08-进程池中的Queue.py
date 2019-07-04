"""
如果要使用Pool创建进程，就需要使用multiprocessing.Manager()中的Queue()，
而不是multiprocessing.Queue()，否则会得到一条如下的错误信息：

RuntimeError: Queue objects should only be shared between processes through inheritance.
"""

from multiprocessing import Manager, Pool
import os


def reader(q):
    print("reader 启动 %s，父进程为 %s" % (os.getpid(), os.getppid()))
    for i in range(q.qsize()):
        print("reader 读取到 :%s" % q.get(True))


def writer(q):
    print("writer 启动 %s，父进程为 %s" % (os.getpid(), os.getppid()))
    for i in "ahojcn":
        q.put(i)


if __name__ == '__main__':
    print("%s start" % os.getpid())
    q = Manager().Queue()  # 使用 Manger 中的 Queue 来初始化
    po = Pool()

    # 使用阻塞模式创建进程，这样就不需要在 reader 中使用死循环了
    # 可以让 writer 完全执行完成后再调用 reader
    po.apply(writer, (q,))
    po.apply(reader, (q,))

    po.close()
    po.join()
    print("%s End" % os.getpid())