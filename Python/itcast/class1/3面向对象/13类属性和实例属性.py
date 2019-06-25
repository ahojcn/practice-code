class Tool(object):
    # 类属性，所有对象（实例属性）共享类属性
    __num = 0

    def __init__(self, name):
        # 对象属性(实例属性)
        self.__name = name
        Tool.__num += 1

    # 类方法
    @classmethod
    def get_num(cls):
        return cls.__num



if __name__ == "__main__":
    t1 = Tool("铁锹")
    t2 = Tool("锄头")
    t3 = Tool("水桶")
    print(Tool.get_num())