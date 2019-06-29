def getAverage(a, b):
    result = (a + b) / 2
    print("result = %d" % result)
    return result

if __name__ == "__main__":
    a = 100
    b = 200
    ret = getAverage(a, b)
    print(ret)