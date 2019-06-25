try:
    print(num)
    print(" 0 ".center(50, "."))
except NameError:
    print("NameError")
finally:
    print(" 1 ".center(50, "."))

print(" 2 ".center(50, "."))


try:
    open("xxx.txt")
    print(num)
except NameError:
    print("NameError")
except FileNotFoundError:
    print("FileNotFoundError")


#  捕获多个异常要用 元组
try:
    # print(1 / 0)
    # open("xxx.txt")
    # print(num)
    print(1)
except (NameError, FileNotFoundError) as e:
    print("know error")
    print(e)
except Exception as e:
    print("another error....")
    print(e)
else:
    print("no error.")
finally:
    print("finally..")