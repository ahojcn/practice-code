#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

/*
	非类型模板参数。
	注意：
		1. 浮点数、类对象、字符串是不允许作为非类型模板参数的
		2. 非类型模板参数必须在编译时期就能确认结果
*/
#if 0
template <class T, size_t N = 10>
class Array
{
private:
	T _arr[N];
	size_t _size;
};
#endif


/*
	模板特化
		使用模板可以实现一些与类型无关的代码，
		但是对于一些特殊类型可能会得到一些错误结果
*/
// 函数模板特化
#if 0
template <class T>
bool isEqual(T& l, T& r)
{
	return l == r;
}

void testIsEqual()
{
	char p1[] = "abc";
	char p2[] = "abc";
	if (isEqual(p1, p2) == true)
		cout << "equal" << endl;
	else
		cout << "not equal" << endl;  // 输出这个
}
#endif

// 特化
#if 0
template <class T>
bool isEqual(T& l, T& r)
{
	return l == r;
}

template<>
bool isEqual<char*>(char*& l, char*& r)
{
	if (strcmp(l, r) == 0)
		return true;
	else
		return false;
}

void testIsEqual()
{
	char* p1 = new char[4];
	memcpy(p1, "abc", 4);
	char* p2 = new char[4];
	memcpy(p2, "abc", 4);

	if (isEqual(p1, p2) == true)
		cout << "equal" << endl;
	else
		cout << "not equal" << endl;
}
#endif


// 类模板特化
// 全特化
#if 0
template <class T1, class T2>
class Data
{
public:
	Data()
	{
		cout << "Data<T1, T2>" << endl;
	}

private:
	T1 _d1;
	T2 _d2;
};

template<>
class Data<int, char>
{
public:
	Data()
	{
		cout << "Data<int, char>" << endl;
	}

private:
	int _d1;
	char _d2;
};

void testData()
{
	Data<int, int> d1;
	Data<int, char> d2;
}
#endif

// 偏特化（半特化）
// 基础的类模板
#if 0
template <class T1, class T2>
class Data
{
public:
	Data()
	{
		cout << "Data<T1, T2>" << endl;
	}

private:
	T1 _d1;
	T2 _d2;
};

// 偏特化的部分特化
template <class T1>
class Data<T1, int>
{
public:
	Data()
	{
		cout << "Data<T1, int>" << endl;
	}

private:
	T1 _d1;
	int _d2;
};

// 参数进一步限制
template <class T1, class T2>
class Data<T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
private:
	T1* _d1;
	T2* _d2;
};

template <class T1, class T2>
class Data<T1&, T2&>
{
public:
	Data(const T1 &d1, const T2 &d2)
		: _d1(d1)
		, _d2(d2)
	{
		cout << "Data<T1&, T2&>" << endl;
	}
private:
	const T1& _d1;
	const T2& _d2;
};

void testData()
{
	Data<double, int> d1;  // 特化 int 版本
	Data<int, double> d2;  // 基础类模板
	Data<int*, int*> d3;  // 指针特化版本
	Data<int&, int&> d4(1, 2);  // 引用特化版本
}

int main()
{
	//testIsEqual();
	testData();
	return 0;
}
#endif



/*
	类模板特化应用 --- 类型萃取

	实现一个通用的拷贝函数
*/

// 1. 使用 memcpy 拷贝
//		浅拷贝
#if 0
namespace ahoj
{
	template <class T>
	void copy(T* dst, const T* src, size_t size)
	{
		memcpy(dst, src, size);
	}
}

void testCopy_1()
{
	string str_arr_1[3] = { "111", "222", "333" };
	string str_arr_2[3];
	ahoj::copy(str_arr_2, str_arr_1, 3);
}
#endif

// 2. 赋值方式拷贝
//		虽然解决了自定义类型的浅拷贝问题，但在内置类型拷贝的时候，效率低。
#if 0
namespace ahoj
{
	template <class T>
	void copy(T* dst, const T* src, size_t size)
	{
		for (size_t i = 0; i < size; ++i)
		{
			dst[i] = src[i];
		}
	}

	void testCopy_2()
	{
		string str_arr_1[3] = { "111", "222", "333" };
		string str_arr_2[3];
		ahoj::copy(str_arr_2, str_arr_1, 3);
	}
}
#endif

// 3. 增加一个参数区分自定义类型和内置类型
//		缺陷：用户需要根据所拷贝元素的类型去传递第三个参数，出错概率增加。
#if 0
namespace ahoj
{
	template <class T>
	void copy(T* dst, const T* src, size_t size, bool is_POD_type)
	{
		if (is_POD_type)
			memcpy(dst, src, size);
		else
		{
			for (size_t i = 0; i < size; ++i)
				dst[i] = src[i];
		}
	}
}
#endif

