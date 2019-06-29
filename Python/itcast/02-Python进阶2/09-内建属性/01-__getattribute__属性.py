"""
常用专有属性	说明	触发方式
__init__	构造初始化函数	创建实例后,赋值时使用,在__new__后
__new__	生成实例所需属性	创建实例时
__class__	实例所在的类	实例.__class__
__str__	实例字符串表示,可读性	print(类实例),如没实现，使用repr结果
__repr__	实例字符串表示,准确性	类实例 回车 或者 print(repr(类实例))
__del__	析构	del删除实例
__dict__	实例自定义属性	vars(实例.__dict__)
__doc__	类文档,子类不继承	help(类或实例)
__getattribute__	属性访问拦截器	访问实例属性时
__bases__	类的所有父类构成元素	类名.__bases__
"""

# __getattribute__ 属性拦截器

class Test(object):
    def __init__(self, subject):
        self.subject = subject
        self.other = 'C/Cpp'

    # 属性访问时拦截器，打印log
    def __getattribute__(self, item):
        if item == 'subject':
            print("log subject")
            return "redirect python"
        else:
            return object.__getattribute__(self, item)

    def show(self):
        print("this is Test class")


if __name__ == '__main__':
    s = Test("Python")
    print(s.subject)
    print(s.other)
    s.show()