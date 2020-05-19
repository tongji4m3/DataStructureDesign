#ifndef _MINPQ_
#define _MINPQ_

#include <vector>
#include <iostream>

using namespace std;

template <class T> class MinPQ
{
public:
	MinPQ(int N) :pq(N + 1)
	{

	}

	bool isEmpty()
	{
		return size() == 0;
	}

	int size()
	{
		return N;
	}

	T delMin()
	{
		T min = pq[1];
		exch(1, N--);
		sink(1);
		return min;
	}

	void push(T t)
	{
		pq[++N] = t;
		swim(N);
	}

private:
	vector<T> pq;
	int N = 0;//元素个数,从1开始

	void swim(int k)
	{
		while (k > 1 && pq[k] < pq[k / 2])
		{
			exch(k, k / 2);
			k /= 2;
		}
	}

	void sink(int k)
	{
		while (2 * k <= N)
		{
			int j = 2 * k;
			if (j + 1 <= N && pq[j + 1] < pq[j])
			{
				++j;
			}
			if (pq[k] < pq[j])
			{
				break;
			}
			exch(k, j);
			k = j;
		}
	}

	void  exch(int i, int j)
	{
		T temp = pq[i];
		pq[i] = pq[j];
		pq[j] = temp;
	}
};

#endif //_MINPQ_
