"""
使用 type 动态创建一个类
type(类名, 由父类名称组成的元组（针对集成的情况，可以为空）, 包含属性的字典（名称和值）)
"""

Person = type("Person", (), {})
p1 = Person()
print(type(p1))

def printName(self):
    print(self.name)

Student = type("Student", (Person,), {"name": 'ahojcn', "age": 20, "printName": printName})
s1 = Student()
s1.printName()
print(s1.age)

# 元类就是用来创建这些类（对象）的，元类就是类的类
# MyClass = MetaClass() # 使用元类创建出一个对象，这个对象成为'类'
# MyObject = MyClass() # 使用'类'来创建出实例对象

print(Person.__class__)
print(Student.__class__)
print(p1.__class__)
print(s1.__class__)

print(type.__class__) # type