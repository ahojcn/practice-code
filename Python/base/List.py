#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# list test 列表测试

ls = [1, 2, 3]

ps = ['ahojcn', 'baozi', 'fc', 'jp', 'mh', 'ax', 1, ls]

print(ps[len(ps) - 1][0])

ps.append('adam')

ps.insert(0, 'test')

ps.pop(0) # 删除 test

ps[0] = 'ahoj'

for i in ps:
    print(i)

print('-----')

l0 = ['a', 'c', 'b']
print('before sort : ', l0)
l0.sort()
print('after sort : ', l0)