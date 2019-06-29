class Person(object):
    __slots__ = ("name", "age")


if __name__ == '__main__':
    p1 = Person()

    p1.name = "ahojcn"
    p1.age = 10

    # p1.score = "nan" # Error