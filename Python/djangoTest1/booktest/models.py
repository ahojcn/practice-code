from django.db import models


class BookInfo(models.Model):
    # 属性，生成数据库表结构的
    btitle = models.CharField(max_length=20)  # 书名
    bpub_date = models.DateTimeField()  # 日期

    def __str__(self):
        return self.btitle.encode('utf-8')


class HeroInfo(models.Model):
    # 属性，生成数据库表结构的
    hname = models.CharField(max_length=10)  # 英雄名
    hgender = models.BooleanField()  # 英雄性别
    hcontent = models.CharField(max_length=1000)  # 英雄简介
    hbook = models.ForeignKey(BookInfo)  # 所属图书，引用外键，对应BookInfo的主键
