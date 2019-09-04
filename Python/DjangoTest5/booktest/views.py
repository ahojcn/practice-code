from django.shortcuts import render

# from django.template import loader
from django.http import HttpResponse

from booktest.models import *


# Create your views here.

# /booktest/index
def index(request):
    # ....
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


def hello(request, username, age):
    print(username, type(username))
    print(age, type(age))
    print(request.GET.get('c'))
    print(request.POST)
    return HttpResponse('username : ' + str(username) + '<br>' + 'age : ' + str(age))
