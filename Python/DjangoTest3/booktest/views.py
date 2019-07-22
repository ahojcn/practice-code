from django.shortcuts import render, HttpResponseRedirect, redirect

from booktest.models import *
from datetime import date


# Create your views here.

def index(req):
    """显示图书信息"""
    # 1. 查询所有图书信息
    books = BookInfo.objects.all()
    # 2. 使用模板
    return render(req, 'booktest/index.html', {'books': books})


def create(req):
    """新增一本书"""
    # 1. 创建一个 bookinfo 对象
    b = BookInfo()
    b.btitle = '流行蝴蝶剑'
    b.bpub_date = date(1990, 1, 1)
    # 2. 保存
    b.save()

    # 3. 返回应答，让浏览器再访问 index 页面，重定向
    # return HttpResponseRedirect('index')
    # 简写
    return redirect('/booktest/index')

    # return HttpResponse('ok')


def delete(req, bid):
    """删除图书"""
    # 1. 通过 bid 获取图书对象并删除
    BookInfo.objects.get(id=bid).delete()
    # 2. 重定向到 index
    # return HttpResponseRedirect('index')
    # 简写
    return redirect('/booktest/index')


def areas(req):
    """获取西安市的上级地区和下级地区"""
    area = AreaInfo.objects.get(atitle='西安市')
    # 查询西安市的上级地区
    parent = area.aparent
    # 查询西安市的下级地区
    children = area.areainfo_set.all()
    return render(req, 'booktest/area.html', {
                      'area': area,
                      'parent': parent,
                      'children': children
                  })
