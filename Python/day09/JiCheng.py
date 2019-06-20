class Person(object):

    def __init__(self, name, age):
        self._name = name
        self._age = age

    @property
    def name(self):
        return self._name

    @property
    def age(self):
        return self._age

    @age.setter
    def age(self, age):
        self._age = age

    def play(self):
        print("%s正在愉快的玩耍." % self._name)

    def watch_tv(self):
        print("%s正在看《小电影》." % self._name)


class Student(Person):
    """学生"""
    def __init__(self, name, age, major):
        super().__init__(name, age)
        self._major = major

    @property
    def major(self):
        return self._major

    @major.setter
    def major(self, major):
        self._major = major

    def study(self, course):
        print("%s正在快乐的学习%s." % (self._name, course))


class Teacher(Person):
    """老师"""

    def __init__(self, name, age, title):
        super().__init__(name, age)
        self._title = title

    @property
    def title(self):
        return self._title

    @title.setter
    def title(self, title):
        self._title = title

    def teach(self, cource):
        print("%s老师正在讲%s." % (self._name, cource))



def main():
    stu = Student("ahoj", 15, "高一")
    stu.play()
    stu.study("计算机组成原理")

    t = Teacher("Tim", 20, "老司机")
    t.teach("Python程序设计")
    t.play()
    t.watch_tv()


if __name__ == '__main__':
    main()

