#include <iostream>
#include <string>
using namespace std;

// class Student
// {
// public:
//   int age;

//   void showInfo();
// };

// void Student::showInfo()
// {
//   cout << this->age << endl;
// }

// int main()
// {
//   Student ahoj;
//   ahoj.age = 19;
//   ahoj.showInfo();

//   cout << "-----" << endl;

//   cout << "sizeof(Student) : " << sizeof(Student) << endl;
//   cout << "sizeof(ahoj) : " << sizeof(ahoj) << endl;
//   return 0;
// }

// class A
// {
//   public:
//     void PrintA()
//     {
//         cout << _a << endl;
//     }

//   private:
//     char _a;
// };

class A1
{
  public:
    void f1() {}

  private:
    int _a;

    class A3
    {
    };
};
// 类中仅有成员函数
class A2
{
  public:
    void f2() {}
};
// 类中什么都没有---空类
class A3
{
};

int main()
{
    cout << "sizeof(A1) : " << sizeof(A1) << endl;
    cout << "sizeof(A2) : " << sizeof(A2) << endl;
    cout << "sizeof(A3) : " << sizeof(A3) << endl;
    return 0;
}