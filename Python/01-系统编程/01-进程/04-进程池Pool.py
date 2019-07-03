"""
当需要创建的子进程数量不多时，
可以直接利用multiprocessing中的Process动态成生多个进程，
但如果是上百甚至上千个目标，
手动的去创建进程的工作量巨大，
此时就可以用到multiprocessing模块提供的Pool方法。

初始化Pool时，可以指定一个最大进程数，
当有新的请求提交到Pool中时，
如果池还没有满，那么就会创建一个新的进程用来执行该请求；
但如果池中的进程数已经达到指定的最大值，那么该请求就会等待，
直到池中有进程结束，才会创建新的进程来执行。
"""

"""
multiprocessing.Pool常用函数解析：

apply_async(func[, args[, kwds]]) ：
    使用非阻塞方式调用func（并行执行，堵塞方式必须等待上一个进程退出才能执行下一个进程），
    args为传递给func的参数列表，kwds为传递给func的关键字参数列表；
apply(func[, args[, kwds]])：
    使用阻塞方式调用func
close()：
    关闭Pool，使其不再接受新的任务；
terminate()：
    不管任务是否完成，立即终止；
join()：
    主进程阻塞，等待子进程的退出， 必须在close或terminate之后使用；
"""

from multiprocessing import Pool
import os, time, random


def worker(msg):
    t_start = time.time()
    print("%s 开始执行,进程号为%d" % (msg, os.getpid()))
    # random.random() 随机生成0~1之间的浮点数
    time.sleep(random.random() * 2)
    t_stop = time.time()
    print(msg, "执行完毕，耗时%0.2f" % (t_stop - t_start))


if __name__ == '__main__':
    po = Pool(3)  # 定义一个进程池，最大进程数3

    for i in range(0, 10):
        # Pool.apply_async(要调用的目标,(传递给目标的参数元祖,))
        # 每次循环将会用空闲出来的子进程去调用目标
        po.apply_async(worker, (i,))

    print("-- start --")
    po.close()  # 关闭进程池，关闭后po不再接收新的请求，相当于不能再次添加新任务了
    po.join()  # 等待po中所有子进程执行完成，必须放在close语句之后
    print("-- end --")
