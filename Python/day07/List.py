def main():
    l1 = [1, 3, 5, 7, 100]
    print(l1)

    l2 = ['hello'] * 5
    print(l2)

    # 计算列表长度（元素个数）
    print(len(l1))

    print(l1[0], l1[2], l1[-1])
    l1[1] = 300
    print(l1)
    # print(l1[10])  # IndexError: list index out of range

    # 增
    l1.append(200)
    l1.insert(1, 400)
    l1 += [10000, 20000]
    print(l1)
    # 删
    l1.remove(200)  # 如果参数是一个list中没有的元素，出错
    print(l1)
    if 10000 in l1:
        l1.remove(10000)
        print(l1)
    # 清空列表元素
    l1.clear()
    print(l1)

    print(" 分界线 ".center(50, '#'))

    fruits = ['apple', 'grape', 'mango']
    fruits += ['pitaya', 'pear']
    print(fruits)
    # 循环遍历列表
    for f in fruits:
        print(f.title(), end=' ')
    print()

    # 列表切片
    fruits2 = fruits[1:4]
    print(fruits2)
    # fruit3 = fruits 没有复制列表只是创建了新的引用
    # 可以通过完整切片操作来复制列表
    fruits3 = fruits[:]
    print(fruits3)
    fruits4 = fruits3[-3:-1]
    print(fruits4)
    # 可以通过反向切片操作来获得倒转后的列表的拷贝
    fruits5 = fruits3[::-1]
    print(fruits5)
    fruits5.sort()
    print(fruits5)


if __name__ == '__main__':
    main()