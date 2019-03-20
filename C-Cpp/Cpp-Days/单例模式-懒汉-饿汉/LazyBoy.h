/*
    懒汉模式
*/
#include <iostream>
#include <mutex> // 互斥锁的头文件
using namespace std;

class LazyBoy
{
  public:
    static LazyBoy *getInstance()
    {
        // double-check 保证线程安全 和 效率
        if (nullptr == sm_instence) // 如果是第一次调用，则加锁解锁，不是的话直接返回
        {
            sm_mutex.lock();
            if (nullptr == sm_instence) // 如果对象没有创建(程序首次调用)，new一个
            {
                sm_instence = new LazyBoy();
            }
            sm_mutex.unlock();
        }
        return sm_instence;
    }

    // 垃圾回收器，内部类，是外部类的友元，可以访问外部类的成员
    class LazyBoyGC
    {
      public:
        ~LazyBoyGC()
        {
            if (nullptr != sm_instence) // 如果对象被创建则 delete，否则不干啥
            {
                delete sm_instence;
            }
        }
    };

  private:
    LazyBoy() // 私有的构造，防止通过这个创建对象
    {
        cout << "LazyBoy()" << endl;
    }
    ~LazyBoy()
    {
        cout << "~LazyBoy()" << endl;
    }

    // C++11 删除函数，防止通过拷贝创建对象
    LazyBoy(LazyBoy const &) = delete;
    LazyBoy &operator=(LazyBoy const &) = delete;

  private:
    static LazyBoy *sm_instence;    // 这里定义 指针类型，就和结构体中不能定义一个自己结构体变量。
    static mutex sm_mutex; // 互斥锁
    static LazyBoyGC sm_gc; // 静态的垃圾回收器遍历，生命周期结束时帮助清理垃圾
};

LazyBoy *LazyBoy::sm_instence = nullptr;    // 初始化指向空
mutex LazyBoy::sm_mutex;    // 互斥锁
LazyBoy::LazyBoyGC LazyBoy::sm_gc;  // 初始化垃圾回收器变量

void lzFun()
{
    cout << LazyBoy::getInstance() << endl;
}