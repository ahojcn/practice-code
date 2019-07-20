from django.db import models


# Create your models here.
# 创建模型
class BookInfo(models.Model):
    """图书模型类"""
    # 图书名
    btitle = models.CharField(max_length=20)
    # 出版日期
    bpub_date = models.DateField()

    def __str__(self):
        return self.btitle


class HeroInfo(models.Model):
    """书中的英雄人物类"""
    # 英雄名
    hname = models.CharField(max_length=20)
    # 性别 Boolean 类型，默认 False 代表男
    hgender = models.BooleanField(default=False)
    # 备注
    hcomment = models.CharField(max_length=128)
    # 关系
    hbook = models.ForeignKey(BookInfo, on_delete=None)

    def __str__(self):
        return self.hname
