class P(object):
    pass


@staticmethod
def test():
    print("static method")


@classmethod
def printNum(cls):
    print("class method")


if __name__ == '__main__':
    P.test = test
    P.test()

    P.printNum = printNum
    P.printNum()