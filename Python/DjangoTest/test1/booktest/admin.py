from django.contrib import admin
from .models import *  # py3

# class HeroInfoInline(admin.StackedInline):
#     model = HeroInfo
#     extra = 3
"""关联对象"""
class HeroInfoInline(admin.TabularInline):
    model = HeroInfo
    extra = 3


class BookInfoAdmin(admin.ModelAdmin):
    """下面是列表页显示效果"""
    # 显示字段，可以点击列头进行排序
    list_display = ['id', 'btitle', 'bpub_date']
    # 过滤字段，过滤框会出现在右侧
    list_filter = ['btitle']
    # 搜索字段，出现搜索框，支持模糊匹配
    search_fields = ['btitle']
    # 分页，每页显示多少条
    list_per_page = 5

    """属性显示的效果"""
    # 修改页、添加页
    fieldsets = [
        ('base', {'fields': ['btitle']}),
        ('super', {'fields': ['bpub_date']})
    ]

    # 属性的先后顺序，和上面的不能一起，会报错
    # fields = ['bpub_date', 'btitle']

    # 在添加一个图书信息的同时，可以再添加三个英雄信息
    inlines = [HeroInfoInline]


# Register your models here.
admin.site.register(BookInfo, BookInfoAdmin)
admin.site.register(HeroInfo)
