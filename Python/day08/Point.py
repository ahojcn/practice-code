from math import sqrt

class Point(object):

    def __init__(self, x=0, y=0):
        """
        初始化方法
        :param x: 横坐标
        :param y: 纵坐标
        """
        self._x = x
        self._y = y

    def move_to(self, x, y):
        """
        移动到指定位置
        :param x: 新的横坐标
        :param y: 新的纵坐标
        :return:
        """
        self._x = x
        self._y = y

    def move_by(self, dx, dy):
        """
        移动指定的增量
        :param dx: 横坐标的增量
        :param dy: 纵坐标的增量
        """
        self._x += dx
        self._y += dy

    def distance_to(self, other):
        """
        计算与另一个点的举例
        :param other: 另一个点
        :return: 返回距离
        """
        dx = self._x - other._x
        dy = self._y - other._y
        return sqrt(dx ** 2 + dy ** 2)

    def __str__(self):
        return '(%s, %s)' % (str(self._x), str(self._y))

def main():
    p1 = Point(3, 5)
    p2 = Point()
    print(p1)
    print(p2)
    p2.move_by(-1, 2)
    print(p2)
    print(p1.distance_to(p2))

if __name__ == '__main__':
    main()