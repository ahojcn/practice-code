from django.shortcuts import render

from .models import BookInfo

# 聚合函数
from django.db.models import Max, F, Q


# Create your views here.
def index(request):
    # book_list = BookInfo.books1.filter(heroinfo__hcontent__contains='六')
    # book_list = BookInfo.books1.filter(pk__lte=3)
    max = BookInfo.books1.aggregate(Max('bpub_date'))

    # book_list = BookInfo.books1.filter(bread__gt=F('bcommet'))  # 阅读量大于评论量的
    # book_list = BookInfo.books1.filter(pk__lt=4, btitle__contains='1')  # 主键大于4并且title包含 1 的  逻辑与的关系
    book_list = BookInfo.books1.filter(Q(pk__lt=4) | Q(btitle__contains='1'))  # 逻辑或
    contest = {
        'max': max,
        'book_list': book_list,
    }
    return render(request, 'booktest/index.html', context=contest)
