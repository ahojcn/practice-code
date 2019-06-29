"""
py2 的内建函数
py3 已经把 reduce 从全局名字空间移除了
"""

from functools import reduce

# 1+2+3+4
a = reduce(lambda x,y:x+y, [1,2,3,4])
print(a)


b = reduce(lambda x,y:x+y, [1,2,3,4], 5)
print(b)


str = reduce(lambda x, y : x + y, ['aa', 'bb', 'cc'], 'dd')
print(str)
