#include "Vector.h"

int main()
{
    Vector<int> v;
    v.PushBack(1);
    v.PushBack(2);
    v.PushBack(3);
    v.PushBack(4);
    //v.PushBack(56);
    Vector<int>::Iterator vit = v.Begin();
    while (vit != v.End())
    {
        if (*vit % 2 == 0)
            vit = v.Erase(vit);
        else
            vit++;
    }
    PrintVector(v);
    // Vector<int> v;
    // v.PushBack(1);
    // v.PushBack(2);
    // v.PushBack(3);
    // v.PushBack(4);
    // v.PushBack(56);

    // PrintVector(v);

    // Vector<string> v2;
    // v2.PushBack("hello");
    // v2.PushBack("world");
    // v2.PushBack("bite");
    // v2.PushBack("tech");
    // v2.PushBack("school");
    // PrintVector(v2);
    return 0;
}