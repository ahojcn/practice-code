#include <iostream>
using namespace std;

// 饿汉模式
class Singleton
{
  public:
    static Singleton &m_Instance()
    {
        return m_instance;
    }
    void print()
    {
        cout << "test print" << endl;
    }

  private:
    Singleton()
    {
        cout << "Singleton()" << endl;
    }
    ~Singleton()
    {
        cout << "~Singleton()" << endl;
    }
    Singleton(Singleton const &) = delete;

  private:
    static Singleton m_instance;
};

Singleton Singleton::m_instance;

int main()
{
    Singleton::m_Instance().print();
    cout << "1 : " << &(Singleton::m_Instance()) << endl;
    cout << "2 : " << &(Singleton::m_Instance()) << endl;
    return 0;
}