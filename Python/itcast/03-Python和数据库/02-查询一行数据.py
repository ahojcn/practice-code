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

    sql = 'select * from students where id = 1'
    cursor1.execute(sql)
    result = cursor1.fetchone()
    print(result)

    conn.commit()

    cursor1.close()
    conn.close()

except Exception as e:
    print(e)

