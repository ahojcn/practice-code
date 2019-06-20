from time import sleep

class Clock(object):
    """
    数字时钟
    """

    def __init__(self, h=0, m=0, s=0):
        """
        初始化方法

        :param h: 时
        :param m: 分
        :param s: 秒
        """
        self._hour = h
        self._minute = m
        self._second = s

    def run(self):
        """走字"""
        self._second += 1
        if self._second == 60:
            self._minute += 1
            self._second = 0
            if self._minute == 60:
                self._hour += 1
                self._minute = 0
                if self._hour == 24:
                    self._hour = 0

    def show(self):
        """显示时间"""
        return '%02d:%02d:%02d' % (self._hour, self._minute, self._second)

def main():
    c = Clock(23, 59, 58)
    while True:
        print(c.show())
        sleep(1)
        c.run()


if __name__ == '__main__':
    main()