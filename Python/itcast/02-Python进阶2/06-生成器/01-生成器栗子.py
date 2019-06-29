"""
如果直接弄一个很大的 list 或者别的会很占用内存
生成器就是 占用少量的内存，我还想要这个结果
每次只生成一个，到最后一个异常退出
"""

if __name__ == '__main__':
    b = (x * 2 for x in range(6)) # 生成 0*2 - 5*2

    print(b)

    print(next(b))
    print(next(b))
    print(next(b))

    print(next(b))
    print(next(b))
    print(next(b))

    '''到了生成器的最后一个，再next()就会抛出异常'''
    # print(next(b))