from django.urls import path, include
from booktest import views

urlpatterns = [
    path('index', views.index),
    path('create', views.create),
    path('delete<int:bid>', views.delete),
    path('areas', views.areas)  # 自关联案例
]