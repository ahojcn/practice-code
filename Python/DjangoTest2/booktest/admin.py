from django.contrib import admin

# Register your models here.
# 注册模型类
from booktest.models import BookInfo, HeroInfo


# 自定义管理页面
# 自定义模型管理类

class BookInfoAdmin(admin.ModelAdmin):
    """图书模型管理类"""
    list_display = ['id', 'btitle', 'bpub_date']


class HeroInfoAdmin(admin.ModelAdmin):
    """英雄人物模型管理类"""
    list_display = ['id', 'hname', 'hcomment']


admin.site.register(BookInfo, BookInfoAdmin)
admin.site.register(HeroInfo, HeroInfoAdmin)
