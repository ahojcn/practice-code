"""
模块之间循环导入
"""
from a import a

def b():
    print("b")

def c():
    a()

c()