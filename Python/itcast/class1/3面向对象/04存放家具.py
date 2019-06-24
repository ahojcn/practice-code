"""
房子类
"""
class Home:
    def __init__(self, area, info, addr):
        self._area = area # 总面积
        self._info = info
        self._addr = addr
        self._left_area = area # 剩余面积
        self._contain_items = [] # 房子里有的东西

    def __str__(self):
        return "面积：" + str(self._area) \
            + "户型：" + self._info \
            + "地址：" + self._addr \
            + "可用面积：" + str(self._left_area) \
            + "房子里有：" + str(self._contain_items)

    def add_item(self, item):
        self._left_area -= int(item.get_area())
        self._contain_items.append(item.get_name())


class Bed:
    def __init__(self, name, area):
        self._name = name
        self._area = area

    def __str__(self):
        return str(self._area) + "平米的" + self._name

    def get_name(self):
        return self._name

    def get_area(self):
        return self._area



if __name__ == "__main__":
    fangzi = Home(120, "三室一厅", "杭州市")
    print(fangzi)

    print("买了一张床")
    bed1 = Bed("席梦思", 4)
    fangzi.add_item(bed1)
    print(fangzi)

    print("又买了一张床")
    bed2 = Bed("双人床", 6)
    fangzi.add_item(bed2)
    print(fangzi)