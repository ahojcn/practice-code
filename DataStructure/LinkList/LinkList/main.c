#include "LinkList.h"

int main(int argc, const char * argv[])
{
    LinkList *p = NULL;
    InitLinkList(&p);
    CreateFromTail(&p, 1);
    CreateFromTail(&p, 2);
    CreateFromHead(&p, 3);
    
    ShowLinkList(&p);
    
    DelFromHead(&p);
    ShowLinkList(&p);
    
    return 0;
}
