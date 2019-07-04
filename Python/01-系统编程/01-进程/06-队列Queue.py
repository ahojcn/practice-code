"""
Process之间有时需要通信，操作系统提供了很多机制来实现进程间的通信。
可以使用multiprocessing模块的Queue实现多进程之间的数据传递，Queue本身是一个消息列队程序
"""

from multiprocessing import Queue

if __name__ == '__main__':
    q = Queue(3)  # 初始化一个Queue对象，最多可接收三条put消息

    q.put('msg 1')
    q.put('msg 2')

    print(q.full())  # 判断队列是否 满

    q.put('msg 3')

    print(q.full())

    # 因为消息列队已满下面的try都会抛出异常，第一个try会等待2秒后再抛出异常，第二个Try会立刻抛出异常
    try:
        q.put('msg 4', True)
    except Exception as e:
        print(e)
        print(q.qsize())

    try:
        q.put_nowait('msg 4')
    except Exception as e:
        print(e)
        print(q.qsize())

    if not q.empty():
        for i in range(q.qsize()):
            print(q.get_nowait())