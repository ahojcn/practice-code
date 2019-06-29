def test1():
    print(1 / 0)

def test2():
    test1()

def test3():
    try:
        test2()
    except Exception as e:
        print(e)


if __name__ == "__main__":
    test3()