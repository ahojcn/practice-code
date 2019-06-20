class Test:

    # 在 python 中，属性和方法的访问权限也只有两种，也是就是 private 和 public
    # 如果希望属性是私有的，在给属性命名时用两个下划线作为开头
    def __init__(self, foo):
        self.__foo = foo

    def __bar(self):
        print(self.__foo)
        print("__bar()")

def main():
    t1 = Test("Hello")
    # AttributeError: 'Test' object has no attribute '__bar'
    # t1.__bar()
    # AttributeError: 'Test' object has no attribute '__foo'
    # print(t1.__foo)

    """
    但是，Python并没有从语法上严格保证私有属性或方法的私密性，
    它只是给私有的属性和方法换了一个名字来“妨碍”对它们的访问，
    事实上如果你知道更换名字的规则仍然可以访问到它们，
    下面的代码就可以验证这一点。
    之所以这样设定，可以用这样一句名言加以解释，
    就是“We are all consenting adults here”。
    因为绝大多数程序员都认为开放比封闭要好，
    而且程序员要自己为自己的行为负责。
    """
    t1._Test__bar()
    print(t1._Test__bar())
    """
    在实际开发中，我们并不建议将属性设置为私有的，因为这会导致子类无法访问（后面会讲到）。
    所以大多数Python程序员会遵循一种命名惯例就是让属性名以单下划线开头来表示属性是受保护的，
    本类之外的代码在访问这样的属性时应该要保持慎重。
    这种做法并不是语法上的规则，单下划线开头的属性和方法外界仍然是可以访问的，
    所以更多的时候它是一种暗示或隐喻
    """

if __name__ == '__main__':
    main()