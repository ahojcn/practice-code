"""
使用装饰器时，有一些细节需要被注意。例如，被装饰后的函数其实已经是另外一个函数了（函数名等函数属性会发生改变）。

添加后由于函数名和函数的doc发生了改变，对测试结果有一些影响
"""

import functools

def note(func):
    """note function"""
    @functools.wraps(func)
    def wrapper():
        """wrapper function"""
        print('note something')
        return func()
    return wrapper

@note
def test():
    """test function"""
    print('I am test')

if __name__ == '__main__':
    test()
    print(help(test))
    print(test.__doc__)

