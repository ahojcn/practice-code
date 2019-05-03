#include <iostream>
#include <string>
#include <stack>

std::stack<char> sk; // 用来存放括号
std::stack<char> sc; // 用来存放除括号外的字符
std::string str;
bool flag = true;

bool iscal(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int main()
{
    std::cin >> str;
    std::string::iterator it = str.begin();

    while (it != str.end())
    {
        if (*it == '(')
        {
            if (isdigit(*(it - 1)))
            {
                flag = false;
                break;
            }
            else
            {
                sk.push(*it);
            }
        }
        else if (*it == ')')
        {
            if (sk.empty())
            {
                flag = false;
                break;
            }
            else
            {
                if (iscal(*(it - 1)))
                {
                    flag = false;
                    break;
                }
                else
                {
                    sk.pop();
                }
            }
        }
        else if (isdigit(*it))
        {
            if (*(it - 1) == ')')
            {
                flag = false;
                break;
            }
            else
            {
                sc.push(*it);
            }
        }
        else // is cal, ignore
        { ; }
        ++it;
    }   // while()

    if (!sk.empty())
    {
        flag = false;
    }

    if (flag)
    { std::cout << "true\n"; }
    else
    { std::cout << "false\n"; }

    return 0;
}