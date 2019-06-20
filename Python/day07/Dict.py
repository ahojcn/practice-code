def main():
    scores = {'ahojcn': 100, 'Tim': 80, 'Bob': 99}
    # key - value
    # 通过 key 可以获取 value
    print(scores['ahojcn'])

    # 对字典进行遍历（遍历的启示是 key，再通过 key 获取对应的 value）
    for e in scores:
        print(e, '->', scores[e])

    # 更新字典中的元素
    scores['ahojcn'] = 98
    scores.update(test=67, jack=100)
    print(scores)

    # print(scores['fc'])  # KeyError: 'fc'
    if 'fc' in scores:
        print(scores['fc'])

    print(scores.get('ahojcn'))
    # get 方法也是通过获取对应的值，但是可以设置默认值
    print(scores.get('武则天', 60))
    print(scores)

    # 删除字典中的元素
    print(scores.popitem())
    print(scores.popitem())
    print(scores.pop('ahojcn'))
    print(scores)

    # 清空字典
    scores.clear()
    print(scores)

if __name__ == '__main__':
    main()