"""
类也是一个对象
"""
class Person(object):

    num = 0

    print("-- person test print --")

    def __init__(self):
        self.name = 'abc'



# 在没有创建实例的情况下，第 5 行的 print 也被执行了

if __name__ == '__main__':
    # print(Person)
    pass