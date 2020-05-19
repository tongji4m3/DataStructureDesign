#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "Node.h"
#include <iostream>

using namespace std;

template <class T> class Queue
{
public:
	void enqueue(T t)
	{
		if (empty())//为空指向同一个
		{
			first = new Node<T>(t, nullptr);
			last = first;
		}
		else
		{
			Node<T> * temp = new Node<T>(t, nullptr);
			last->next = temp;
			last = temp;
		}
		++N;
	}
	T dequeue()
	{
		if (empty())
			throw "队列为空";
		T value = first->value;
		first = first->next;
		--N;
		if (empty())
			last = nullptr;
		return value;
	}

	bool empty()
	{
		return N == 0;
	}

	int size()
	{
		return N;
	}

private:
	Node<T> * first;
	Node<T> * last;
	int N = 0;
};

#endif //_QUEUE_H_
