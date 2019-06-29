"""
集合对象还支持union(联合), intersection(交), difference(差)和sysmmetric_difference(对称差集)等数学运算
"""

x = set('abcd')
y = {'h', 'e', 'l', 'l', 'o'}
z = set('spam')

# 交集
print(y & z)

# 交集
print(x & z)

# 并集
print(x | y)

# 差集
print(x - y)
print(y - x)

# 对称差集(在x或z中，但不会同时出现在二者中)
print(x ^ z)