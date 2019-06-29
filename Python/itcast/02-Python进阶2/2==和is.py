"""
== 判断的是值是否相等
is 判断指向的是不是同一个东西
"""

a = [11, 22, 33]
b = [11, 22, 33]
print(a == b) # True
print(a is b) # False

c = a
print(id(a))
print(id(b))
print(id(c))


n1 = 100
n2 = 100
print(n1 == n2)
print(n1 is n2)

m1 = 100000
m2 = 100000
print(m1 == m2)
print(m1 is m2)
print(id(m1))
print(id(m2))