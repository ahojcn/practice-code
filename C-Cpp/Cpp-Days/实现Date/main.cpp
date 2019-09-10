#include <iostream>
#include <thread>

using namespace std;

#include "Date.h"

/*
 * 格式化代码：alt + cmd + l
 *
 *
 */

// TODO: here

using namespace std;

int i = 0;

void fun()
{
    while (i < 100)
    {
        cout << "( " << i++ << " )" << endl;
    }
}

int main()
{
//    thread t1(fun);
//    thread t2(fun);
//
//    t1.join();
//    t2.join();

    Date d1(2018, 2, 28);
    Date d2(2018, 7, 9);
    Date d3;
    cout << (d1 > d2) << endl;

    cout << d1 << endl << d2 << endl << d3 << endl;

    cin >> d3;

    cout << d3 << endl;

    cout << "++d3 : " << (++d3) << endl;

    return 0;
}