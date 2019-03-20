/*
    饿汉模式
*/
#include <iostream>
using namespace std;

class HungaryBoy
{
  public:
    static HungaryBoy &getInstance() // 静态的成员函数，通过这个接口来获取创建的对象
    {
        return sm_instence;
    }

    // 测试用的函数，输出 sm_instence 的地址。
    void printAdd()
    {
        cout << &sm_instence << endl;
    }

  private:
    HungaryBoy()    // 构造函数私有，防止外部通过构造创建对象
    {
        cout << "HungaryBoy()" << endl;
    }

    // C++ 11 删除函数
    // 拷贝构造、重载赋值运算符设置为删除函数，防止通过拷贝创建其他对象
    HungaryBoy(HungaryBoy const &) = delete;
    HungaryBoy &operator=(HungaryBoy const &) = delete;

  private:
    static HungaryBoy sm_instence; // 静态的成员变量，程序一运行就创建
};

HungaryBoy HungaryBoy::sm_instence;