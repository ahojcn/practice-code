#!/usr/bin/env python3
# 告诉 Linux/OS X 系统，这是一个 Python 可执行程序，Windows 系统会忽略这个注释
# -*- coding: utf-8 -*-
# 告诉Python解释器，按照UTF-8编码读取源代码，否则，你在源代码中写的中文输出可能会有乱码。

print(r'''hello,\n
world''')

classmates = ['ahojcn', 'fc', 'mc', 'jp']
print(classmates)
len(classmates)


print('hello python.')
print(3**3)

# 获取用户输入
print('input you name : ')
name = input()
print('hello, ', name)

# turtle 海龟画图
import turtle

turtle.pensize(4)
turtle.pencolor('red')
turtle.forward(100)
turtle.right(90)
turtle.forward(100)
turtle.right(90)
turtle.forward(100)
turtle.right(90)
turtle.forward(100)
turtle.mainloop()
