"""
生产者消费者模型是用来解决
生产和处理数据速度不匹配问题的
"""

import threading
import time
from queue import Queue


class Producer(threading.Thread):
    """生产者"""

    def run(self):
        global queue
        count = 0
        while True:
            # 只要商品数量小于 1000 我就生产 100 个放进去，一共有 2 个生产者
            if queue.qsize() < 1000:
                for i in range(100):
                    count += 1
                    msg = '生成产品' + str(count)
                    queue.put(msg)
                    print(msg)
            time.sleep(0.5)


class Consumer(threading.Thread):
    """消费者"""

    def run(self):
        global queue
        while True:
            # 只要商品里数量大于 100 个，我就消费 3 个，一共有 5 个消费者
            if queue.qsize() > 100:
                for i in range(3):
                    msg = self.name + '消费了' + queue.get()
                    print(msg)
            time.sleep(1)


if __name__ == '__main__':
    # 数据缓冲队列
    queue = Queue()

    # 这是主线程往队列里初始化了 500 个商品
    for i in range(500):
        queue.put('初始产品' + str(i))

    # 创建了 2 个生产者
    for i in range(2):
        p = Producer()
        p.start()

    # 创建了 5 个消费者
    for i in range(5):
        c = Consumer()
        c.start()
