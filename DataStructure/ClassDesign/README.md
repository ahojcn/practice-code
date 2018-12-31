# 2、8、10、16进制间的相互转换

# 使用方法

输入：

退出程序：`end`或`END`

二进制：`b`或`B`

八进制：`o`或`O`

十进制：`d`或`D`

十六进制：`h`或`H`

# 测试

## 测试用例

```c
01011010.01b
245o
f2dh
725.625d
1011001.1101011b
3571.402o
91a28.b71h
end
```

## 测试结果

```c
##########################################
input 'end' or 'END' to exit the program!
##########################################
input>
-----answer-----
bin : 1011010.10
oct : 132.2
dec : 90.52
hex : 5A.4
-----answer-----
input>
-----answer-----
bin : 10100101
oct : 245
dec : 165
hex : A5
-----answer-----
input>
-----answer-----
bin : 111100101101
oct : 7455
dec : 3885
hex : F2D
-----answer-----
input>
-----answer-----
bin : 1011010101.101
oct : 1325.5
dec : 725.526
hex : 2D5.A
-----answer-----
input>
-----answer-----
bin : 1011001.1101011
oct : 131.456
dec : 89.5739538
hex : 59.6D
-----answer-----
input>
-----answer-----
bin : 11101111001.10000001
oct : 3571.204
dec : 1913.52609305
hex : 779.18
-----answer-----
input>
-----answer-----
bin : 10010001101000101000.100011101101
oct : 2215050.1655
dec : 596520.526098780517
hex : 91A28.17B
-----answer-----
input>
Bye!

```

## 运行结果截图

![运行结果](https://wx3.sinaimg.cn/mw690/006wR0dcly1fypr5li42tj30zf0u0e2n.jpg)

# 程序介绍

+ main.c

  程序的主体逻辑

+ Conversion.h Conversion.c

  数制转换

+ Stack.h Stack.c

  辅助数制转换的栈

以字符串的方式获取输入，以字符串的形式输出。

将输出的字符串转换为十进制数，再由十进制数转换为其他进制的字符串。转换成字符串的过程用到栈。

## TODO

使用递归处理转换过程。

## 流程图

+ 主体流程图

![主体流程](https://wx3.sinaimg.cn/mw690/006wR0dcly1fypr5wm16wj31a40u0agd.jpg)