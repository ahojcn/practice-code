#include <iostream>
// #include <string>
using namespace std;

char *strstr(char *str, char *s)
{
    char *p = s;
    char *tmp = str;
    while (*str)
    {
        tmp = str;
        while (*str++ == *p++)
        {
            if (*p == '\0')
            {
                return tmp;
            }
        }
        p = s;
    }

    return nullptr;
}

// string fun()
// {
//     return string("hello world");
// }

int main()
{
    // cout <<  << endl;
    printf("%p\n", strstr("abc", "abd"));
    // cout << fun() << endl;
    return 0;
}

// String operator+(const String &s1, const String &s2)
// {
//     return String(Append(s1._str, s2._str));
//     // 这里发生了两次值拷贝，效率低。
//     // += 返回的是引用，效率比较高
// }

// String operator+(const String &s1, const char *s2)
// {
//     return String(Append(s1._str, s2));
// }

// String operator+(const char *s1, const char *s2)
// {
//     return String(Append(s1, s2));
// }