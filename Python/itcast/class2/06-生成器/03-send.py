def test():
    i = 0
    while i < 5:
        # 这里并不是把 yield 的产生的值反悔了
        temp = yield i
        print(temp)
        i += 1


if __name__ == '__main__':
    t = test()

    print(t.__next__())

    print(t.__next__())

    # 相当于把这个 haha 当做 yield 的结果 给了 temp
    t.send("haha-------->")

    print(t.__next__())

