from django.shortcuts import render

# Create your views here.
from .models import Student, School

def index(req):
    stu_list = Student.objects.all()
    context = {'stu_list': stu_list}
    return render(req, 'booktest/index.html', context=context)