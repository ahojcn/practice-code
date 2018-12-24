#include "LinkList.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    LinkList ll;
    LinkList *pll;

    LinkListInit(&pll);
    LinkListCreateFromTail(&pll);
    LinkListShow(&pll);
    
    return 0;
}
