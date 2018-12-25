#include "LinkList.h"

int main(int argc, const char * argv[])
{
    LinkList *p = NULL;
    InitLinkList(&p);
    InsertFromHead(&p, 1);
    InsertFromHead(&p, 2);
    InsertFromHead(&p, 3);
    InsertFromHead(&p, 4);
    InsertFromHead(&p, 5);
    
    ShowLinkList(&p);
    
    InsertFromTail(&p, 666);
    
    ShowLinkList(&p);
    
    UpdateAllData(&p, 666, 777);

    ShowLinkList(&p);
    
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
