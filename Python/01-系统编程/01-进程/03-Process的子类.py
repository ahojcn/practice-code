from multiprocessing import Process
import time
import os


class MyProcess(Process):
    def __init__(self, interval):
        # super().__init__(self)  #  Error
        Process.__init__(self)
        self.interval = interval

    def run(self):
        print("子进程%s 开始执行，父进程为%s" % (os.getpid(), os.getppid()))
        t_start = time.time()
        time.sleep(self.interval)
        t_stop = time.time()
        print("%s执行结束，耗时%.2f秒" % (os.getppid(), t_start - t_stop))


if __name__ == '__main__':
    t_start = time.time()
    print("父进程%s" % os.getpid())

    p1 = MyProcess(2)
    p1.start()  # 父类中的 start 自动掉了 run 方法
    p1.join()

    t_stop = time.time()
    print("父进程%s执行结束，耗时%.2f秒" % (os.getpid(), t_start - t_stop))
