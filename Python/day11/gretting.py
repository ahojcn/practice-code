class Gre(object):

    def __init__(self, name):
        self._name = name

    def _private_1(self):
        return "Hello, " + self._name

    def _private_2(self):
        return "Hi, " + self._name

    def greeting(self):
        if len(self._name) > 1:
            return _private_1(self._name)
        else:
            return _private_2(self._name)

