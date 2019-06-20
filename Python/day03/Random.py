"""
掷骰子决定做什么事
"""
import random

face = random.randint(1, 6)

if face == 1:
    print("唱歌")
elif face == 2:
    print("跳舞")
elif face == 3:
    print("写代码")
elif face == 4:
    print("看电影")
elif face == 5:
    print("吃大餐")
else:
    print("睡觉")