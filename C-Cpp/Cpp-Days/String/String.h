//
// Created by hanoi_ahoj on 2019-03-23.
//

#ifndef STRING_STRING_H
#define STRING_STRING_H

#include <iostream>
#include <cassert>

namespace ahoj
{
    class string
    {
    public:
        string(const char *str = "")
        {
            assert(str != nullptr);

            _size = strlen(str);
            _capacity = _size + 1;
            _str = new char[_capacity + 1]; // '\0'
            strcpy(_str, str);
        }

        string(const string &s) : _str(nullptr)
        {
            string t(s._str);
            std::swap(_str, t._str);
        }

        string &operator=(string s)
        {
            std::swap(_str, s._str);
            return *this;
        }

        char *c_str()
        {
            return _str;
        }

    private:
        size_t _size;
        size_t _capacity;
        char *_str;
    };
}


#endif //STRING_STRING_H
