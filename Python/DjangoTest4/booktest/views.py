from django.shortcuts import render, HttpResponse, redirect
from django.http import JsonResponse


# Create your views here.
def index(req):
    """首页"""
    return render(req, 'booktest/index.html')


def show_args(req, num):
    """捕获参数"""
    print(req.GET.get('a'))
    return HttpResponse(num)


def login(req):
    """登录页面"""
    return render(req, 'booktest/login.html')


def login_check(req):
    """登录验证"""
    """req.POST 保存 post 提交的参数， req.Get 保存 get 提交参数，参数类型都是 QueryDict 类型的对象"""
    # 获取提交的用户名和密码
    username = req.POST.get('username')
    password = req.POST.get('password')
    # 校验，根据用户名密码查找数据库
    if username == 'ahojcn' and password == '200212':
        # 用户名密码正确，跳转到首页
        return redirect('/booktest/index')
    else:
        # 用户名或密码错误，跳转到登录页面
        return redirect('/booktest/login')
    # 返回应答
    # return HttpResponse('ok')


def ajax_test(req):
    """显示 ajax 页面"""
    return render(req, 'booktest/test_ajax.html')


def ajax_handle(req):
    return JsonResponse({'res': 1})


def login_ajax(req):
    return render(req, 'booktest/login_ajax.html')


def login_ajax_check(req):
    """ajax 登录案例校验"""
    # 1. 获取用户名和密码
    username = req.POST.get('username')
    password = req.POST.get('password')
    # 2. 校验、返回
    if username == 'ahojcn' and password == '200212':
        # 用户名密码正确
        return JsonResponse({'res': 0})
    else:
        # 用户名密码错误
        return JsonResponse({'res': 1})