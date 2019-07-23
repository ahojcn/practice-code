from django.shortcuts import render, HttpResponse, redirect
from django.http import JsonResponse

from datetime import datetime, timedelta


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
    # 判断用户是否登录
    if req.session.has_key('islogin'):
        # 已登录，跳转到首页
        return redirect('/booktest/index')
    else:
        # 获取 cookie 中的 username
        if 'username' in req.COOKIES:
            username = req.COOKIES['username']
        else:
            username = ''

        return render(req, 'booktest/login.html', {'username': username})


def login_check(req):
    """登录验证"""
    """req.POST 保存 post 提交的参数， req.Get 保存 get 提交参数，参数类型都是 QueryDict 类型的对象"""
    # 获取提交的用户名和密码
    username = req.POST.get('username')
    password = req.POST.get('password')
    remember = req.POST.get('remember')  # on / None
    # 校验，根据用户名密码查找数据库
    if username == 'ahojcn' and password == '200212':
        resp = redirect('/booktest/index')
        # 判断是否需要记住用户名
        if remember == 'on':
            resp.set_cookie('username', username, max_age=7 * 24 * 3600)  # 记住 1 周
        # 记录用户登录状态
        req.session['islogin'] = True
        # 用户名密码正确，跳转到首页
        return resp
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


# /booktest/set_cookie
def set_cookie(req):
    """设置cookie 信息"""
    resp = HttpResponse('设置 cookie')
    # 设置一个 cookie，名字为 num，值为 1，两周之后过期
    resp.set_cookie('num', 1, max_age=14 * 24 * 3600)
    # resp.set_cookie('num', 1, expires=datetime.now()+timedelta(days=14))
    return resp


# /booktest/get_cookie
def get_cookie(req):
    """获取 cookie 信息"""
    num = req.COOKIES['num']
    return HttpResponse(num)


# /booktest/set_session
def set_session(req):
    """设置 session"""
    req.session['username'] = 'ahojcn'
    req.session['age'] = 19
    return HttpResponse('设置 session')


# /booktest/get_session
def get_session(req):
    """获取 session"""
    username = req.session['username']
    age = req.session['age']
    return HttpResponse(username + ":" + str(age))
