//
// Created by hanoi_ahoj on 2019-03-17.
//

#include "Date.h"

Date::Date(int year, int month, int day) : _year(year), _month(month), _day(day)
{
    if (year < 1900 || (month < 1 || month > 12) || (day < 1 || day > getMonthDays(*this)))
    {
        cout << "错误的初始化日期，以将日期定义为初始值(1900-1-1)" << endl;
        _year = 1900;
        _month = 1;
        _day = 1;
    }
}

Date::Date(const Date &d)
{
    _year = d._year;
    _month = d._month;
    _day = d._day;
}

Date &Date::operator=(const Date &d)
{
    if (this != &d)
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }
    return *this;
}

Date Date::operator+=(int days)
{
    if (days < 0)
    {
        *this -= days;
    }
    _day += days;
    while (_day > getMonthDays(*this))
    {
        _day -= getMonthDays(*this);
        _month += 1;
        if (_month > 12)
        {
            _month -= 12;
            _year += 1;
        }
    }
    return *this;
}

Date Date::operator-=(int days)
{
    if (days < 0)
    {
        *this += days;
    }
    _day += days;
    while (_day > getMonthDays(*this))
    {
        _day -= getMonthDays(*this);
        _month += 1;
        if (_month > 12)
        {
            _month -= 12;
            _year += 1;
        }
    }
    return *this;
}

int Date::getMonthDays(Date &d)
{
    int ret_days = -1;
    if (d._month == 2 && isLeapYear(d._year))
    {
        ret_days = 29;
    }
    else
    {
        switch (d._month)
        {
            case 2:
                ret_days = 28;
                break;
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                ret_days = 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                ret_days = 30;
                break;
            default:
                break;
        }
    }

    return ret_days;
}

bool Date::isLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

Date Date::operator+(int days)
{
    Date ret = *this;
    ret += days;
    return ret;
}

Date Date::operator-(int days)
{
    Date ret = *this;
    ret -= days;
    return ret;
}

int Date::operator-(const Date &d)
{
    int cnt = 0;
    Date tmp = d;
    if (*this > d)
    {
        while (*this != tmp)
        {
            tmp++;
            cnt++;
        }
    }
    else
    {
        while (*this != tmp)
        {
            tmp--;
            cnt++;
        }
    }
    return cnt;
}

Date &Date::operator++()
{
    (*this) += 1;
    return *this;
}

Date Date::operator++(int)
{
    Date ret = *this;
    (*this) += 1;
    return ret;
}

Date &Date::operator--()
{
    (*this) -= 1;
    return *this;
}

Date Date::operator--(int)
{
    Date ret = *this;
    (*this) -= 1;
    return ret;
}

bool Date::operator>(const Date &d) const
{
    return (_year > d._year)
           || (_month > d._month)
           || (_day > d._day);
}

bool Date::operator==(const Date &d) const
{
    return (_year == d._year)
           && (_month == d._month)
           && (_day == d._day);
}

bool Date::operator!=(const Date &d) const
{
    return !(*this == d);
}

bool Date::operator>=(const Date &d) const
{
    return (*this > d) && (*this == d);
}

bool Date::operator<(const Date &d) const
{
    return *this <= d;
}

bool Date::operator<=(const Date &d) const
{
    return (*this < d) && (*this == d);
}

ostream &operator<<(ostream &os, Date &d)
{
    cout << d._year << "-" << d._month << "-" << d._day;
    return os;
}

istream &operator>>(istream &is, Date &d)
{
    cout << "日期输入格式：1970 1 1" << endl << "输入 > ";
    cin >> d._year >> d._month >> d._day;
    return is;
}
