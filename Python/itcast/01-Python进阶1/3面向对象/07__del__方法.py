import sys

class Dog:
    def __del__(self):
        print("del..")


if __name__ == "__main__":
    d1 = Dog()
    d2 = d1  # d2 也指向了 d1 指向的对象
    # del d1
    # del d2  # 引用计数，当 del d2 后 py 解释器就会自动调用 __del__ 方法

    print(sys.getrefcount(d1))  # getrefcount 可以获取引用计数的个数，这返回值个数是实际的 + 1
    del d1
    print(sys.getrefcount(d2))
    del d2
    while True:
        pass