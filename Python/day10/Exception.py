"""
Python 中所有的异常类都继承自 BaseException
"""

try:
    print('try...')
    r = 10 / 2
    print('result :', r)
except ZeroDivisionError as e:
    print('except :', e)
except ValueError as e:
    print('except :', e)
else:
    print('no error.')
finally:
    print('finally...')
print('END')