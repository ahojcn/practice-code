def create():
    print("start")

    a,b = 0,1
    for i in range(5):
        print("1")
        yield b # 只要函数里有 yield，就生成了一个对象，返回 b
        print("2")
        a,b = b,a+b
        print("3")

    print("end")


if __name__ == '__main__':

    '''这里接收返回来的对象'''
    c = create()

    # next(c)
    # next(c)

    # 取得生成器的值 1
    for num in c:
        print(num)

    # 取得生成器的值 2
    # ret = c.__next__()
    # print(str(ret).center(10))
    # next(c)
    # ret = c.__next__()
    # print(str(ret).center(10))
    # next(c)
    # ret = c.__next__()
    # print(str(ret).center(10))

