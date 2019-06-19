#!/usr/bin/env python3
# -*- coding: utf-8 -*-

age = input()
age = int(age)

if age >= 18:
    print('your age is', age)
    print('adult')
else:
    print('your age is', age)
    print('teenager')

print('----')

if age >= 18:
    print('adult')
elif age >= 6:
    print('teenager')
else:
    print('kid')

# 只要x是非零数值、非空字符串、非空list等，就判断为True，否则为False。
x = []
if x:
    print('x')