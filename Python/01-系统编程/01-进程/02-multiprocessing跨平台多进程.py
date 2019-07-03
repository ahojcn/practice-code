"""
如果你打算编写多进程的服务程序，Unix/Linux无疑是正确的选择。
由于Windows没有fork调用，难道在Windows上无法用Python编写多进程的程序？
由于Python是跨平台的，自然也应该提供一个跨平台的多进程支持。
multiprocessing模块就是跨平台版本的多进程模块。
"""
from multiprocessing import Process
import os

def func(name):
    print('子进程：name = %s, pid = %d' % (name, os.getpid()))

if __name__ == '__main__':
    print("父进程 pid = %d" % os.getpid())

    p = Process(target=func, args=('test', ))

    print("将要执行子进程")
    p.start()

    p.join() # join()方法可以等待子进程结束后再继续往下运行，通常用于进程间的同步。
    print("子进程 over")