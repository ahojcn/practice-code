def main():
    str1 = "hello, world!"
    print(len(str1))
    # 获取字符串首字母大写的拷贝
    print(str1.capitalize())
    # 获取字符串全部大写后的拷贝
    print(str1.upper())
    # 查找子串所在位置
    print(str1.find("or"))
    print(str1.find("ahojcn"))
    # index 与 find 类似，但找不到子串时会引发异常

    # 检查字符串是否以指定的字符串开头，注意大小写
    print(str1.startswith("he"))
    print(str1.startswith("He"))
    # 检查字符串是否以指定的字符串结尾
    print(str1.endswith("!"))

    # 将字符串以指定的宽度居中并在两侧填充指定的字符
    print(str1.center(50, "*"))
    # 将字符串以指定的宽度靠右放置左侧填充指定的字符
    print(str1.rjust(50, ' '))
    print(str1.ljust(50, ' '))

    print(" 分界线 ".center(100, "#"))

    str2 = "abc123456"
    print(str2[2])
    # 字符串切片（从指定的开始索引到指定的结束索引）
    print(str2[2:5])  # c12
    print(str2[2:])  # c123456
    print(str2[2::2])  # c246
    print(str2[::2])  # ac246
    print(str2[::-1])  # 654321cba
    print(str2[-3:-1])  # 45

    # 检查字符串是否由数字构成
    print(str2.isdigit())  # False
    # 检查字符串是否由字母构成
    print(str2.isalpha())  # False
    # 检查字符串是否以数字和字母构成
    print(str2.isalnum())  # True

    str3 = '  ahojcn@qq.com    '
    print(str3)
    # 获取字符串修建左右两侧空格的拷贝
    print(str3.strip())


if __name__ == '__main__':
    main()