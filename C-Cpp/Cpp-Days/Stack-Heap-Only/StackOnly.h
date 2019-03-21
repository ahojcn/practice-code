/*
 * 只在栈上创建对象的类
 */
class StackOnly
{
  public:
    static StackOnly getStackOnlyObj()
    {
        return StackOnly(); // 这里返回的一份拷贝
    }

  private:
    StackOnly() {}

    // 拷贝构造 和 重载的= 不用 私有/删除函数，因为通过拷贝出来的对象就是在栈上
};

/*
    实现方式 2 : 
        屏蔽 new 操作符，不允许 new 对象（即屏蔽掉operator new和定 位new表达式）
        屏蔽了 operator new，实际也将定位new屏蔽掉。
    缺陷 :  
        1. 还可以在全局定义一个栈上的对象
        2. 在类内部可以定义 static 的对象
*/
#include <iostream> // size_t
class StackOnly2
{
  public:
    StackOnly2() {}

    static StackOnly2 obj2; // 缺陷 2.

  private:
    void *operator new(size_t size) = delete;   // 重载 new 为删除函数
    void operator delete(void *p) = delete;     // 不让删除自己，因为对象自己删除自己可能会出现一些意想不到的情况
};

StackOnly2 obj1;    // 缺陷 1.

