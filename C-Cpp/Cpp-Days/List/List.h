#include <iostream>

using namespace std;

template<class T>
struct ListNode
{
    ListNode<T> *_prev;
    ListNode<T> *_next;
    T _val;

    ListNode(const T &val = T()) : _prev(nullptr), _next(nullptr), _val(val)
    {}
};

template<class T>
class List
{
    typedef ListNode<T> Node;
    typedef ListNode<T> *pNode;
private:
    pNode pHead;
};