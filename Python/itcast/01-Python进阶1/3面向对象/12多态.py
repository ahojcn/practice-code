class Dog(object):
    def print_self(self):
        print("大家好，我是...，请多多关照。")


class Xiaotq(Dog):
    def print_self(self):
        print("hello everybody, 我是狗老大，哮天犬。")


def introduce(temp):
    temp.print_self()


if __name__ == "__main__":
    d1 = Dog()
    d2 = Xiaotq()
    introduce(d1)
    introduce(d2)