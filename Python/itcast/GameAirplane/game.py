import pygame
import time
from pygame.locals import *

# 飞机类 
class HeroPlane(object):
    def __init__(self, screen_temp):
        self.x = 210
        self.y = 700
        self.image = pygame.image.load("./feiji/hero1.png")
        self.screen = screen_temp
        # 存储发射出去子弹的引用
        self.bullet_list = []

    def display(self):
        # 显示飞机
        self.screen.blit(self.image, (self.x, self.y))
        # 显示飞机发射的子弹
        for b in self.bullet_list:
            b.display()
            b.move()
            # 判断子弹是否越界
            if b.judge():
                self.bullet_list.remove(b)

    def move_left(self):
        self.x -= 5

    def move_right(self):
        self.x += 5

    def fire(self):
        self.bullet_list.append(Bullet(self.screen, self.x, self.y))



# 子弹
class Bullet(object):
    def __init__(self, screen, x, y):
        self.x = x + 40
        self.y = y - 20
        self.screen = screen
        self.image = pygame.image.load("./feiji/bullet.png")
    
    def display(self):
        self.screen.blit(self.image, (self.x, self.y))

    def move(self):
        self.y -= 5

    def judge(self):
        if self.y < 0:
            return True
        else:
            return False



# 敌机
class EnemyPlane(object):
    def __init__(self, screen_temp):
        self.x = 0
        self.y = 0
        self.image = pygame.image.load("./feiji/enemy0.png")
        self.screen = screen_temp
        # 敌机移动方向
        self.direction = "right"

    def display(self):
        # 显示飞机
        self.screen.blit(self.image, (self.x, self.y))

    def move(self):
        if self.direction == "right":
            self.x += 5
        elif self.direction == "left":
            self.x -= 5
        
        if self.x > 430:
            self.direction = "left"
        elif self.x < 0:
            self.direction = "right"

    def fire(self):
        pass



def key_control(hero):
    # 获取事件
    for event in pygame.event.get():
        if event.type == QUIT:
            print("Bye.")
            # pygame.event.poll()
            exit()
        # 判断是否由键盘按下
        elif event.type == KEYDOWN:
            # 检测是否是 a 或者 左箭头
            if event.key == K_a or event.key == K_LEFT:
                print("left")
                hero.move_left()
            elif event.key == K_d or event.key == K_RIGHT:
                print("right")
                hero.move_right()
            elif event.key == K_w or event.key == K_UP:
                print("up")
                hero.y -= 5
            elif event.key == K_s or event.key == K_DOWN:
                print("down")
                hero.y += 5
            elif event.key == K_SPACE:
                print("space")
                hero.fire()



def main():
    screen = pygame.display.set_mode((480, 852), 0, 32)
    # 背景图片
    background = pygame.image.load("./feiji/background.png")

    hero = HeroPlane(screen)

    # 创建一个敌机
    enemy = EnemyPlane(screen)

    while True:
        screen.blit(background, (0, 0))

        hero.display()

        enemy.display()
        enemy.move()

        pygame.display.update()

        # 键盘控制
        key_control(hero)

        time.sleep(0.01)

        



if __name__ == "__main__":
    main()