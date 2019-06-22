"""
读文件
"""

def main():
    f = None
    try:
        f = open('./1.txt', 'r', encoding='utf-8')
        print(f.read())
    except FileNotFoundError:
        print('无法打开指定文件！')
    except LookupError:
        print("未知编码方式！")
    except UnicodeDecodeError:
        print("读取文件时解码错误！")
    finally:
        if f:
            f.close()

"""
如果不愿意在finally代码块中关闭文件对象释放资源，
也可以使用上下文语法，
通过with关键字指定文件对象的上下文环境并在离开上下文环境时自动释放文件资源，
代码如下所示
"""

def test():
    try:
        with open('./1.txt', 'r', encoding='utf-8') as f:
            print(f.read())
    except FileNotFoundError:
        print("无法打开指定文件")
    except LookupError:
        print("指定了未知编码")
    except UnicodeDecodeError:
        print("读取文件时解码错误")

import time
def rl():
    # 一次性读取整个文件内容
    with open('./1.txt', 'r', encoding='utf-8') as f:
        print(f.read())

    # 通过循环逐行读取
    with open('./1.txt', 'r', encoding='utf-8') as f:
        for line in f:
            print(line, end='')
            time.sleep(0.5)
    print()

    # 读取文件安航读取到列表中
    with open('./1.txt') as f:
        lines = f.readlines()
    print(lines)



if __name__ == '__main__':
    rl()