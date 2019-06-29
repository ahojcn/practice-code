def test(a, b):

    def test_in(x):
        print(a * x + b)

    return test_in

if __name__ == '__main__':
    l1 = test(1, 1)
    l1(0)

    l2 = test(10, 4)
    l2(0)
