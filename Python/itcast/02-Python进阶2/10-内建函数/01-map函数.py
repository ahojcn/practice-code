"""
map函数会根据提供的函数对指定序列做映射
    map(...)
        map(function, sequence[, sequence, ...]) -> list

function:是一个函数
sequence:是一个或多个序列,取决于function需要几个参数
返回值是一个list
"""

# 1
m1 = map(lambda x:x*x, [1,2,3]) # 1, 4, 9
for i in m1:
    print(i, end=' ')
print()

# 2
m2 = map(lambda x, y: x+y, [1,2,3], [4,5,6])
for i in m2:
    print(i, end=' ')
print()

# 3
def fn1(x, y):
    return x, y

l1 = [1,2,3,4,5,6]
l2 = ['Sun', 'M', 'T', 'W', 'T', 'F', 'S']
l3 = map(fn1, l1, l2)
print(list(l3))

