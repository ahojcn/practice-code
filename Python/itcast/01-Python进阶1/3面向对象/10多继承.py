"""
驴    马
  骡子
骡子继承自驴和马
"""

class Base(object):
    def test(self):
        print("Base test")

class A(Base):
    def test_A(self):
        print("test_A")

class B(Base):
    def test_B(self):
        print("test_B")

class C(A, B):
    pass


if __name__ == "__main__":
    c1 = C()
    c1.test()
    c1.test_A()
    c1.test_B()

