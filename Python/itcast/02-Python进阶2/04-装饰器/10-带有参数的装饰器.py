def func_arg(pre = "hello"):
    def func(fn):
        def func_in():
            print("记录日志 %s" % pre)
            fn()

        return func_in
    return func

"""
1. 先执行 func_arg("heihei") 函数，这个函数 return 的结果是 func 这个函数的引用
2. @func
3. 使用 @func 对 test 进行装饰
"""
@func_arg("嘿嘿")
def test1():
    print("---test1---")

"""
带有参数的装饰器能够起到在运行时，有不用的功能
"""
@func_arg("哈哈")
def test2():
    print("---test2---")


if __name__ == '__main__':
    test1()
    test2()
