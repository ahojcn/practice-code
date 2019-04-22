#include <iostream>
using namespace std;

/*
    只能在堆上创建对象的类
*/
class HeapOnly
{
  public:
    static HeapOnly *getHeapOnlyObj()
    {
        return new HeapOnly;
    }

  private:
    HeapOnly() {}
    // C++98 拷贝构造私有，不允许拷贝对象
    // HeapOnly(HeapOnly const &);
    // C++11 删除函数
    HeapOnly(HeapOnly const &) = delete;
};

int main()
{
    cout << sizeof(HeapOnly) << endl;
    return 0;
}