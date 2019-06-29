class Store(object):
    def order(self, car_type):
        return self.select_car(car_type)

    def select_car(self, car_type):
        pass


class CarStore(Store):
    def __init__(self):
        self.__factory = Factory()

    def select_car(self, car_type):
        return BMWFactory().select_car_by_type(car_type)


class BMWStroe(Store):
    def __init__(self):
        pass


#  解耦，工厂类
class Factory(object):
    def select_car_by_type(car_type):
        if car_type == "索纳塔":
            return Suonata()
        elif car_type == "名图":
            return Mingtu()
        elif car_type == "Ix35":
            return Ix35()


class Car(object):
    def drive(self):
        print("开车...")
    
    def music(self):
        print("听音乐...")

    def stop(self):
        print("停车...")


def Suonata(Car):
    pass


def Mingtu(Car):
    pass


def Ix35(Car):
    pass


if __name__ == "__main__":
    cs = CarStore()
    car1 = cs.order("索纳塔")
    car1.drive()
    car1.music()
    car1.stop()