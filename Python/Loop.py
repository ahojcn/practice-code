#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# for loop

names = ['ahoj', 'tim', 'baozi']
for name in names:
    print(name)

sum = 0
for x in [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]:
    sum += x
print(sum)

# 上面这么写太麻烦了
# range() 函数可以生成一个整数序列，再通过 list() 函数可以转换成 list
sum = 0
for i in list(range(101)):   # 生成 0 - 100 的整数序列
    sum += i
print(sum)

##############
# while loop #

# 计算100以内所有奇数之和
sum = 0
n = 99
while n > 0:
    sum += n
    n -= 2
print(sum)


# break and continue

n = 1
while n <= 100:
    if n > 10:
        break
    print(n)
    n += 1
print('END')

# 打印 10 内的奇数
n = 0
while n < 10:
    n += 1
    if n % 2 == 0:
        continue
    print(n)

# 死循环
while True:
    pass