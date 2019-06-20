class Person(object):

    # 限定 Person 对象只能绑定 _name _age 和 _gender 属性
    __slots__ = ('_name', '_age', '_gender')

    def __init__(self, name, age):
        self._name = name
        self._age = age

    @property
    def name(self):
        return self._name

    @property
    def age(self):
        return self._age

    @age.setter
    def age(self, age):
        self._age = age

    def play(self):
        if self._age >= 16:
            print("%s正在玩斗地主." % self._name)
        else:
            print("%s正在玩飞行棋." % self._name)

    def __str__(self):
        return "%s, %s, %s" % (str(self._name), str(self._age), str(self._gender))



def main():
    p1 = Person("ahojcn", 12)
    p1.play()
    p1._gender = "男"
    print(p1)
    # p1._is_gay = True


if __name__ == '__main__':
    main()