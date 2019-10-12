#include <iostream>
#include "LinkList.h"

int main() {
    using namespace ahoj;

    SigList<int> sl;

    sl.pushFront(1);
    sl.pushFront(2);
    sl.pushFront(3);

    sl.pushBack(4);
    sl.pushBack(5);
    sl.pushBack(6);

    return 0;
}