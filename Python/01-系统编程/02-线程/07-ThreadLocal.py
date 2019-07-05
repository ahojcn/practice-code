import threading

"""
创建全局 ThreadLocal 对象
"""
local_school = threading.local()


def process_student():
    """获取当前线程关联的 student"""
    std = local_school.student
    print("hello, %s (in %s)" % (std, threading.current_thread().name))


def process_thread(name):
    """绑定 ThreadLocal 的 student"""
    local_school.student = name
    process_student()


if __name__ == '__main__':
    t1 = threading.Thread(target=process_thread, args=('ahojcn',), name='Thread-A')
    t2 = threading.Thread(target=process_thread, args=('Tim',), name='Thread-B')

    t1.start()
    t2.start()

    t1.join()
    t2.join()