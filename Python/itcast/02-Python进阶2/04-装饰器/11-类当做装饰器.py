class Test(object):
    def __init__(self, func):
        print("-- 初始化 --")
        print("-- func name is %s --" % func.__name__)
        self.__func = func

    def __call__(self):
        print("-- test __call__() --")
        self.__func()


@Test
def testFunc():
    print("testFunc print")


if __name__ == '__main__':

    # 类中重写了父类 __call__ 方法后可以直接用对象调用，如下
    # t = Test()
    # t()

    testFunc()