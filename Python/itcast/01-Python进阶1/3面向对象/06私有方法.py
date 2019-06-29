class Dog:

    def __init__(self):
        pass

    def test1(self):
        print(" 1 ".center(20, "."))

    def __test2(self):
        print(" 2 ".center(20, "."))


if __name__ == "__main__":
    d1 = Dog()
    d1.test1()
    # d1.__test2()  # 不能调用