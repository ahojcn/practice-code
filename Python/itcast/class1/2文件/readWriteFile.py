"""
读写文件
"""
# open 默认以读的方式打开，所以可以省略 "r"
f = open("./openCloseFile.py", "r")
# print(f.read())
# if f.read() == '':
    # print("读取完毕")
print(f.readlines())
f.close()

fw = open("./test.txt", "w")
fw.write("520\n")
fw.close()

