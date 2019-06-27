import types

class Person(object):
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def eat(self):
        print("%s 正在吃" % self.name)


def run(self):
    print("%s 正在跑" % self.name)

if __name__ == '__main__':
    p1 = Person("ahoj", 20)
    p1.eat()

    '''给 p1 添加属性'''
    # p1.run = run
    # p1.run(p1)  # 注意这里要给 run 传入 p1

    '''使用types把方法绑定到对象上'''
    p1.run = types.MethodType(run, p1)
    p1.run()