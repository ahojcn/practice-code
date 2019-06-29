"""
__metaclass__ 属性
"""

class Person(object):
    __metaclass__ = "hello world"

    # 这个属性决定了这个类长什么样子
    # 不指定，使用系统默认的


def upper_attr(future_class_name, future_class_parents, future_class_attr):

    # 遍历字典，把不是__开头的属性名称变成大写
    newAttr = {}
    for name, value in future_class_attr.items():
        if not name.startswith("__"):
            newAttr[name.upper()] = value

    # 调用 type 创建一个类
    return type(future_class_name, future_class_parents, newAttr)



class Foo(object, metaclass=upper_attr):
    # __metaclass__ = upper_attr # py2 要写在这里
    bar = 'bip'


if __name__ == '__main__':
    print(hasattr(Foo, 'bar'))
    print(hasattr(Foo, 'BAR'))

    f = Foo()
    print(f.BAR)