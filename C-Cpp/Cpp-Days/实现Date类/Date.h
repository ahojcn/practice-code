//
// Created by hanoi_ahoj on 2019-03-17.
//

#ifndef UNTITLED_DATE_H
#define UNTITLED_DATE_H

#include <iostream>

using namespace std;

class Date
{
    friend ostream &operator<<(ostream &os, Date &d);

    friend istream &operator>>(istream &is, Date &d);
public:
    explicit Date(int year = 1900, int month = 1, int day = 1);

    // 拷贝构造 Date d1(d2);
    Date(const Date &d);

    // Date d1 = d2;
    Date &operator=(const Date &d);

    // d += 1
    Date operator+=(int days);

    // d -= 1
    Date operator-=(int days);

    // d + 1
    Date operator+(int days);

    // d - 1
    Date operator-(int days);

    // 计算两个日期的差，返回一个整数
    int operator-(const Date &d);

    // ++d
    Date &operator++();

    // d++
    Date operator++(int);

    // --d
    Date &operator--();

    // d--
    Date operator--(int);

    bool operator>(const Date &d) const;

    bool operator>=(const Date &d) const;

    bool operator<(const Date &d) const;

    bool operator<=(const Date &d) const;

    bool operator==(const Date &d) const;

    bool operator!=(const Date &d) const;

private:
    int _year;
    int _month;
    int _day;

    // 是否是闰年
    bool isLeapYear(int year);

    // 获取当前月的天数
    int getMonthDays(Date &d);
};


#endif //UNTITLED_DATE_H
