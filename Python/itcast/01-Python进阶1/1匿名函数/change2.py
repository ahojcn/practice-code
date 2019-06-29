"""
交换 2 个变量
"""
a = 4
b = 5
# 第一种 py 独特的方式
print(a, b)
a, b = b, a
print(a, b)

# 第二种
a = a+b
b = a-b
a = a-b
print(a, b)

# 第三种
c = a
a = b
b = c
print(a, b)