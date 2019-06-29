"""
类名用大驼峰
"""
class Cat:

    def __init__(self, name, age, sex):
        self._name = name
        self._age = age
        self._sex = sex

    def eat(self):
        print(self._name + "吃鱼...")

    def drink(self):
        print(self._name + "喝可乐...")

    def info(self):
        print("name:" + self._name + \
            ", age:" + str(self._age) + \
                ", sex:" + self._sex)



tom = Cat("汤姆", 20, "女")
tom.eat()
tom.drink()
tom.info()

# # 这里还可以给tom添加一个属性
# tom.sex = "男"
# # 获取属性的第一种方式
# print(tom.sex)

print("------------")

lanmao = Cat("蓝猫", 10, "女")
lanmao.eat()
lanmao.drink()
lanmao.info()
