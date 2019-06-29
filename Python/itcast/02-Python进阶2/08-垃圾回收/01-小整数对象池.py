a = 100
b = 100

print(id(a))
print(id(b))


# 小整数对象 常驻内存
del a
del b
c = 100
print(id(c))
