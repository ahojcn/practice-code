class SweetPotato:

    def __init__(self):
        """
        cookedLevel 是一个数字
        [0, 3) 生的；[3, 5) 半生不熟；[5, 8) 完美；[8, ~) 烤糊了
        """
        self._cookedString = "生的"
        self._cookedLevel = 0
        # 撒的调料
        self._condiments = []

    def __str__(self):
        return "地瓜状态" + self._cookedString \
            + "（%d）" % self._cookedLevel \
            + str(self._condiments)
    
    def cook(self, cooked_time):
        self._cookedLevel += cooked_time
        if self._cookedLevel >= 0 and self._cookedLevel < 3:
            self._cookedString = "生的"
        elif self._cookedLevel >= 3 and self._cookedLevel < 5:
            self._cookedString = "半生不熟"
        elif self._cookedLevel >= 5 and self._cookedLevel < 8:
            self._cookedString = "烤熟了"
        else:
            self._cookedString = "烤糊了"

    # 添加作料
    def addCondiments(self, condiments):
        self._condiments.append(condiments)


if __name__ == "__main__":
    di_gua = SweetPotato()
    for i in range(0, 10):
        if i == 5:
            di_gua.addCondiments("葱")
            di_gua.addCondiments("蒜")
        di_gua.cook(1)
        print(di_gua)

