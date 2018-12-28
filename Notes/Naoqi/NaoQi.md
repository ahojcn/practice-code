# NaoQi

## choregraphe

### app文件路径

在Naoqi操作系统中，使用Choregraphe开发的App，都是以源代码的形式存储在Naoqi中。
位于`/home/nao/.local/share/PackageManager/apps/`下

### 指令盒

指令盒运行过程：

1. 指令盒实例化
2. 将指令盒注册为模块，这样它就可以通过链接，从其它指令盒里调用。
3. 指令盒初始化

前两步是自动的，不受控制，默认生成的类的方法：

initialize（初始化）  、onLoad、onUnload、onStart、onStop

这些方法的含义：

initialize()：执行行为时，自动执行初始化参数

onLaod():当加载指令盒流程图时，会调用这个方法。在当前行为的所有指令盒的__init__方法之后，有必要调用这个方法。加载流程图时，在任何输入/输出点被激活前，这一方法会被调用至当前一级的每个指令盒。

onInput_onStart（）：当onStart被激活时，会调用该方法。在onInput_onStart()中调用self.onStopped()，会激活onStoped()输出点。

onInput_onStop（）：当onStop被激活时，会调用该方法。

可以定义自己的函数并在合适的位置进行调用，例如上面的mufun(self)函数。

```python
class MyClass(GeneratedClass):
    def __init__(self):
        GeneratedClass.__init__(self)
 
    def onLoad(self):
        #~ puts code for box initialization here
        pass
 
    def onUnload(self):
        #~ puts code for box cleanup here
        pass
 
    def onInput_onStart(self):
        self.myfun()
        self.onStopped() #~ activate output of the box
        pass
 
    def onInput_onStop(self):
        self.onUnload() #~ it is recommanded to call onUnload of this box in a onStop method, as the code written in onUnload is used to stop the box as well
        pass
    def myfun()
        self.logger.info("++++++++++++++++++++++++")

```



