class Base(object):
    def test(self):
        print("Base test")

class A(Base):
    def test(self):
        print("test_A")

class B(Base):
    def test(self):
        print("test_B")

class C(A, B):
    def test(self):
        print("test_C")


if __name__ == "__main__":
    c1 = C()
    c1.test()
    print(C.__mro__)  # 搜索方法的先后顺序，这个顺序是 C3 算法计算出来的搜索路径