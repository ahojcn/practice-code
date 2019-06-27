import sys

# py 模块的搜索路径
for i in sys.path:
    print(i)


# 添加一个搜索路径
sys.path.append("../path/to/home")


# 重新导入模块
# from imp import *
# reload(test)