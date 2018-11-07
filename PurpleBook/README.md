# 算法竞赛入门(紫书)

> 这里是我读紫书过程中的笔记。

## 第一章

### Note01

1. 输入前不要打印提示信息，输入完毕后立即终止程序，不要等待用户按键。

2. 算法竞赛中不要使用头文件conio.h，包括getch()、clrscr()等函数。

3. 每行输出均以回车符结束，包括最后一行，除非特别说明，每行行首不应有空格，但行末通常可以有多余空格。输出的每两个数字或者字符串之间用单个空格隔开。

### Note02

1. 对程序运行时间进行计算

   ```c
   #include <time.h>
   printf("Time used = %.2fs\n", (double)clock()/CLOCKS_PER_SEC);
   ```

2. 为了避免输入对程序计算时间的影响，可以利用“管道”。

   Windows：`echo 20 | test.exe`（将20作为输入，test.exe是程序名）

   Linux：`echo 20 | ./a.out`（将20作为输入）

3. 使用文件，最简单的方法就是使用输入输出重定向。

   ```c
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   ```

   上面的代码使得所有键盘输入，屏幕输出的函数都将作用于文件。

4. 