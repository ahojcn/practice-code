"""
模块之间循环导入
"""
from b import b

def a():
    print("a")
    b()

a()