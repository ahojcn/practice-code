def func(fn):
    print("func - 1")

    def func_in():
        print("func - 2")
        fn()
        print("func - 3")

    print("func - 4")
    return func_in


@func
def test():
    print("---test---")


if __name__ == '__main__':
    test()
