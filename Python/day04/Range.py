"""
for 循环
"""

# 求 1~100 的和
sum = 0
for i in range(101):
    sum += i
print(sum)

"""
range(101)可以产生一个0到100的整数序列。
range(1, 100)可以产生一个1到99的整数序列。
range(1, 100, 2)可以产生一个1到99的奇数序列，其中的2是步长，即数值序列的增量。
"""

# 计算 1~100 之间的偶数和
sum = 0
for i in range(2, 101, 2):
    sum += i
print(sum)