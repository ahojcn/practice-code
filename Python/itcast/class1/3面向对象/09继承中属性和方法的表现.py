"""
你爹的就是你爹的，你爹给你的你才可以用，不给你的你就不能用
"""

class A:
    
    def __init__(self):
        self.a = 1
        self.__a = 111

    def test(self):
        print("test")

    def __test(self):
        print("__test")

class B(A):
    pass


if __name__ == "__main__":
    b = B()
    print(b.a)
    # print(b.__a)
    b.test()
    # b.__test()

