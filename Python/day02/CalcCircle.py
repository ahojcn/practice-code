"""
计算○的周长和面积
"""

import math

r = float(input("输入圆的半径: "))
area = math.pi * math.pow(r, 2)
perimeter = math.pi * 2 * r

print("面积：%.1f\n周长：%.1f\n" % (area, perimeter))