#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

template <class T>
class Vector
{
  public:
    typedef T *Iterator;
    typedef const T *ConstIterator;

    Vector() : _start(nullptr), _finish(nullptr), _endOfStorage(nullptr) {}

    Vector(const Vector<T> &v)
    {
        T *_start = new T[v.Capacity()];
        for (size_t i = 0; i < v.Size(); i++)
        {
            _start[i] = v[i];
        }
        _finish = _start + v.Size();
        _endOfStorage = _start + v.Capacity();
    }

    ~Vector()
    {
        if (_start)
        {
            delete[] _start;
            _start = _finish = _endOfStorage = nullptr;
        }
    }

    T &operator=(Vector<T> v)
    {
        Swap(v);
        return *this;
    }

    T &operator[](size_t pos)
    {
        assert(pos < Size());
        return _start[pos];
    }

    const T &operator[](size_t pos) const
    {
        assert(pos < Size());
        return _start[pos];
    }

    void
    Swap(Vector<T> &v)
    {
        swap(_start, v._start);
        swap(_finish, v._finish);
        swap(_endOfStorage, v._endOfStorage);
    }

    void Reserve(size_t n)
    {
        if (n > Capacity())
        {
            size_t sz = Size();
            T *tmp = new T[n];

            if (nullptr != _start)
            {
                for (size_t i = 0; i < sz; i++)
                {
                    tmp[i] = _start[i];
                }
            }

            _start = tmp;
            _finish = _start + sz;
            _endOfStorage = _start + n;
        }
    }

    void Resize(size_t n, const T &val = T())
    {
        if (n <= Size())
        {
            _finish = _start + n;
            return;
        }
        if (n > Capacity())
        {
            Reserve(n);
        }

        Iterator old_finish = _finish;
        Iterator new_finish = _start + n;
        while (old_finish != new_finish)
        {
            *old_finish++ = val;
        }
    }

    /*
     * insert erase 存在迭代器失效问题
     * insert: 增容会导致迭代器失效，故增容之后更新迭代器。
     */
    Iterator Insert(Iterator pos, const T &x)
    {
        assert(pos >= _start && pos <= _finish);

        // 空间是否足够，不够要扩容
        if (_finish == _endOfStorage)
        {
            size_t step = pos - _start; // 保存一下之前的 Size()
            size_t newCap = (_start == nullptr ? 1 : Capacity() * 2);
            Reserve(newCap);
            pos = _start + step; // 因为发生了扩容，空间位置发生了改变，所以重置 pos
        }

        // 从后向前挪动元素
        Iterator end = _finish;
        while (end > pos)
        {
            *end = *(end - 1);
            --end;
        }

        *pos = x;
        ++_finish;
        return pos; // 其实这里不返回也可以，因为pos在上面已经被更新
    }

    /* erase导致迭代器失效
     * erase:
     *  1. 可能导致迭代器访问越界 
     *  2. 位置访问异常
     * 解决方法: 获取erase的返回值，更新迭代器
     */
    Iterator Erase(Iterator pos)
    {
        assert(pos < _finish && pos >= _start);
        Iterator it = pos + 1;
        while (it < _finish) // 从 pos 后面的那个开始
        {
            *(it - 1) = *it; // 用后面的覆盖前面的，就会覆盖掉 pos 位置
            it++;
        }
        --_finish;
        return pos;
    }

    void PushBack(const T &val)
    {
        if (_finish == _endOfStorage)
        {
            size_t newCap = (_start == nullptr ? 1 : 2 * Capacity());
            Reserve(newCap);
        }
        *_finish = val;
        ++_finish;
    }

    size_t Size()
    {
        return _finish - _start;
    }

    size_t Capacity()
    {
        return _endOfStorage - _start;
    }

    Iterator Begin()
    {
        return _start;
    }

    Iterator End()
    {
        return _finish;
    }

    ConstIterator CBegin() const
    {
        return _start;
    }

    ConstIterator CEnd() const
    {
        return _finish;
    }

  private:
    T *_start;
    T *_finish;
    T *_endOfStorage;
};

template <class T>
void PrintVector(Vector<T> &v)
{
    for (int i = 0; i < v.Size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}