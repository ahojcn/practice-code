#include <iostream>
#include <string>
using namespace std;

class Date {
public:
    Date(int y =1900, int m = 1, int d = 1) {
        cout << "Date::Date(int, int, int)" << endl;
        _year = y;
        _month = m;
        _day = d;
    }

    void toString() {
        cout << _year << "-" << _month << "-" << _day;
    }

private:
    int _year;
    int _month;
    int _day;
};

int main() {
    Date d1(2019, 9, 7);  // 构造函数并不是开空间创建对象，而是初始化对象。该对象的空间在函数运行时的栈空间中
    d1.toString();

    return 0;
}