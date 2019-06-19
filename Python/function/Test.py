#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from absTest import my_abs
import math

print('my_abs(-9) : ', my_abs(-9))

num = 10
print(str(hex(num)))


def nop():
    pass


'''
从一个点移动到另一个点，给出坐标、位移、角度，计算新的坐标
'''


def move(x, y, step, angle=0.0):
    nx = x + step * math.cos(angle)
    ny = y - step * math.sin(angle)
    return nx, ny


r = move(100, 100, 60, math.pi / 6)
print('r :', r)

x1, y1 = move(100, 100, 60, math.pi / 6)
print(x1, y1)


def power(x, n=2):
    s = 1
    while n > 0:
        n -= 1
        s *= x
    return s


print(power(10))
print(power(10, 3))


def add_end(L=None):
    if L is None:
        L = []
    L.append('END')
    return L


print(add_end())
print(add_end())

'''
可变参数
可变参数允许你传入0个或任意个参数，这些可变参数在函数调用时自动组装为一个tuple。
'''


def calc(*num):
    sum = 0
    for i in num:
        sum += i * i
    return sum


print(calc(1, 2))

nums = [1, 2, 3]
print(calc(*nums))  # *nums表示把nums这个list的所有元素作为可变参数传进去。这种写法相当有用，而且很常见。

'''
关键字参数
关键字参数允许你传入0个或任意个含参数名的参数，这些关键字参数在函数内部自动组装为一个dict。
'''
def person(name, age, **kw):
    print('name:', name, 'age:', age, 'other:', kw)

print(person('ahoj', 18))

print(person('tim', 18, city='北京'))

print(person('fc', 18, gender='M', job='学生'))

'''
注意kw获得的dict是extra的一份拷贝，对kw的改动不会影响到函数外的extra。
'''
extra = {'city':'北京', 'job':'学生'}
print(person('jack', 20, **extra))


'''
命名关键字参数
只接收city和job作为关键字参数
命名关键字参数需要一个特殊分隔符*，*后面的参数被视为命名关键字参数
'''
def person2(name, age, *, city='中国', job):
    print(name, age, city, job)

print(person2('ahoj', 20, city='西安', job='学生'))

print(person2('ahojcn', 21, job='学生'))


'''
参数组合
在Python中定义函数，可以用必选参数、默认参数、可变参数、关键字参数和命名关键字参数，
这5种参数都可以组合使用。
但是请注意，参数定义的顺序必须是：
必选参数、默认参数、可变参数、命名关键字参数和关键字参数。
'''
def f1(a, b, c=0, *args, **kw):
    print(a,b,c,args,kw)

def f2(a, b, c=0, *, d, **kw):
    print(a, b, c, d, kw)

print(f1(1, 2))
print(f1(1, 2, c=3))
print(f1(1, 2, 3, 'a', 'b'))
print(f1(1, 2, 3, 'a', 'b', x = 99))
print(f2(1, 2, d = 99, ext = None))