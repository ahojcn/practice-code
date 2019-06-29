def w1(func):
    print("正在装饰")

    def inner():
        print("正在验证权限")
        func()

    return inner


"""
只要 解释器 执行到了这行代码，就会自动进行装饰，而不是等到调用的时候才装饰的
"""
@w1
def f1():
    print("f1")


"""
在调用f1之前，已经进行装饰了
"""
if __name__ == '__main__':
    f1()