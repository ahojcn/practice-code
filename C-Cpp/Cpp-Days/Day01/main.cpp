/*
 * 命名空间
 */

// using namespace my;  展开了 my 命名空间中所有的东西
// using my::a;  只展开了 a

#if 0
#include <iostream>

int a = 0;

namespace A {
    namespace A1 {
        int aa1 = 111;
    }

    namespace A2 {
        void func1() {
            printf("in func1\n");
        }
    }
}

namespace B {
    int b1 = 1;
}

namespace B {
    int b2 = 2;
}

int main() {

    int a = 1;
    printf("%d\n", ::a);
    printf("%d\n", a);

    printf("%d\n", A::A1::aa1);
    A::A2::func1();

    printf("%d\n", B::b1);
    printf("%d\n", B::b2);
    return 0;
}
#endif

/*
 * 输入输出
 */

#if 0

#include <iostream>

int main() {
    std::cout << "123\n";

    int a = 0;
    std::cin >> a;
    std::cout << a << std::endl;
    return 0;
}

#endif


/*
 * 缺省参数
 */

#if 0

#include <iostream>

using namespace std;

// 全缺省
void func(int a = 0, int b = 1, int c = 2) {
    cout << a << b << c << endl;
}

// 半缺省，只能是从右往左缺省
void func1(int x, int y, int z = 7) {
    cout << x << y << z << endl;
}

int main() {

    func();
    func(1);
    func(1,2);
    func(1,2,3);

    cout << "---" << endl;

    func1(1,2);
    func1(1,2,3);

    return 0;
}

#endif


/*
 * 函数重载
 * 参数个数/类型/顺序 有所不同
 */
#if 0

#include <iostream>

using namespace std;

int Add(int a, int b) {
    return a + b;
}

int main() {

    Add(1, 2);
    return 0;
}

#endif


#if 1

#include <iostream>

inline int add(int x, int y) {
    return x + y;
}

int main() {
    int ret = 0;

    size_t begin = clock();

    ret = add(1, 2);
    return 0;
}




//struct A {
//    int data[10000];
//};
//
//A a;
//
//A func1() {
//    return a;
//}
//
//A& func2() {
//    return a;
//}
//
//int main() {
//    size_t begin = clock();
//    for (size_t i = 0; i < 100000; ++i)
//        func1();
//    size_t end = clock();
//    std::cout << "A func1() : " << end - begin << std::endl;
//
//    begin = clock();
//    for (size_t i = 0; i < 100000; ++i)
//        func2();
//    end = clock();
//    std::cout << "A& func2() : " << end - begin << std::endl;
//
//    return 0;
//}



//void func1(A a) {
//}
//
//void func2(A &a) {
//}
//
//int main() {
//    A a;
//
//    size_t begin = clock();
//    for (size_t i = 0; i < 10000; ++i)
//        func1(a);
//    size_t end = clock();
//    std::cout << "func1(A a) : " << end - begin << std::endl;
//
//    begin = clock();
//    for (size_t i = 0; i < 10000; ++i)
//        func2(a);
//    end = clock();
//    std::cout << "func2(A a) : " << end - begin << std::endl;
//
//    return 0;
//}

//int& Add(int a, int b)
//{
//    int c = a + b;
//    return c;
//}
//int main() {
//    int& ret = Add(1, 2);
//    Add(3, 4);
//    std::cout << "Add(1, 2) is :"<< ret <<std::endl;
//    return 0;
//}

//int main() {
//    const int a = 10;
////    int &ar = a;
//    const int &ar = a;
//
//    int b = 20;
//    int &rb1 = b;
//    const int &rb2 = b;
//
//    int c = 30;
////    double &rc1 = c;
//    const double &rc2 = c;
//
//    return 0;
//}

//extern "C" int Add(int x, int y) {
//    return x + y;
//}
//
//int main() {
//    std::cout << Add(1, 2) << std::endl;
//    return 0;
//}

//void func(int i=1, double d=1.0);
//
//int main() {
//    func();
//
//    return 0;
//}
//
//void func(int i, double d) {
//    std::cout << i << std::endl << d << std::endl;
//}

//#include <iostream>
//
//int a = 10;
//
//int main() {
//    int a = 20;
//
//    std::cout << ::a << std::endl;
//
//    return 0;
//}

//namespace A {
//    int aa = 1;
//    int ab = 2;
//}
//
//namespace A {
////    int ab = 3;  // 提示已存在变量 ab
//    int ac = 4;
//}
//
//int main() {
//    std::cout << A::aa << " " << A::ab << " " << A::ac << std::endl;
//    return 0;
//}

#endif