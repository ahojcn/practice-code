def is_leap_year(year):
    """
    判断 year 是否是闰年

    :param year: 年份
    :return: 闰年，True；否则，False
    """
    return year % 4 == 0 and year % 100 != 0 or year % 400 == 0

def which_day(year, month, date):
    """
    计算传入的日期是这一年的第几天

    :param year: 年
    :param month: 月
    :param date: 日
    :return: 第几天
    """
    days_of_month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    # 如果是闰年，2月加一天
    if is_leap_year(year):
        days_of_month[1] += 1
    total = 0
    for i in range(month - 1):
        total += days_of_month[i]
    return total + date


def main():
    print(which_day(1980, 11, 28))
    print(which_day(2019, 6, 20))

if __name__ == '__main__':
    main()