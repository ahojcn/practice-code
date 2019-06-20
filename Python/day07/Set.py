"""
set 集合
python 中的集合和数学上的集合是一致的
不允许有重复元素，而且可以进行交集、并集、差集等运算
"""
def main():
    s1 = {1, 2, 3, 2, 1}
    print(s1)
    print('len(s1) = %d' % len(s1))

    s2 = set(range(1, 10))
    print(s2)

    s1.add(4)
    s1.add(5)
    print(s1)
    s2.discard(5) # 删除 5
    print(s2)

    # remove 元素，如果不存在会引发 TypeError
    if 4 in s2:
        s2.remove(4)
    print(s2)

    # 遍历集合
    for e in s2:
        print(e ** 2, end=' ')
    print()
    print(s2)

    # 元组 -> 集合
    s3 = set((1, 2, 3, 2, 1))
    print(s3)
    print(s3.pop())

    print(" 集合运算 ".center(50, '#'))
    se1 = {1, 2, 3}
    se2 = {2, 3, 4, 5}
    # 交
    print(se1 | se2)
    # 并
    print(se1 & se2)
    # 差
    print(se1 ^ se2)
    print(se1.symmetric_difference(se2))

    # 判断子集和超集
    print(se2 <= se1)
    print(se2.issubset(s1))
    print(se2 >= se1)


if __name__ == '__main__':
    main()