"""
匿名函数
"""
def test(a, b, func):
    result = func(a, b)
    return result

num = test(1, 2, lambda x, y : x + y)
print(num)