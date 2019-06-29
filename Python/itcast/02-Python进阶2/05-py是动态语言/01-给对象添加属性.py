class Person(object):
    def __init__(self, name, age):
        self.name = name
        self.age = age


if __name__ == '__main__':
    laowang = Person("laowang", 30)
    print(laowang.name)
    print(laowang.age)

    '''给对象添加一个属性'''
    laowang.addr = "陕西西安"
    print(laowang.addr)

    # print(dir(laowang))

    '''新对象没有刚才的属性'''
    laozhao = Person("laozhao", 20)
    # print(laozhao.addr)  # error

    '''给类添加一个属性'''
    Person.num = 100
    print(laozhao.num)
    print(laowang.num)
