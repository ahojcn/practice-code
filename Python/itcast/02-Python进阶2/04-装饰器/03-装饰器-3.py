def makeBold(fn):
    def wrapped():
        return "<b>" + fn() + "</b>"
    return wrapped

def makeItalic(fn):
    def wrapped():
        return "<i>" + fn() + "</i>"
    return wrapped


@makeBold
@makeItalic
def test1():
    return "hello, world"


@makeBold
def test2():
    return "hi, ahojcn"

if __name__ == '__main__':
    print(test1())
    print(test2())
