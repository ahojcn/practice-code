import os
from multiprocessing import Pool, Manager


def copyFileTask(oldFolderName, newFolderName, name, queue):
    """完成拷贝文件的功能"""
    fr = open(oldFolderName + '/' + name)
    fw = open(newFolderName + '/' + name, "w")

    content = fr.read()
    fw.write(content)

    fr.close()
    fw.close()

    queue.put(name)


def main():
    # 0. 输入要拷贝的文件夹名
    oldFolderName = input("请输入文件夹名称 :")

    # 1. 创建一个文件夹
    newFolderName = oldFolderName + '-复件'
    os.mkdir(newFolderName)

    # 2. 获取 old 文件夹中的所有的文件名字
    fileNames = os.listdir(oldFolderName)
    print(fileNames)

    # 3. 使用多进程的方式 copy 原文件夹中的所有文件
    pool = Pool(5)
    queue = Manager().Queue()
    for name in fileNames:
        pool.apply_async(copyFileTask, args=(oldFolderName, newFolderName, name, queue))

    num = 0
    allNum = len(fileNames)
    while num < allNum:
        queue.get()
        num += 1
        copyRate = num / allNum
        print("拷贝进度 %.2f %%" % (copyRate * 100), end='')

    print("\n已经完成")

    pool.close()
    pool.join()


if __name__ == '__main__':
    main()
