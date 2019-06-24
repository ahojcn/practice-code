"""
复制文件
"""

# 1. 获取用户要复制的文件名
old_file_name = input("请输入要复制的文件名：")

# 2. 打开要复制的文件
old_file = open(old_file_name, "r")

# 3. 新建一个文件
pos = old_file_name.rfind(".")
new_file_name = old_file_name[0: pos] + "[backup]" + old_file_name[pos:]
new_file = open(new_file_name, "w")

# 4. 从旧文件中复制数据写入新文件中
"""注意：当文件特别大的时候不能直接read了，内存不够"""
# content = old_file.read()
while True:
    content = old_file.read(1024)
    if len(content) == 0:
        break
    new_file.write(content)

# 5. 关闭文件
old_file.close()
new_file.close()
