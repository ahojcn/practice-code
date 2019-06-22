"""
写文件
计算 1~9999 之间的素数并分别写入三个文件中
    1~99 -> a.txt
    100 ~ 999 -> b.txt
    1000 ~ 9999 -> c.txt
"""

from math import sqrt

def is_prime(n):
    """判断是否是素数，返回True/False"""
    assert n > 0
    if n == 1:
        return False
    for i in range(2, int(sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def main():
    filenames = ['a.txt', 'b.txt', 'c.txt']
    fs_list = []
    try:
        for i in filenames:
            fs_list.append(open(i, 'w', encoding='utf-8'))
        for j in range(1, 10000):
            if is_prime(j):
                if j < 100:
                    fs_list[0].write(str(j) + '\n')
                elif j < 1000:
                    fs_list[1].write(str(j) + '\n')
                else:
                    fs_list[2].write(str(j) + '\n')
    except IOError as e:
        print(e)
        print("写文件时发生错误！")
    finally:
        for f in fs_list:
            f.close()



if __name__ == '__main__':
    main()