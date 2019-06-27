def func(fn):

    def func_in(*args, **kwargs):
        print("记录日志")
        r = fn(*args, **kwargs)
        return r

    return func_in


@func
def test1():
    print("---test1---")
    return "hello"

@func
def test2():
    print("---test2---")

@func
def test3(aa):
    print("---test3---%d" % aa)


if __name__ == '__main__':
    ret = test1()
    print(ret)

    a = test2()
    print(a)

    test3(1)
