import functools

# 把一个函数的某些参数设置默认值，返回一个新的函数，调用这个新函数会更简单。

def show(*args, **kw):
    print(args)
    print(kw)

p1 = functools.partial(show, 1, 2, 3)
p1()
p1(4, 5, 6)
p1(a = 'Python', b = 'ahojcn')


print(" 分割线 ".center(50, '-'))


p2 = functools.partial(show, a = 3, b = 'Linux')
p2()
p2(1, 2)
p2(a = 'Python', b = 'ahojcn')