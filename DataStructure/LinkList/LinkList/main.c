#include "LinkList.h"

int main(int argc, const char * argv[])
{
    LinkList *p = NULL;
    InitLinkList(&p);
    CreateFromTail(&p, 1);
    CreateFromTail(&p, 2);
    CreateFromHead(&p, 3);
    
    ShowLinkList(&p);
    
//    DelFromHead(&p);
    DelFromTail(&p);
    
    ShowLinkList(&p);
    
    printf("%d\n", UpdateFirstData(&p, 5, 2));
    ShowLinkList(&p);
    
//    DestoryLinkList(&p);
    
//    printf("%d\n", SearchValue(&p, 3)->data);
    
//    printf("%d\n", SearchCount(&p, 1)->data);
    
    return 0;
}
