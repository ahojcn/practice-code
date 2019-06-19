#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
Python内置了字典：dict的支持，dict全称dictionary，
在其他语言中也称为map，使用键-值（key-value）存储，具有极快的查找速度。
dict内部存放的顺序和key放入的顺序是没有关系的

这个通过key计算位置的算法称为哈希算法（Hash）

和list比较，dict有以下几个特点：
    1. 查找和插入的速度极快，不会随着key的增加而变慢；
    2. 需要占用大量的内存，内存浪费多。
dict是用空间来换取时间的一种方法。

需要牢记的第一条就是dict的key必须是不可变对象。
"""

d = {'ahoj': 90, 'tim': 85, 'bob': 75}
d['ahoj'] = 100
print(d['ahoj'])

# error
# d['test']

print('ahoj' in d) # 看看 ahoj 这个 key 在 d 中有没有，True

print(d.get('test')) # None
print(d.get('test', -1)) # -1，是自己指定的，如果没有找到就是 -1
print(d.get('ahoj', -1))

# 删除一个key
print('pop : %d' % d.pop('tim'))
print(d)

# 获取 d 的 key 集合
print(d.keys())
# dict_keys(['ahoj', 'bob'])
