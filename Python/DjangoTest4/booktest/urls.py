from django.urls import path, re_path
from booktest import views

urlpatterns = [
    path('index', views.index),
    path('showargs<int:num>', views.show_args),  # 捕获位置参数
    # re_path(r'^showargs(?P<num>\d+)$', views.show_args)  # 捕获关键字参数

    path('login', views.login),  # 显示登录页面
    path('login_check', views.login_check),  # 用户登录校验

    path('test_ajax', views.ajax_test),  # 显示 ajax 页面
    path('ajax_handle', views.ajax_handle),  # 处理请求


    path('login_ajax', views.login_ajax),  # ajax 登录案例

    path('login_ajax_check', views.login_ajax_check),  # ajax 登录校验
]