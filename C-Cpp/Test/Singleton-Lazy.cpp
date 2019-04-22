#include <iostream>
#include <mutex> // 互斥锁
#include <thread>
using namespace std;

/*
    饿汉模式
*/
class Singleton
{
  public:
    static Singleton *getInstance()
    {
        if (nullptr == sm_instance)
        {
            sm_mutex.lock();
            if (nullptr == sm_instance)
            {
                sm_instance = new Singleton();
            }
            sm_mutex.unlock();
        }
        return sm_instance;
    }

    class SingletonGC
    {
      public:
        ~SingletonGC()
        {
            if (sm_instance)
            {
                delete sm_instance;
            }
        }
    };

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
    Singleton &operator=(Singleton const &) = delete;

  private:
    static Singleton *sm_instance;
    static mutex sm_mutex;
    static SingletonGC sm_gc;
};

Singleton *Singleton::sm_instance = nullptr;
mutex Singleton::sm_mutex;
Singleton::SingletonGC Singleton::sm_gc;

void fun()
{
    cout << Singleton::getInstance() << endl;
}

int main()
{
    thread t1(fun);
    thread t2(fun);
    t1.join();
    t2.join();

    return 0;
}