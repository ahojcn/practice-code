from django.contrib import admin

# Register your models here.
from .models import School, Student

class StudentInline(admin.TabularInline):
    model = Student
    extra = 3

class SchoolAdmin(admin.ModelAdmin):
    # 显示字段，可以在管理页面中点击列头进行排序
    list_display = ['id', 'school_name', 'school_addr', 'school_build_date']
    # 过滤字段，过滤框会出现在管理页面的右侧
    list_filter = ['school_name']
    # 搜索字段，会在管理页面头上出现搜索框，支持模糊匹配
    search_fields = ['school_name']
    # 分页操作，每页显示多少条信息
    list_per_page = 5

    fieldsets = [
        ('base', {'fields': ['school_name', 'school_addr']}),
        ('else', {'fields': ['school_build_date']})
    ]

    inlines = [StudentInline]

class StudentAdmin(admin.ModelAdmin):
    list_display = ['id', 'stu_name', 'gender', 'stu_birth', 'stu_school']

admin.site.register(School, SchoolAdmin)
admin.site.register(Student, StudentAdmin)
