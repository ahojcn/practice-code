def func(fn):
    print("func - 1")

    def func_in(a, b):
        print("func - 2")
        fn(a, b)
        print("func - 3")

    print("func - 4")
    return func_in


@func
def test(a, b):
    print("---test---a=%d,b=%d" % (a, b))


if __name__ == '__main__':
    test(11, 22)
