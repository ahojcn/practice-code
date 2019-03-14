#include "LinkList.h"

int main(int argc, const char * argv[])
{
    LinkList *p = NULL;
    InitLinkList(&p);
//    printf("%d\n", GetLinkListLength(&p));
    InsertFromHead(&p, 1);
//    InsertFromHead(&p, 2);
    InsertFromHead(&p, 3);
//    InsertFromHead(&p, 4);
    InsertFromHead(&p, 5);
    ShowLinkList(&p);
    
    LinkList *q = NULL;
    InitLinkList(&q);
    InsertFromHead(&q, 2);
    InsertFromHead(&q, 4);
    InsertFromHead(&q, 6);
    ShowLinkList(&q);
    MerageOrderedLinkList(&p, &q);
    
//    printf("%d\n", GetLinkListLength(&p));
//    CreateLinkListByKeyBorad(&p);
//    ShowLinkList(&p);
//    p = ReverseLinkList_1(&p);
//    ShowLinkList(&p);
    
//    p = ReverseLinkList_2(&p);
//    ShowLinkList(&p);
    
    //    DelOneNodeIndex(&p, 4);
//    ShowLinkList(&p);
//
//    InsertInMid(&p, 4, 11111);
//    ShowLinkList(&p);
    
    
    
//    InsertFromTail(&p, 666);
//    printf("%d\n", GetLinkListLength(&p));
//    ShowLinkList(&p);
    
//    UpdateAllData(&p, 666, 777);
//
//    InsertInMid(&p, 2, 888);
//
//    ShowLinkList(&p);
    
//    DelFromHead(&p);
//    DelFromTail(&p);
    
//    ShowLinkList(&p);
    
//    printf("%d\n", UpdateFirstData(&p, 5, 2));
//    ShowLinkList(&p);
    
//    DestoryLinkList(&p);
    
//    printf("%d\n", SearchValue(&p, 3)->data);
    
//    printf("%d\n", SearchCount(&p, 1)->data);
    
    return 0;
}
