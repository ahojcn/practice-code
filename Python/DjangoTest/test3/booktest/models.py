from django.db import models


# 自己写了管理器就没有 objects 了
class BookInfoManager(models.Manager):
    def get_queryset(self):
        return super(BookInfoManager, self).get_queryset().filter(isDelete=False)

    # 更方便的创建对象 2  推荐这么用
    def createObj(self, btitle, bpub_date):
        b = BookInfo()
        b.btitle = btitle
        b.bpub_date = bpub_date
        b.bread = 0
        b.bcommet = 0
        b.isDelete = False
        return b


# Create your models here.
class BookInfo(models.Model):
    btitle = models.CharField(max_length=20)  # 书名
    bpub_date = models.DateTimeField(db_column='pub_date')  # 出版时间
    bread = models.IntegerField(default=0)  # 阅读量
    bcommet = models.IntegerField(null=False)  # 评论量
    isDelete = models.BooleanField(default=False)  # 逻辑删除标记 False 表示未删除

    class Meta:
        db_table = 'bookinfo'  # 定义数据表名称
        # ordering = ['id']  # 对象的默认排序字段，获取对象的列表时使用，接收属性构成的列表   '-id' 表示倒叙
        # 排序会增加数据库的存储开销

    books1 = models.Manager()
    books2 = BookInfoManager()


"""
    # __init__不能用了，为了更方便的创建对象  1  不推荐这么用
    @classmethod
    def createObj(cls, btitle, bpub_date):
        b = BookInfo()
        b.btitle = btitle
        b.bpub_date = bpub_date
        b.bread = 0
        b.bcommet = 0
        b.isDelete = False
        return b
"""


class HeroInfo(models.Model):
    hname = models.CharField(max_length=10)  # 英雄名称
    hgender = models.BooleanField(default=True)  # 性别
    hcontent = models.CharField(max_length=1000)  # 描述
    isDelete = models.BooleanField(default=False)
    book = models.ForeignKey(BookInfo, on_delete=None)  # 外键
