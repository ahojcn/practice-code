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