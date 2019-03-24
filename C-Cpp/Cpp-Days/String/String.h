//
// Created by hanoi_ahoj on 2019-03-23.
//

#ifndef STRING_STRING_H
#define STRING_STRING_H

#include <iostream>
#include <cstring>
#include <string>
#include <cassert>

class String
{
public:
    String(char *str = "") : m_str(new char[strlen(str) + 1])
    {
        strcpy(m_str, str);
    }

    // 传统写法
    // 深拷贝：拷贝成员变量 + 资源
    /*String(String const &s) : m_str(new char[strlen(s.m_str) + 1])
    {
        strcpy(m_str, s.m_str);
    }*/

    // 现代写法
    String(String const &s) : m_str(nullptr)    // 注意这里的把 m_str 赋为空，因为当 temp 和 this的东西交换了后，temp除了作用域会成一个null被析构
    {
        String temp(s.m_str);
        std::swap(m_str, temp.m_str);
    }

    // 深拷贝，传统写法
    /*String &operator=(String const &s)
    {
        if (this != &s)
        {
            delete[] m_str;
            m_str = new char[strlen(s.m_str) + 1];
            strcpy(m_str, s.m_str);
        }
        return *this;
    }*/

    // 现代写法 1.
    /*String &operator=(String const &s)
    {
        if (this != &s)
        {
            String temp(s.m_str);
            std::swap(m_str, temp.m_str);
        }
        return *this;
    }*/


    // 现代写法 2.
    String &operator=(String s)
    {
        std::swap(m_str, s.m_str);
        return *this;
    }

    ~String()
    {
        if (m_str)
        {
            delete[] m_str;
            m_str = nullptr;
        }
    }

    char *c_str()
    {
        return m_str;
    }

private:
    char *m_str;
};


#endif //STRING_STRING_H
