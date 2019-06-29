class ShortInputException(Exception):
    '''自定义异常类'''
    def __init__(self, length, atlieast):
        self.length = length
        self.atlieast = atlieast
        

def main():
    try:
        s = input("请输入 -> ")
        if len(s) < 3:
            # raise 引发一个自定义异常
            raise ShortInputException(len(s), 3)
    except ShortInputException as e:
        print("ShortInputException, 输入长度(%d), 最小长度(%d)" % (e.length, e.atlieast))


if __name__ == "__main__":
    main()