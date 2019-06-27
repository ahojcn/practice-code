def func(fn):
    print("func - 1")

    def func_in():
        print("func - 2")
        r = fn()
        print("func - 3")
        return r

    print("func - 4")
    return func_in


@func
def test():
    print("---test---")
    return "haha"


if __name__ == '__main__':
    ret = test()
    print(ret)
