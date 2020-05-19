#ifndef _MINPQ_
#define _MINPQ_

#include <vector>
#include <iostream>

using namespace std;

class MinPQ
{
public:
    MinPQ(int len):pq(len+1)
    {

    }
    int size()
    {
        return N;
    }

    int delMin()
    {
        int max = pq[1];
        exch(1, N--);
        sink(1);
        return max;
    }

    void push(int i)
    {
        pq[++N] = i;
        swim(N);
    }

private:
    vector<int> pq;
    int N;//元素个数,从1开始
    
    void swim(int k)
    {
        while(k>1 && pq[k] < pq[k/2])
        {
            exch(k, k / 2);
            k /= 2;
        }
    }
    
    void sink(int k)
    {
        while(2 * k <=N)
        {
			int j = 2 * k;
            if(j+1<=N && pq[j]>pq[j+1])
            {
                ++j;
            }
            if(pq[k]<=pq[j])
            {
				break;
            }
			exch(k, j);
			k = j;
        }
    }
    
    void  exch(int i,int j)
    {
        int temp = pq[i];
        pq[i] = pq[j];
        pq[j] = temp;
    }
};

#endif //_MINPQ_
