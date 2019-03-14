#include "LinkedList.h"

int main(int argc, char const *argv[])
{
    LinkedList CL = NULL;
    InitCLinkedList(&CL);
    CreateCLinkedList(CL);
    ShowCLinkedList(CL);

    LinkedList LA = NULL;
    LinkedList LB = NULL;
    InitCLinkedList(&LA);
    InitCLinkedList(&LB);
    CreateCLinkedList(LA);
    CreateCLinkedList(LB);
    ShowCLinkedList(MergeLinkedList(LA, LB));

    return 0;
}
