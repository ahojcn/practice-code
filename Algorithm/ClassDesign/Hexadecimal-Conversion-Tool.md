# Hexadecimal-Conversion-Tool

数据结构课程设计——进制转换工具，[源码](https://github.com/ahojcn/Practice/tree/master/DataStructure/ClassDesign)

### TODO

:spiral_notepad: 递归进制转换

:spiral_notepad: 任意进制转换

### OK

:heavy_check_mark: 程序使用帮助功能

:heavy_check_mark: 使用栈辅助转换

---

### 使用方法

以下输入对大小写均支持。

退出程序：`END`

获取使用帮助：`HELP`

二进制=>其他进制：`101.101B`

八进制=>其他进制：`777.777O`

十进制=>其他进制：`999.999D`或者`999.999`

十六进制=>其他进制：`fff.fffH`

---

### 使用截图

![001-使用截图](/Users/hanoi_ahoj/Desktop/Hexadecimal-Conversion-Tool-pic/001.png)

### 测试

测试输入用例`test.in`

```shell
01011010.01b
245o
f2dh
725.625d
1011001.1101011b
3571.402o
91a28.b71h
end
```

测试输出结果`test.out`

```shell
	#################  Menu  #################
	input 'end' or 'END' to exit the program!
	-----------------------------------------
	input 'help' or 'HELP' to get user guide!
	#################  Menu  #################
input>		-----answer-----
		bin : 1011010.10
		oct : 132.2
		dec : 90.52
		hex : 5A.4
		-----answer-----
input>		-----answer-----
		bin : 10100101
		oct : 245
		dec : 165
		hex : A5
		-----answer-----
input>		-----answer-----
		bin : 111100101101
		oct : 7455
		dec : 3885
		hex : F2D
		-----answer-----
input>		-----answer-----
		bin : 1011010101.101
		oct : 1325.5
		dec : 725.526
		hex : 2D5.A
		-----answer-----
input>		-----answer-----
		bin : 1011001.1101011
		oct : 131.456
		dec : 89.5739538
		hex : 59.6D
		-----answer-----
input>		-----answer-----
		bin : 11101111001.10000001
		oct : 3571.204
		dec : 1913.52609305
		hex : 779.18
		-----answer-----
input>		-----answer-----
		bin : 10010001101000101000.100011101101
		oct : 2215050.1655
		dec : 596520.526098780517
		hex : 91A28.17B
		-----answer-----
input>Bye!
```

