import os

# 重命名
os.rename("text.txt", "test.txt")

# 删除
os.remove("test[backup].txt")

# 创建文件夹
os.mkdir("testdir")

# 删除文件夹
os.rmdir("testdir")

# 获取当前路径
print(os.getcwd())

# 改变默认目录
os.chdir("/usr/")
print(os.getcwd())

# 获取目录
print(os.listdir("./"))