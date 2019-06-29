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

    # sql = 'insert into students(name) values("bbbbbb")'
    sql = 'update students set name="wangxiao" where id=10'
    cursor1.execute(sql)
    conn.commit()

    cursor1.close()
    conn.close()

except Exception as e:
    print(e)

