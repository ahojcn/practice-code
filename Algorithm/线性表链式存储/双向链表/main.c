#include "DuLinkedList.h"

int main(int argc, char const *argv[])
{
    DuLinkedList DL = NULL;
    InitDuLinkedList(&DL);
    CreateFromTail(DL);
    ShowDuLinkedList(DL);

    return 0;
}
