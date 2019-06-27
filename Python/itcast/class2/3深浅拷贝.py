'''浅拷贝'''
a = [11, 22, 33]
b = a

print("id(a)", end=",")
print(id(a))
print("id(b)", end=",")
print(id(b))


'''深拷贝'''
import copy
c = copy.deepcopy(a)
print("id(a)", end=",")
print(id(a))
print("id(c)", end=",")
print(id(c))


a = [11, 22, 33]
b = [44, 55, 66]
c = [a, b]
print(c)

d = c
print(id(c))
print(id(d))

# 注意这里深拷贝
e = copy.deepcopy(c)
print(id(e))
print("id(e[0]), %d" % id(e[0]))
print("id(a), %d" % id(a))


print(" 分界线 ".center(50, "."))

"""
copy 和 deepcopy 的区别
copy 值拷贝一层
deepcopy 是如果里面还有引用，继续拷贝
"""
a = [1, 2, 3]
b = [4, 5, 6]
c = [a, b]

e = copy.copy(c)
a.append(100)
print(c[0])
print(e[0])

print(id(c))
print(id(e))


"""copy 元组的特点"""
a = [1, 2, 3]
b = [4, 5, 6]
c = (a, b)

e = copy.copy(c)
# 下面的输出是相等的，因为元组是不可变的类型
print(id(c))
print(id(e))