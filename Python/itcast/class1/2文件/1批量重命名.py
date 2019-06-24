import os

# 1. 获取重命名的文件夹名字
folder_name = input("请输入文件夹：")

# 2. 获取指定的文件夹中所有的名字
file_names = os.listdir(folder_name)

# 3. 跳转到指定目录
#os.chdir(folder_name)

# 4. 修改文件名
for name in file_names:
    print(name)
    old_file_name = folder_name + "/" + name
    new_file_name = folder_name + "/" + "ahojcn" + name
    os.rename(old_file_name, new_file_name)
    # os.rename(name, "ahojcn-" + name)