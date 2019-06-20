"""
打印杨辉三角
"""
def main():
    num = int(input("输入行数："))
    yh = [[]] * num
    for i in range(len(yh)):
        yh[i] = [None] * (i + 1)
        for j in range(len(yh[i])):
            if j == 0 or i == j:
                yh[i][j] = 1
            else:
                yh[i][j] = yh[i-1][j] + yh[i-1][j-1]
            print(yh[i][j], end='\t')
        print()

if __name__ == '__main__':
    main()