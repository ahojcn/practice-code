#include <iostream>

// 反面教材：编译器默认生成的，浅拷贝，资源丢失
#if 0
class String {
public:
	String(const char* str = "")
	{
		if (nullptr == str)
		{
			str = "";
		}

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s) : _str(s._str)
	{}

	String& operator=(const String& s)
	{
		_str = s._str;
		return *this;
	}

	~String()
	{
		if (_str != nullptr)
		{
			delete[] _str;
		}
	}

private:
	char* _str;
};
#endif


// 传统版本的深拷贝（拷贝构造、赋值运算符重载）写法
#if 0
class String {
public:
	String(const char* str = "")
	{
		if (nullptr == str)
		{
			str = "";
		}

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s) : _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s)
	{
		// 避免自己给自己赋值
		if (this != &s)
		{
			// 这种方式：先释放了原有空间，再申请新空间
			//     万一申请空间失败，原有的数据也没有了
			/*delete _str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);*/

			// 这种写法比上面稍微好一些，先申请空间，
			//     失败以后就不会释放原有的空间了，外面捕获个异常就好了
			char* pstr = new char[strlen(s._str) + 1];
			strcpy(pstr, s._str);
			delete[] _str;
			_str = pstr;
		}

		return *this;
	}

	~String()
	{
		if (_str != nullptr)
		{
			delete[] _str;
		}
	}

private:
	char* _str;
};

void TestString()
{
	String s1("hello");
	String s2(s1);

	String s3;
	s3 = s2;
}
#endif


// 现代版深拷贝写法
#if 0
class String {
public:
	String(const char* str = "")
	{
		if (nullptr == str)
		{
			str = "";
		}

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		: _str(nullptr)
	{
		String strTemp(s._str);
		std::swap(_str, strTemp._str);
	}

	// 不是一个最简洁写法
	//String& operator=(const String& s)
	//{
	//	// 避免自己给自己赋值
	//	if (this != &s)
	//	{
	//		String strTemp(s._str);
	//		std::swap(_str, strTemp._str);
	//	}
	//	return *this;
	//}

	// 简洁写法
	String& operator=(String s)
	{
		std::swap(_str, s._str);
		return *this;
	}

	~String()
	{
		if (_str != nullptr)
		{
			delete[] _str;
		}
	}

private:
	char* _str;
};
#endif


// 引用计数解决浅拷贝问题，写时拷贝 Copy On Write
// 多线程会出现问题，因为 _pCount 的操作不是原子性的操作
//     解决方法：1. C++11 中有原子类型变量  2. 加锁
#if 0
class String {
public:
	String(const char* str = "")
		: _pCount(new int(1))
	{
		if (nullptr == str)
		{
			str = "";
		}

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		: _str(s._str)
		, _pCount(s._pCount)
	{
		++(*_pCount);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			// 当前对象更新自己资源的计数
			Release();

			// 当前对象与 s 共享资源和计数
			_str = s._str;
			_pCount = s._pCount;
			++(*_pCount);
		}
		return *this;
	}

	char& operator[](size_t index)
	{
		if (GetRef() > 1)
		{
			String strTemp(_str);
			std::swap(_str, strTemp._str);
			std::swap(_pCount, strTemp._pCount);
		}
		return _str[index];
	}

	const char& operator[](size_t index) const
	{
		return _str[index];
	}

	~String()
	{
		Release();
	}

private:
	void Release()
	{
		if (_str != nullptr && 0 == --(*_pCount))
		{
			delete[] _str;
			delete _pCount;
		}
	}

	int GetRef()
	{
		return *_pCount;
	}

private:
	char* _str;
	int* _pCount;
};

void TestString()
{
	String s1("hello");
	String s2(s1);

	String s3("world");
	String s4(s3);

	s3 = s2;  // s3: 原来的计数 1
	s4 = s2;  // 

	s1[0] = 'H';
}

int main()
{
	TestString();
	return 0;
}
#endif