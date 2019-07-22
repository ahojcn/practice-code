from django.db import models


# Create your models here.

class BookInfoManager(models.Manager):
    """图书模型管理器类"""

    # 1. 改变查询的结果集
    def all(self):
        # 1. 获取所有的数据，调用父类的 all 方法
        all_books = super().all()
        # 2. 对数据进行过滤
        all_books = all_books.filter(isDelete=False)
        return all_books

    # 2. 添加额外的方法，操作模型类对应的数据表，增删改查
    def create_book(self, btitle, bpub_date):
        model_class = self.model  # 获取 self 锁在的模型类
        book = model_class()

        book.btitle = btitle
        book.bpub_date = bpub_date
        book.save()
        return book


# 1
class BookInfo(models.Model):
    """图书模型类"""
    # 图书名
    btitle = models.CharField(max_length=20)
    # 出版日期
    bpub_date = models.DateField()
    # 阅读量
    bread = models.IntegerField(default=0)
    # 评论量
    bcomment = models.IntegerField(default=0)
    # 逻辑删除标记，默认 False 代表未删除
    isDelete = models.BooleanField(default=False)
    # 价格，最大位数 10，小数位 2，默认 0.0 ￥
    bprice = models.DecimalField(max_digits=10, decimal_places=2, default=0.0)

    # book = models.Manager()  # 自定义一个 Manager 类对象
    objects = BookInfoManager()  # 自定义一个 BookInfoManager 类的对象

    def __str__(self):
        return self.btitle

    # 元选项
    # class Meta:
    #     db_table = 'bookinfo'  # 指定模型类的对应的表名


# n
class HeroInfo(models.Model):
    """英雄人物模型类"""
    # 英雄名
    hname = models.CharField(max_length=20)
    # 性别
    hgender = models.BooleanField(default=False)
    # 备注
    hcomment = models.CharField(max_length=200)
    # 外键
    hbook = models.ForeignKey(BookInfo, on_delete=None)
    # 逻辑删除标记，默认 False 代表未删除
    isDelete = models.BooleanField(default=False)

    def __str__(self):
        return self.hname


# n
class NewsType(models.Model):
    """新闻类型"""
    # 类型名
    type_name = models.CharField(max_length=20)


# n
class NewsInfo(models.Model):
    """新闻类"""
    # 新闻标题
    title = models.CharField(max_length=128)
    # 发布时间
    pub_date = models.DateTimeField(auto_now_add=True)
    # 信息内容
    context = models.TextField()
    # 关联属性，新闻所属类型，当然也可以在 NewsType 中定义这个关系
    news_type = models.ManyToManyField(NewsType)


# 1
class EmployeeBasicInfo(models.Model):
    """员工基本信息"""
    name = models.CharField(max_length=20)
    gender = models.BooleanField(default=False)
    age = models.IntegerField()


# 1
class EmployeeDetailInfo(models.Model):
    """员工详细信息类"""
    address = models.CharField(max_length=250)
    # 教育经历
    # 关系属性，代表员工的基本信息
    employee_basic = models.OneToOneField('EmployeeBasicInfo', on_delete=models.CASCADE)


# 自关联
class AreaInfo(models.Model):
    """地区模型类"""
    # 地区名称
    atitle = models.CharField(max_length=20)
    # 关系属性，代表当前地区的父集地区
    aparent = models.ForeignKey('self', null=True, blank=True, on_delete=None)
