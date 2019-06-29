class Animal:

    def __init__(self, name, age):
        self.__name = name
        self.__age = age

    def __str__(self):
        return 'name:' + self.__name + ', age:' + str(self.__age)

    def eat(self):
        print(self.__name + " eatting...")

    def drink(self):
        print(self.__name + " drinking...")


class Cat(Animal):

    def __init__(self, name, age, type):
        self.__type = type
        return super().__init__(name, age)

    def __str__(self):
        return super().__str__() + ', type:' + self.__type

    def sleep(self):
        print(self._Animal__name + " 睡觉觉...")

    # 重写
    def eat(self):
        print(self._Animal__name + " 吃吃吃吃吃吃胖...")
        # Cat.eat(self)  # Error ???
        super().eat()


if __name__ == "__main__":
    c1 = Cat("猪皮", 1, "橘猫")
    c1.eat()
    c1.drink()
    c1.sleep()
    print(c1)