class Dog:
    
    def __init__(self, name, age):
        self.__name = name
        self.__age = age

    def set_age(self, age):
        assert age > 0 and age < 30
        self.__age = age


if __name__ == "__main__":
    d1 = Dog("hh", 10)
    # print(d1.__name)  # 不能