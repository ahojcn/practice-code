class Person(object):
    def __init__(self, name, age):
        self.__name = name
        self.__age = age

    def getName(self):
        return self.__name

    def setName(self, name):
        self.__name = name

    def getAge(self):
        return self.__age

    def setAge(self, age):
        self.__age = age

    name = property(getName, setName)
    age = property(getAge, setAge)


if __name__ == '__main__':
    p1 = Person("ahoj", 21)
    p1.name = "ahojcn"
    print(p1.name)
    p1.age = 20
    print(p1.age)

