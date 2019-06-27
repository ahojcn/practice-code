def test(num):

    print("1")

    def test_in(num2):
        print("2")
        print(num + num2)

    print("3")

    return test_in

if __name__ == '__main__':
    ret = test(1)

    ret(10)
    ret(100)