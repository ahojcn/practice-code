def func(fn):
    print("func - 1")

    def func_in(*args, **kwargs):
        print("func - 2")
        fn(*args, **kwargs)
        print("func - 3")

    print("func - 4")
    return func_in


@func
def test(a, b, c):
    print("---test---a=%d,b=%d,c=%d" % (a, b, c))


@func
def test2(a, b, c, d):
    print("---test---a=%d,b=%d,c=%d,d=%d" % (a, b, c, d))

if __name__ == '__main__':
    test(11, 22, 33)
    test2(1, 2, 3, 4)
