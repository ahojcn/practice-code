#include <iostream>
#include <vector>
#include <list>
#include "Stack.h"
#include "Queue.h"
#include "PriorityQueue.h"

void testStack()
{
	using namespace std;
	using ahoj::Stack;

	Stack<int> s1;
	Stack<int, vector<int>> s2;

	s1.push(1);
	s1.push(2);
	s1.push(3);

	while (s1.empty() == false)
	{
		cout << s1.top() << endl;
		s1.pop();
	}
}

void testQueue()
{
	using namespace std;
	using ahoj::Queue;

	Queue<int> q1;
	Queue<int, list<int>> q2;

	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);

	while (q1.empty() == false)
	{
		cout << q1.front() << endl;
		q1.pop();
	}
}

void testPriorityQueue()
{
	using namespace ahoj;
	using namespace std;

	PriorityQueue<int> q;
	q.push(5);
	q.push(1);
	q.push(8);
	q.push(3);
	q.push(6);

	PriorityQueue<int, vector<int>, greater<int>> q0;
	q0.push(100);
	q0.push(1);

	vector<int> v{ 5, 1 , 8 , 3 ,6 };
	PriorityQueue<int> q1(v.begin(), v.end());
	q1.push(5);
	q1.push(1);
	q1.push(8);
	q1.push(3);
	q1.push(6);
}

int main()
{
	// testStack();
	// testQueue();
	// testPriorityQueue();

	double a = 10;
	std::cout << typeid(a).name() << std::endl;
	return 0;
}