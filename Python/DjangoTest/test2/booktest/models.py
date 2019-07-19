from django.db import models

# Create your models here.
# 学校表
class School(models.Model):
    # 学校名
    school_name = models.CharField(max_length=30)
    # 学校地址
    school_addr = models.CharField(max_length=30)
    # 建校日期
    school_build_date = models.DateTimeField()

    def __str__(self):
        return self.school_name

class Student(models.Model):
    # 学生名
    stu_name = models.CharField(max_length=20)
    # 学生出生日期
    stu_birth = models.DateTimeField()
    # 学生性别
    stu_gender = models.BooleanField()
    # 学生是哪个学校的
    stu_school = models.ForeignKey('School', on_delete=None)

    def __str__(self):
        return self.stu_name

    def gender(self):
        if self.stu_gender:
            return '男'
        else:
            return '女'

    gender.short_description = '性别'