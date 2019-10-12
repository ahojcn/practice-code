#pragma once
#include <cassert>

/*
	带头单链表
*/

namespace ahoj
{
	template <class T>
	class LinkedList
	{
	public:
		LinkedList() :  _len(0) 
		{
			(*_head)(0);
		}
		LinkedList(const size_t n, const T& val)
		{
			_node* cur = _head;
			for (size_t i = 0; i < n; ++i)
			{
				_node new_node(val);
				cur->next = new_node;
				cur = cur->next;
				++_len;
			}
		}

	private:
		class _node
		{
		public:
			_node(const T& val) : val(val), next(nullptr) {}

		public:
			T val;
			_node* next;
		};

		_node* _head;
		size_t _len;
	};
}