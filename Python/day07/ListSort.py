def main():
    l1 = ['orange', 'apple', 'mango', 'blueberry']
    l2 = sorted(l1)
    print(l1)
    print(l2)
    # sorted 函数返回列表排序后的拷贝，不会修改传入的列表
    # 函数的设计就应该像sorted一样尽可能不产生副作用
    l3 = sorted(l1, reverse=True)
    print(l3)

    # 通过 key 关键字参数指定根据字符串长度进行排序而不是默认的字母顺序
    l4 = sorted(l1, key=len)
    print(l4)

    # 给列表对象发出排序消息，直接在列表对象上进行排序
    l1.sort(reverse=True)
    print(l1)

if __name__ == '__main__':
    main()