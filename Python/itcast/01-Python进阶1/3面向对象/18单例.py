class Dog(object):
    #  类属性
    __instance = None
    __init_flag = False

    def __new__(cls, name):
        if cls.__instance == None:
            cls.__instance = super().__new__(cls)
            return cls.__instance
        else:
            return cls.__instance

    def __init__(self, name):
        if Dog.__init_flag == False:
            self.name = name
            Dog.__init_flag = True


if __name__ == "__main__":
    a = Dog("旺仔")
    print(id(a))
    print(a.name)

    b = Dog("小黑")
    print(id(b))
    print(b.name)