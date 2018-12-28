三个区域：

Command Window 用于输入命令和得到输出结果

Workspace 记录Command中用到的变量

Command History 记录Command输入历史

# 一、基础命令

## 1. 基础运算

- 清空屏幕

  `clc`

- 注释

  `%`

- 加减乘除

  ```matlab
  1 + 2
  1 - 2
  1 * 2
  1 / 2
  ```

- 指数

  - 例如$5^2$

    `5^2`

- 对数

  - 例如：$\ln32$

    `log(32)`

  - $\lg32$

    `log10(32)`

  - $\log_232$

    `log2(32)`

  - $\log_87 = \frac{\log_e7}{\log_e8}$

    `log(7)/log(8)`

- 三角函数

  `sin(x)`

  `cos(x)`

  还有一些其他的三角函数，动手试一试。

- 变量

  `x = 10`

  `y = 20`

  `x + y`

  不可以这样`x + 1 = 2`，没办法直接来解方程。在Matlab中`=`是赋值符号，不是**等于**。这个类似于C语言。

  可以这样：`x = x + 1`

  输出变量的值：`fprintf('%g\n', x);`或者`disp(x);`

- 按方向键⬆️⬇️用来重复命令

  这个和Linux中一样。

+ $\sqrt3$

  `sqrt(3)`

## 2. 向量运算

- $\vec x = (1,2,3)$

  `x = [1,2,3]`或`x = [1 2 3]`

- $\vec x*2$

  这个是计算$\vec x*2$的值，但是$\vec x$的值并没有改变，只是计算了这个表达式的结果。

  `x = x * 2`，这样才会改变$\vec x$的值，这个和C语言一样～

- 当然也可以做向量和向量的基本运算（加减乘除）等。

- `sum(x)`

  这个命令是用来求和的，例如：

  ```matlab
  v = [1 2 3];
  disp(sum(v));	% 输出 6
  ```

## 3. 矩阵运算

+ 矩阵
  $$
  A = 
  \begin{Bmatrix}
  \mathbf{1} & \mathbf{2} & \mathbf{3} \\\
  \mathbf{4} & \mathbf{5} & \mathbf{6} 
  \end{Bmatrix}
  $$

  $$
  B = 
  \begin{Bmatrix}
  \mathbf{7} & \mathbf{8} & \mathbf{9} \\\
  \mathbf{10} & \mathbf{11} & \mathbf{12} 
  \end{Bmatrix}
  $$




  输入：`A = [1 2 3;4 5 6]`

  按上面的输入同样，矩阵B

  输入：`B = [7,8,9;10,11,12]`

  然后就可以做矩阵的运算咯，`A*B,A+B,A-B,A/B`等。

  注意这里矩阵运算需要遵循矩阵运算规则。

+ 另一种矩阵乘法

  在Matlab中输入`A*B`就是数学中的矩阵乘法

  还有一种是输入`A.*B`，这样就是矩阵每个位置($A_{i,j}*B_{i,j}$)对应相乘。

## 4. Script

+ New Script

  在脚本里写一堆命令。

  例如：计算$x+y$

  ```matlab
  x = 10;	% 加了;后，在command window里，就不会出现x=10的结果。
  y = 20;	% 也可以不加分号。
  x + y
  ```

  保存脚本扩展名为.m -> 然后在左面切换到刚才保存的文件夹 -> RUN

  写脚本可以实现输入互动，例如：

  ```matlab
  x = input('Please input x:');
  y = input('Please input y:');
  
  x + y
  ```

  然后RUN，输入x，y，就会输出结果。

  + 例子：摄氏温度转华氏温度

    ```matlab
    C = input('enter a temperature in Celesius:');
    F = (C * 1.8) + 32
    
    fprintf('Fahrenheit = %f\n', F);
    ```

# 二、语法

## 1. 选择

栗子1：

```matlab
num = input('enter a number:');

if num > 0
	fprintf('正数\n');
elseif num == 0
	fprintf('0\n');
else
	fprintf('负数\n');
end
```

栗子2：

```matlab
a = input('a = ');
b = input('b = ');

if a > b
	fprintf('%g\n', a);
else
	fprintf('%g\n', b);
end
```

栗子3：

```matlab
% 1.
a = input('a = ');
b = input('b = ');
c = input('c = ');

if a + b <= c
	fprintf('NO\n');
elseif a + c <= b
	fprintf('NO\n');
elseif b + c <= a
	fprintf('NO\n');
else
	fprintf('YES\n');
end


% 2.
if (a + b > c) && (b + c > a) && (a + c > b)
	fprintf('YES\n');
else
	fprintf('NO\n');
end
```

## 2. 循环

### 2.1 while

栗子1：

```matlab
t = 1;
while t <= 5
	disp(t);
	t = t + 1;
end
```

栗子2：

```matlab
a = input('a = ');
b = input('b = ');
r = mod(a, b);

while r ~= 0
	a = b;
	b = r;
	r = mod(a, b);
end

disp(b);
```

### 2.2 for

栗子1：

```matlab
% 输出 1 ～ 5
for i = 1 : 5
	disp(i);
end

% 输出 5 ～ -5
for i = 5 : -1 : -5	 % 这的-1表示步长，步长默认为 1，步长可以为小数。
	disp(i);
end
```

栗子2：

```matlab
s = 0;
for i = 1 : 100
	s = s + i;
end

disp(s);
```

栗子3：计算

$\frac{1}{1}+\frac{1}{2}+\frac{1}{3}+…+\frac{1}{100} = ?$

```matlab
s = 0;

for i = 1 : 100
	s = s + (1 / i);
end

disp(s);
```

栗子4：

$$\frac{1}{1}-\frac{1}{2}+\frac{1}{3}-…-\frac{1}{100} =?$$

```matlab
sum = 0;
flag = -1;

for i = 1 : 100
	sum = sum + (1 / i)*flag;
end
```

栗子5：for loop和向量

```matlab
v = [1 2 3 4 5 6 7 8 9 100];

for i = v
	disp(i);
end
```

# 三、Function

## 3.1**无**返回值

新建一个function。

栗子1：计算$1+2+3+...+100 = ?$

```matlab
function mysum1( )
	s = 0;
    for i = 1 : 100
        s = s + i;
    end
	disp(s);
end
```

运行：`mysum1()`

栗子2：计算$1+2+3+…+n = ?$

```matlab
function mysum2( n )
	s = 0;
    for i = 1 : n
        s = s + i;
    end
	disp(s);
end
```

运行：`mysum2(100)`

栗子3：计算$n+(n+1)+(n+2)+...+m = ?$

```matlab
function mysum3( n, m )
	s = 0;
    for i = n : m
        s = s + i;
    end
	disp(s);
end
```

运行：`mysum(4, 10)`

> 上面这个例子，在command window调用时，我们需要把他的结果保存在一个变量中，如：`s1 = mysum(4,10)`。就会出错，这个就是没有返回值。

## 3.2 带返回值function

```matlab
function ret = mysum3( n, m )
	s = 0;
    for i = n : m
        s = s + i;
    end
    ret = s;	% return
end
```

此时：`s1 = mysum(4, 10)`

这样就完成了一个具有返回值的function。

---

# EOF