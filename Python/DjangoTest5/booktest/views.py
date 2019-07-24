from django.shortcuts import render

# from django.template import loader
from django.http import HttpResponse

from booktest.models import *

# Create your views here.

# /booktest/index
def index(request):
    # 1. 加载模板文件
    # temp = loader.get_template('booktest/index.html')
    # 2. 定义模板上下文，传数据给模板
    # context = {}
    # 3. 模板渲染，产生一个替换后的 html 内容
    # res_html = temp.render(context)
    # 4. 返回应答
    # return HttpResponse(res_html)

    # 上面的简写
    return render(request, 'booktest/index.html', {})


# /booktest/index2
def index2(request):
    """模板文件的加载顺序"""
    return render(request, 'booktest/index2.html')


# /booktest/temp_var
def temp_var(request):
    """模板变量"""
    my_dict = {'title': '字典'}
    my_list = [1, 2, 3]
    book = BookInfo.objects.get(id=1)

    context = {'my_dict': my_dict, 'my_list': my_list, 'book': book}
    return render(request, 'booktest/temp_var.html', context)


def hello(request, num):
    print(num, '#'.center(20, '*'))
    return HttpResponse("num:" + str(num))