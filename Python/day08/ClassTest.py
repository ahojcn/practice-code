class Student(object):

    # __init__ 是一个特殊方法，用于在创建对象时进行初始化操作
    # 通过这个方法我们可以为学生对象绑定 name 和 age 两个属性
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def study(self, course_name):
        print("%s 正在学习 %s." % (self.name, course_name))

    def watchMovie(self):
        if self.age < 18:
            print("%s 正在看《小猪佩奇》." % self.name)
        else:
            print("%s 正在看《回家的诱惑》." % self.name)


if __name__ == '__main__':
    s1 = Student('ahoj', 17)
    s1.study("Python程序设计")