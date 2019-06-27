class Test(object):
    def __init__(self):
        # num 是公有变量
        self.num = 100
        # __num2 是在外面直接用不了的
        # 改成了名字叫 _Test__num，所以外面用不了，这样就实现了在外部不能直接用
        # 但是使用 _Test__num 就可以用了
        self.__num2 = 100
        # 单前置下划线，私有化属性或方法，在 from a import * 禁止导入，但是类对象和子类都可以访问
        self._x = 100



if __name__ == "__main__":
    t1 = Test()
    print(t1.num)