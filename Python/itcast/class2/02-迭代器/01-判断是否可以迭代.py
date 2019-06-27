"""
可以使用 isinstance() 判断一个对象是否是 Iterable 对象（是否可以迭代）
"""

from collections import Iterable

if __name__ == '__main__':
    a = [11, 22]
    print(isinstance(a, Iterable))

    b = {11, 22}
    print(isinstance(b, Iterable))

    c = (11, 22)
    print(isinstance(c, Iterable))



"""
iter() 函数
生成器都是 Iterator 对象，但 list、dict、str 虽然是 Iterable，却不是 Iterator
把 list、dict、str 等 Iterable 编程 Iterator 可以使用 Iter() 函数
"""
isinstance(iter([]), Iterable)  # True
isinstance(iter('abc'), Iterable)   # True



"""
生成器
(x for x in range(10))
"""