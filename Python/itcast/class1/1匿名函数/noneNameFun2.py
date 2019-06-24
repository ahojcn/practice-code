# coding=utf-8
"""
匿名函数 2
"""
def test(a, b, func):
    result = func(a, b)
    return result

# py 2
# func_new = input("请输入一个匿名函数：")

# py 3 输入的东西默认都是 string
func_new = input("请输入一个匿名函数：")
# 使用 eval 把字符串转换成一个真正的表达式
func_new = eval(func_new)

num = test(1, 2, func_new)
print(num)