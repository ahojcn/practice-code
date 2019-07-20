from django.contrib import admin
from django.urls import path, re_path
from booktest import views

urlpatterns = [
    path('index', views.index),
    path('index2', views.index2),

    path('books', views.show_books),  # 显示图书信息
    path('books/<int:bid>', views.detail)  # 显示英雄信息
    # re_path(r'^books/(\d+)$', views.detail)  # 显示英雄信息
]
