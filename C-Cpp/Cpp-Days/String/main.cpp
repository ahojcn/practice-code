#include <iostream>
#include <string>
#include <vector>
#include "String.h"

using namespace std;

/*
 * String 类练习代码
 */

void testString1()
{
    string s1;
    string s2("hello");
    string s3(10, 'a');
    string s4(s2 + " world");
    string s5(s3, 5);

    cout << "s1 : " << s1 << endl;
    cout << "s2 : " << s2 << endl;
    cout << "s3 : " << s3 << endl;
    cout << "s4 : " << s4 << endl;
    cout << "s5 : " << s5 << endl;
}

void testString2()
{
    string s("hello world");
    cout << s << endl;
    cout << s.length() << endl;
    cout << s.size() << endl;
    cout << s.capacity() << endl;

    cout << "-----" << endl;

    s.clear();
    cout << s.length() << endl;
    cout << s.size() << endl;
    cout << s.capacity() << endl;

    cout << "-----" << endl;

    s += "hello world";
    s.resize(8, '1');
    cout << s << endl;
    cout << s.size() << endl;
    cout << s.capacity() << endl;

    cout << "-----" << endl;

    s.clear();
    s += "aaaaaaaaa";
    s.reserve(3);
    cout << s << endl;
    cout << s.size() << endl;
    cout << s.capacity() << endl;
    s.reserve(100);
    cout << s << endl;
    cout << s.size() << endl;
    cout << s.capacity() << endl;
}

void testString3()
{
    string s = "hello world";
    for (size_t i = 0; i < s.size(); i++)
    {
        cout << s[i];
    }
    cout << endl << "-----" << endl;
    for (auto &e : s)
    {
        cout << e;
    }
    cout << endl << "-----" << endl;
    for (char i : s)
    {
        cout << i;
    }
    cout << endl << "-----" << endl;
}

void testString4()
{
    string s = "hello world";
    cout << s.find(' ') << endl;
    cout << s.rfind(' ') << endl;
    cout << s.substr(s.find(' ') + 1, 5) << endl;
}

// 获取file的后缀
void testString5()
{
    string s = "main.cpp";
    size_t pos = s.rfind('.');
//    cout << pos << endl;
    cout << s.substr(pos, s.size()) << endl;
}

// 取出url中的域名
void testString6()
{
    string url = "http://ahoj.cc/wiki/index.html";
    cout << url << endl;
    size_t begin = url.find("://");
    if (begin == string::npos)
    {
        cout << "illegal url" << endl;
        return;
    }
    begin += 3;
    size_t end = url.find('/', begin);
    cout << url.substr(begin, end - begin) << endl;

    // 删除url的协议前缀
    url.erase(0, begin);
    cout << url << endl;
}

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        if (s.empty())
            return;
        size_t begin = 0, end = s.size() - 1;
        while (begin < end)
        {
            swap(s[begin++], s[end--]);
        }
    }
};

int main()
{
    // testString6();
    /*vector<char> v;
    v.push_back('h');
    v.push_back('e');
    v.push_back('l');
    v.push_back('l');
    v.push_back('o');

    Solution().reverseString(v);

    for (vector<char>::iterator vc_it = v.begin(); vc_it != v.end(); ++vc_it)
    {
        cout << *vc_it;
    }
    cout << endl;
    for (char &e : v)
    {
        cout << e;
    }
    cout << endl;*/

    String s1;
    String s2("hello world");
    cout << s1.c_str() << endl;
    cout << s2.c_str() << endl;

    String s3(s2);
    cout << s3.c_str() << endl;

    s1 = s3;
    cout << s1.c_str() << endl;

    return 0;
}