// 4. 使用函数区分内置类型和自定义类型
//		缺陷：枚举需要将所有的类型都遍历一遍，每次都要进行好多次字符串比较，效率低。
#if 0
namespace ahoj
{
	bool isPODType(const char* type)
	{
		const char* arr_type[] = {
			"char", "short", "int",
			"long", "long long", "float",
			"double", "long double"
		};

		for (size_t i = 0; i < sizeof(arr_type) / sizeof(arr_type[0]); ++i)
		{
			if (0 == strcmp(type, arr_type[i]))
				return true;
		}
		return false;
	}

	template <class T>
	void copy(T* dst, const T* src, size_t size)
	{
		if (isPODType(typeid(T).name()) == true)
			memcpy(dst, src, size);
		else
		{
			for (size_t i = 0; i < size; ++i)
			{
				dst[i] = src[i];
			}
		}
	}
}
#endif

// 5. 类型萃取
#if 0
namespace ahoj
{
	struct TrueType  // 代表内置类型
	{
		static bool get()
		{
			return true;
		}
	};

	struct FalseType  // 代表自定义类型
	{
		static bool get()
		{
			return false;
		}
	};

	template <class T>
	struct TypeTraits
	{
		typedef FalseType IsPODType;
	};

	template <>
	struct TypeTraits<char>
	{
		typedef TrueType IsPODType;
	};

	template <>
	struct TypeTraits<short>
	{
		typedef TrueType IsPODType;
	};

	template <>
	struct TypeTraits<int>
	{
		typedef TrueType IsPODType;
	};

	template <>
	struct TypeTraits<long>
	{
		typedef TrueType IsPODType;
	};

	template <>
	struct TypeTraits<long long>
	{
		typedef TrueType IsPODType;
	};

	template <>
	struct TypeTraits<float>
	{
		typedef TrueType IsPODType;
	};

	template <>
	struct TypeTraits<double>
	{
		typedef TrueType IsPODType;
	};

	template <class T>
	void copy(T* dst, const T* src, size_t size)
	{
		if (TypeTraits<T>::IsPODType::get())
			memcpy(dst, src, size * sizeof(T));
		else
		{
			for (size_t i = 0; i < size; ++i)
				dst[i] = src[i];
		}
	}

	void testCopy_5()
	{
		int a1[] = { 0,1,2,3,4,5,6,7,8,9 };
		int a2[10];
		ahoj::copy(a2, a1, 10);

		string str_arr_1[3] = { "111", "222", "333" };
		string str_arr_2[3];
		ahoj::copy(str_arr_2, str_arr_1, 3);
	}
}
#endif

// STL 中的栗子
namespace ahoj
{
	struct __true_type {};  // 内置类型
	struct __false_type {};  // 自定义类型

	template <class type>
	struct __type_traits
	{
		typedef __false_type is_POD_type;
	};

	// 对所有内置类型进行特化
	// 在重载内置类型时，
	// 所有的内置类型都必须重载出来，
	// 包括有符号和无符号，比如：对于int类型，必须特化三个，int -- signed int -- unsigned int
	template <>
	struct __type_traits<char>
	{
		typedef __true_type is_POD_type;
	};

	template <>
	struct __type_traits<signed char>
	{
		typedef __true_type is_POD_type;
	};

	template <>
	struct __type_traits<unsigned char>
	{
		typedef __true_type is_POD_type;
	};

	template <>
	struct __type_traits<int>
	{
		typedef __true_type is_POD_type;
	};

	template <>
	struct __type_traits<float>
	{
		typedef __true_type is_POD_type;
	};

	template <>
	struct __type_traits<double>
	{
		typedef __true_type is_POD_type;
	};

	template <class T>
	void _copy(T* dst, const T* src, size_t n, __true_type)
	{
		memcpy(dst, src, n);
	}

	template <class T>
	void _copy(T* dst, const T* src, size_t n, __false_type)
	{
		for (size_t i = 0; i < n; ++i)
			dst[i] = src[i];
	}

	template <class T>
	void copy(T* dst, const T* src, size_t n)
	{
		_copy(dst, src, n, __type_traits<T>::is_POD_type());
	}
}

void testSTLExp()
{
	int a1[] = { 0,1,2,3,4,5,6,7,8,9 };
	int a2[10];
	ahoj::copy(a2, a1, 10);

	string str_arr_1[3] = { "111", "222", "333" };
	string str_arr_2[3];
	ahoj::copy(str_arr_2, str_arr_1, 3);
}

int main()
{
	// testCopy_1();
	// ahoj::testCopy_2();
	// ahoj::testCopy_5();
	testSTLExp();
	return 0;
}
