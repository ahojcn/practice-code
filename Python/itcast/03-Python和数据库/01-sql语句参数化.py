# coding=utf-8

import pymysql

try:
    conn = pymysql.connect(
        host='10.211.55.19',
        port=3306,
        db='python3',
        user='root',
        password='1Baiduyun$',
        charset='utf8'
    )
    cursor1 = conn.cursor()

    name = input('请输入学生姓名 :')

    sql = 'insert into students(name) values(%s)'
    cursor1.execute(sql, [name])
    conn.commit()

    cursor1.close()
    conn.close()

except Exception as e:
    print(e)

