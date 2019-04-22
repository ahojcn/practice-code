
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

template <class T>
class Vector
{
public:

	typedef T* iterator;
	typedef const T* const_iterator;
	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{}

	Vector(const Vector<T>& v)
	{
		//开辟空间
		T* _start = new T[v.Capacity()];
		//拷贝内容，深拷贝
		for (int i = 0; i < v.Size(); i++)
		{
			_start[i] = v[i];
		}
		//更新
		_finish = _start + v.Size();
		_endOfStorage = _start + v.Capacity();
	}

	T& operator=(Vector<T> v)
	{
		Swap(v);
		return *this;
	}

	void Swap(Vector<T>& v)
	{
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_endOfStorage, v._endOfStorage);
	}



	size_t Size() const
	{
		return _finish - _start;
	}

	size_t Capacity() const
	{
		return _endOfStorage - _start;
	}

	void PushBack(const T& val)
	{
		if (_finish == _endOfStorage)
		{
			size_t newC = (_start == nullptr ? 1 : 2 * Capacity());
			Reserve(newC);
		}
		*_finish = val;
		//更新size
		++_finish;
	}

	void Reserve(size_t n)
	{
		if (n > Capacity())
		{
			size_t sz = Size();
			//申请新的空间
			T* tmp = new T[n];
			//检查空间是否为空
			if (_start)
			{
				//拷贝原有空间内容, 浅拷贝
				//memcpy(tmp, _start, sizeof(T)* sz);
				//深拷贝，调用T类型的赋值运算符重载完成拷贝
				for (int i = 0; i < sz; i++)
				{
					tmp[i] = _start[i];
				}

				//释放原有空间
				delete[] _start;
			}
			//更新size, capacity
			_start = tmp;
			//更新size
			_finish = _start + sz;
			//更新容量
			_endOfStorage = _start + n;
		}
	}


	T& operator[](size_t pos)
	{
		assert(pos < Size());
		return _start[pos];
	}

	const T& operator[](size_t pos) const
	{
		assert(pos < Size());
		return _start[pos];
	}

	iterator begin()
	{
		return _start;
	}

	iterator end()
	{
		return _finish;
	}

	const_iterator begin() const
	{
		return _start;
	}

	const_iterator end() const
	{
		return _finish;
	}

	//insert, erase 存在迭代器失效问题
	//insert: 增容导致迭代器失效， 故增容之后更新迭代器
	void Insert(iterator pos, const T& val)
	{
		assert(pos >= _start && pos <= _finish);
		size_t len = pos - _start;
		if (_finish == _endOfStorage)
		{
			size_t newC = (_start == nullptr ? 1 : 2 * Capacity());
			Reserve(newC);
		}
		//增容以后更新迭代器
		pos = _start + len;
		iterator end = _finish;
		//从后向前挪动元素
		while (end > pos)
		{
			*end = *(end - 1);
			--end;
		}
		//在pos位置插入元素val
		*pos = val;
		//更新_finish指针
		++_finish;
	}

	// Erase 导致迭代器失效：可能导致迭代器访问越界，或者位置访问异常
	// 获取Erase的返回值，更新迭代器
	iterator Erase(iterator pos)
	{
		assert(pos < _finish && pos >= _start);
		//起始挪动元素的位置, 从前向后依次挪动
		iterator begin = pos + 1;
		while (begin < _finish)
		{
			*(begin - 1) = *begin;
			begin++;
		}
		--_finish;
		return pos;
	}

	void Resize(size_t n, const T& val = T())
	{
		if (n <= Size())
		{
			// _finish -  _start
			_finish = _start + n;
		}
		else
		{
			if (n > Capacity())
			{
				Reserve(n);
			}
			// Size() ~  n
			while (_finish != _start + n)
			{
				*_finish = val;
				_finish++;
			}
		}
	}

	~Vector()
	{
		if (_start)
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}
	}

private:
	T* _start;
	T* _finish;
	T* _endOfStorage;
};

template <class T>
void PrintVector(const Vector<T>& v)
{
	for (int i = 0; i < v.Size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

template <class T>
void PrintVectorFor(const Vector<T>& v)
{
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}


//int main()
//{
//	Vector<string> v2;
//	/*Vector<int> v1;
//	v1.PushBack(1);
//	v1.PushBack(1);
//	v1.PushBack(1);
//	v1.PushBack(1);
//	v1.PushBack(1);*/
//	v2.PushBack("1");
//	v2.PushBack("1");
//	v2.PushBack("1");
//	v2.PushBack("1");
//
//	return 0;
//}

void testVector1()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.PushBack(56);

	PrintVectorFor(v);

	Vector<string> v2;
	v2.PushBack("hello");
	v2.PushBack("world");
	v2.PushBack("bite");
	v2.PushBack("tech");
	v2.PushBack("school");
	PrintVectorFor(v2);

}

void testVector2()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	//v.PushBack(56);
	Vector<int>::iterator vit = v.begin();
	while (vit != v.end())
	{
		if (*vit % 2 == 0)
			v.Erase(vit);
		else
			vit++;
	}
	PrintVectorFor(v);
}
#include <vector>
void testVector3()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	//v.PushBack(56);
	vector<int>::iterator vit = v.begin();
	while (vit != v.end())
	{
		if (*vit % 2 == 0)
			vit = v.erase(vit);
		else
			vit++;
	}
}

void testVector4()
{
	Vector<string> v2;
	v2.PushBack("hello");
	v2.PushBack("world");
	v2.PushBack("bite");
	v2.PushBack("tech");
	v2.PushBack("school");
	PrintVectorFor(v2);
	string s = "abc";  // string(const char* str)
	v2.Resize(18, "abc");
	PrintVectorFor(v2);
}

int main()
{
	testVector4();
	return 0;
}