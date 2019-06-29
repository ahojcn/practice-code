"""
__str__ 相当于 Java 中的 toString()
"""
class Cat:

    def __init__(self, name, age, sex):
        self._name = name
        self._age = age
        self._sex = sex

    def __str__(self):
        return "姓名：" + self._name \
            + "年龄：" + str(self._age) \
            + "性别：" + self._sex

    def eat(self):
        print(self._name + "吃鱼...")

    def drink(self):
        print(self._name + "喝可乐...")

    def info(self):
        print("name:" + self._name + \
            ", age:" + str(self._age) + \
            ", sex:" + self._sex)



tom = Cat("汤姆", 20, "男")
print(tom)

print(" 分界线 ".center(50, "*"))

lanmao = Cat("蓝猫", 10, "女")
print(lanmao)
