def main():
    t = ('ahojcn', 18, True, '陕西西安')
    print(t)
    print(t[0], t[1])
    # 遍历
    for item in t:
        print(item, end=' ')
    print()

    # 重新给元组赋值
    # t[0] = '王大锤' # TypeError
    # 变量 t 重新引用了新的元组，原来的元组将被垃圾回收
    t = ('Tim', 20, True, '陕西汉中')
    print(t)

    # 元组 -> 列表
    person = list(t)
    print(person)

    # 列表可以修改元素
    person[0] = '李小龙'

    # 列表 -> 元组
    t = tuple(person)
    print(t)




if __name__ == '__main__':
    main()