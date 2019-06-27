def w1(func):
    def inner():
        print("正在进行验证权限")
        func()
    return inner


@w1
def f1():
    print("--f1--")


@w1
def f2():
    print("--f2--")



if __name__ == '__main__':
    f1()
    f2()
