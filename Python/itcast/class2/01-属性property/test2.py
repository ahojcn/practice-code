class Person(object):
    def __init__(self, name, age):
        self.__name = name
        self.__age = age

    @property
    def name(self):
        return self.__name

    @name.setter
    def name(self, name):
        self.__name = name

    @property
    def age(self):
        return self.__age

    @age.setter
    def age(self, age):
        self.__age = age


if __name__ == '__main__':
    p1 = Person("ahoj", 21)
    p1.name = "ahojcn"
    print(p1.name)
    p1.age = 20
    print(p1.age)

