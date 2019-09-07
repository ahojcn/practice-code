#include <iostream>
#include <string>

using namespace std;


#if 0

int main() {
    const int a = 10;  // 常量，具有宏常量的也行：在编译期间替换
    int *pa = (int *) &a;

    *pa = 100;

    cout << a << endl;  // cout << 10 << endl; 但是 a 里面存的是 100
    cout << *pa << endl;

    return 0;
}

#endif

#if 0

int main() {
//    auto a = 10;
//    cout << typeid(a).name() << endl;
//
//    auto b = 1.1;
//    cout << typeid(b).name() << endl;
//
//    auto s = 'a';
//    cout << typeid(s).name() << endl;


//    int a = 10;
//    auto pa1 = &a;
//    auto *pa2 = &a;
//
//    cout << typeid(pa1).name() << endl;
//    cout << typeid(pa2).name() << endl;  // Pi -> Point int
//
//    auto &ra = a;
//    ra = 100;
//    cout << a << endl;


//    auto a = 1, b = 2;
//    auto x = 1, y = 1.1;  // error


    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    for (auto &e: arr) {
        e *= 2;
        cout << e << " ";
    }
    cout << endl;

    return 0;
}

#endif

#if 0

void func(int *) {
    cout << "func int *" << endl;
}

void func(int) {
    cout << "func int" << endl;
}

int main() {
    int a = 10;
    int *pa = &a;
    int *pb = NULL;  // NULL

    func(pb);  // int *
    // func(NULL);
    func(nullptr);
}

#endif

// 类和对象
#if 0

struct Student {
    char _name[20];
    char _gender[3];
    int _age;

    void initStudent(char *name, char *gender, int age) {
        strcpy(_name, name);
        strcpy(_gender, gender);
        _age = age;
    }

    void printStudent() {
        cout << _name << " " << _gender << " " << _age << endl;
    }
};

int main() {
    Student s1, s2;
    s1.initStudent((char *)"ahoj", (char *)"男", 18);
    s1.printStudent();

    s1._age = 22;

    s2.initStudent((char *)"tim", (char *)"男", 20);
    s2.printStudent();

    return 0;
}

#endif

#if 0

class Student {
private:
    string _name;
    string _gender;

public:
    Student() {
        _name = "未知";
        _gender = "未知";
    }
};

int main() {

    return 0;
}

#endif


#if 0

class A {
public:
    void func() {}

public:
    int _a;
};

class B {
public:
    void func() {}
};

class C {
};

int main() {
    cout << sizeof(A) << sizeof(B) << sizeof(C) << endl;

    C c, c2;
    C const *pc = &c;
    pc = &c2;

    return 0;
}

#endif

#if 0

class A {
public:
    void func1();

    void func2(...);
};

int main() {
    A a;
    a.func1();
    a.func2(&a);

    return 0;
}

#endif


#if 1



#endif

