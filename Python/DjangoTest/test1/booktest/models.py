from django.db import models


# Create your models here.
class BookInfo(models.Model):
    # 类属性用来生成表的字段
    btitle = models.CharField(max_length=20)
    bpub_date = models.DateTimeField()

    def __str__(self):
        return self.btitle


class HeroInfo(models.Model):
    hname = models.CharField(max_length=10)
    hgender = models.BooleanField()
    hcontent = models.CharField(max_length=1000)
    hbook = models.ForeignKey(BookInfo, on_delete=None)  # 外键

    def __str__(self):
        return self.hname
