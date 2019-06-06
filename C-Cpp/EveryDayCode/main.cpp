#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        int bigEn = 0, smEn = 0, hasDig = 0, hasSign = 0;
        int score = 0;

        if (s.size() <= 4)
        {
            score += 5;
        }
        else if (s.size() >= 5 && s.size() <= 7)
        {
            score += 10;
        }
        else
        {
            score += 25;
        }

        for (char i : s)
        {
            if (i >= '0' && i <= '9')
            {
                hasDig += 1;
            }
            else if (i >= 'a' && i <= 'z')
            {
                smEn += 1;
            }
            else if (i >= 'A' && i <= 'Z')
            {
                bigEn += 1;
            }
            else // 符号
            {
                hasSign += 1;
            }
        }

        if (bigEn == 0 || smEn == 0)
        {
            score += 10;
        }
        else
        {
            score += 20;
        }

        if (hasDig == 1)
        {
            score += 10;
        }
        else if (hasDig > 1)
        {
            score += 20;
        }

        if (hasSign == 0)
        {}
        else if (hasSign == 1)
        {
            score += 10;
        }
        else
        {
            score += 25;
        }

        if ((bigEn || smEn) && hasDig)
        {
            score += 2;
        }
        else if ((bigEn || smEn) && hasDig && hasSign)
        {
            score += 3;
        }
        else if (bigEn && smEn && hasDig && hasSign)
        {
            score += 5;
        }
        else
        { ; }

        if (score >= 90)
        {
            cout << "VERY_SECURE\n";
        }
        else if (score >= 80)
        {
            cout << "SECURE\n";
        }
        else if (score >= 70)
        {
            cout << "VERY_STRONG\n";
        }
        else if (score >= 60)
        {
            cout << "STRONG\n";
        }
        else if (score >= 50)
        {
            cout << "AVERAGE\n";
        }
        else if (score >= 25)
        {
            cout << "WEAK\n";
        }
        else
        {
            cout << "VERY_WEAK\n";
        }
    }


    return 0;
}