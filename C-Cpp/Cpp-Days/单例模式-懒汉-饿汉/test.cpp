#include <iostream>
#include <thread>
#include "HungaryBoy.h"
#include "LazyBoy.h"
using namespace std;

int main()
{
    cout << "饿汉 : " << endl;
    HungaryBoy::getInstance().printAdd();
    HungaryBoy::getInstance().printAdd();

    cout << "懒汉 : " << endl;
    thread t1(lzFun);
    thread t2(lzFun);
    t1.join();
    t2.join();

    return 0;
}