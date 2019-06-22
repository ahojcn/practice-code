"""
读写文进制文件

复制图片
"""
def main():
    try:
        with open('image.png', 'rb') as f1:
            data = f1.read()
            print(type(data)) # <class 'bytes'>
        with open('image_cp.jpg', 'wb') as f2:
            f2.write(data)
    except FileNotFoundError as e:
        print(e)
    except IOError as e:
        print(e)
    print("END" + '.')

if __name__ == '__main__':
    main()