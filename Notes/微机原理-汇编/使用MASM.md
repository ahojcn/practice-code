# 编写汇编程序

汇编语言工具包：链接:https://pan.baidu.com/s/1biXtlVcb1HW9WoiliD6SbQ  密码:86zz

一下介绍的是使用MASM来翻译和链接汇编程序，还有一款`emu8086`的软件也挺好用。

## 1. 在32位机上（学校的机子上，win7_x86）

1. 将工具包中`MASM`文件夹复制到C盘下

   ![1](https://wx3.sinaimg.cn/mw690/006wR0dcly1fy4dcg8n15j31400u01l3.jpg)

2. 打开`cmd`，来到这个目录下

   ![2](https://wx1.sinaimg.cn/mw690/006wR0dcly1fy4dcb5af0j31400u04qq.jpg)

3. 创建一个`1.asm`文件，使用`edit`工具进行编辑（edit就是个编辑器，还是`notepad`好用）

   ![3](https://wx4.sinaimg.cn/mw690/006wR0dcly1fy4dcfblo2j31400u0b2a.jpg)

4. 使用`edit`编辑代码，并保存

   ![4](https://wx2.sinaimg.cn/mw690/006wR0dcly1fy4dcfkwj5j31400u04qs.jpg)

5. `masm 1;`进行汇编，会生成一个`1.obj`文件

   ![5](https://wx4.sinaimg.cn/mw690/006wR0dcly1fy4dccm188j31400u07wi.jpg)

6. `link 1;`链接文件

   ![6](https://wx4.sinaimg.cn/mw690/006wR0dcly1fy4dcd87f9j31400u01l0.jpg)

7. `1.exe`或者`1;`运行程序

   ![7.1](https://wx3.sinaimg.cn/mw690/006wR0dcly1fy4dcf7bvrj31400u0b2b.jpg)

   ![7.2](https://wx1.sinaimg.cn/mw690/006wR0dcly1fy4dchnkh8j31400u01l0.jpg)

## 2. 在64位Windows机器上

要使用一个叫`DOSBox`的工具来模拟32位环境。

1. 安装`DOSBox`一路next

2. 运行`DOSbox`

3. 绑定`MASM`的路径

   `mount C C:\MASM`

   ![3](https://wx1.sinaimg.cn/mw690/006wR0dcly1fy4dnaccokj30a306pdgx.jpg)

4. 切换到挂在的C盘

   ![4](https://wx2.sinaimg.cn/mw690/006wR0dcly1fy4dne2bbmj309i06cwff.jpg)

5. 然后就可以和上面一样咯

   ![5.1](https://wx3.sinaimg.cn/mw690/006wR0dcly1fy4dnhkdj8j309h06d0tj.jpg)

   ![5.2](https://wx1.sinaimg.cn/mw690/006wR0dcly1fy4dnkr1jyj30a306pwff.jpg)

   ![5.3](https://wx1.sinaimg.cn/mw690/006wR0dcly1fy4dnnynksj30a706raau.jpg)

## 3. Mac上写汇编程序

`DOSBox`也有Mac版本的。

[MAC上编写汇编程序](https://blog.csdn.net/zach_z/article/details/78171329)

---