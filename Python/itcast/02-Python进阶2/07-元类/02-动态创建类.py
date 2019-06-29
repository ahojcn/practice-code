def choose_class(name):
    if name == 'foo':
        class Foo(object):
            pass
        return Foo # 返回的是类，不是类的实例
    else:
        class Bar(object):
            pass
        return Bar


if __name__ == '__main__':
    mc = choose_class('foo')
    print(mc)   # 函数返回的是类，不是类的实例
    print(mc()) # 可以通过这个类创建实例对象
