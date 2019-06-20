from time import time, localtime, sleep

class Clock(object):
    """数字时钟"""

    def __init__(self, h=0, m=0, s=0):
        self._h = h
        self._m = m
        self._s = s

    @classmethod
    def now(cls):
        ctime = localtime(time())
        return cls(ctime.tm_hour, ctime.tm_min, ctime.tm_sec)

    def run(self):
        """走字"""
        self._s += 1
        if self._s == 60:
            self._s = 0
            self._m += 1
            if self._m == 60:
                self._m = 0
                self._h += 1
                if self._h == 24:
                    self._h = 0

    def show(self):
        """显示时间"""
        return "%02d : %02d : %02d" % (self._h, self._m, self._s)

def main():
    # 通过类方法创建并获取系统时间
    clock = Clock.now()
    while True:
        print(clock.show())
        sleep(1)
        clock.run()

if __name__ == '__main__':
    main()