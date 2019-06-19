#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# 元组 tuple test
# 这个tuple不能变了，它也没有append()，insert()这样的方法。其他获取元素的方法和list是一样的
t0 = ('ahojcn', 'bob', 'tim')

print(t0)

t1 = ()

# 定义只有一个元素的 tuple 时必须加一个逗号
# Python在显示只有1个元素的tuple时，也会加一个逗号,，以免你误解成数学计算意义上的括号。

t2 = (1,)
print(t2)