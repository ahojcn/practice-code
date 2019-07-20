from django.shortcuts import render
from django.http import HttpResponse

from booktest.models import BookInfo, HeroInfo


# 导入模板文件
# from django.template import loader, RequestContext


# Create your views here.
# 创建视图函数

def index(request):
    # 进行处理，需要数据找 M，需要页面找 T
    # return HttpResponse('<h1>index</h1>')

    """
    # 使用模板
    # 1. 加载模板文件
    temp = loader.get_template('booktest/index.html')
    # 2. 给模板文件传递数据
    context = {}
    # 3. 模板渲染: 产生标准的 html 内容
    res_html = temp.render(context)
    # 4. 返回给浏览器
    return HttpResponse(res_html)
    """

    # 简洁写法
    c = {'index': 'index', 'list': list(range(1, 10))}
    return render(request, 'booktest/index.html', context=c)


# url/booktest/index2
def index2(req):
    return HttpResponse('<h1>index2</h1>')


def show_books(req):
    """显示图书信息"""
    # 1. 通过 M 查找图书表中的数据
    books = BookInfo.objects.all()
    # 2. 使用模板
    return render(req, 'booktest/show_books.html', {'books': books})


def detail(req, bid):
    # print(bid, "#".center(50, '*'))
    """查询图书关联的英雄信息"""
    # 1. 根据 id 查询图书
    book = BookInfo.objects.get(id=bid)
    # 2. 查询和 book 关联的英雄信息
    heros = book.heroinfo_set.all()
    # 3. 使用模板
    return render(req, 'booktest/detail.html', {'book': book, 'heros': heros})
