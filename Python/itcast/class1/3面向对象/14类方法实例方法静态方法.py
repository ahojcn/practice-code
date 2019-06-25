class Game(object):

    # 类属性
    __num = 0

    # 实例方法
    def __init__(self):
        # 实例属性
        self.__name = "老王"
        Game.__num += 1
    
    # 类方法
    @classmethod  # 装饰器
    def add_num(cls):
        cls.__num += 1

    @classmethod
    def get_num(cls):
        return cls.__num

    # 静态方法
    @staticmethod  # 有了这个装饰器 就可以不传入 self 参数
    def print_menu():
        print("".center(50, "-"))
        print("穿越火线".center(50, " "))
        print("".center(50, "-"))



if __name__ == "__main__":
    g1 = Game()
    # 调用 类方法
    Game.add_num()  # 1
    g1.add_num()  # 2

    print(Game.get_num())

    # 调用 静态方法
    Game.print_menu()  # 1
    g1.print_menu()  # 2