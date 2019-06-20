import os
import time

def main():
    str = "北京欢迎您……"
    while True:
        # 清理屏幕上的输出
        os.system('clear')
        print(str)
        # 休眠 200 毫秒
        time.sleep(0.2)
        str = str[1:] + str[0]


if __name__ == '__main__':
    main()