def test(num):

    """
    在函数内部再定义一个函数，并且这个函数用到了外边函数的变量(num)
    那么将这个函数以及用到的一些变量称之为 闭包
    """
    def test_in(num_in):
        print("in test_in function, num_in is %d" % num_in)
        return num + num_in

    """
    其实这里返回的就是闭包的结果
    """
    return test_in


if __name__ == '__main__':
    ret = test(1)

    print(ret(10))
    print(ret(20))