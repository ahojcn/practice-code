from django.urls import path
from booktest import views

urlpatterns = [
    path('index', views.index),
    path('index2', views.index2),  # 模板文件加载顺序

    path('temp_var', views.temp_var),

    path('hello<int>', views.hello),  # 位置参数
]