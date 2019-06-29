"""
__new__ 方法是创建对象用的
重写此方法后一定要在最后调用父类的 __new__ 对象
为对象分配空间，创建对象

__init__ 负责初始化

这两个方法合起来相当于 “构造方法”
"""
class Dog(object):
    def __init__(self):
        print("init方法")

    def __del__(self):
        print("del方法")
    
    def __str__(self):
        print("str方法")

    def __new__(cls):
        # print(id(cls))
        print("new方法")
        return super().__new__(cls)


if __name__ == "__main__":
    # print(id(Dog))
    d1 = Dog()