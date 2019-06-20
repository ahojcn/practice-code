from abc import ABCMeta, abstractmethod

class Pet(object, metaclass=ABCMeta):
    """宠物"""

    def __init__(self, nickname):
        self._nickname = nickname

    @abstractmethod
    def make_voice(self):
        """发出声音，虚函数"""
        pass


class Dog(Pet):
    """狗狗"""
    def make_voice(self):
        print("%s 汪汪汪..." % self._nickname)



class Cat(Pet):
    """猫咪"""
    def make_voice(self):
        print("%s 喵喵喵..." % self._nickname)


def main():
    pets = [Dog('熊熊'), Cat('Kid'), Dog('旺旺')]
    for p in pets:
        p.make_voice()

if __name__ == '__main__':
    main()