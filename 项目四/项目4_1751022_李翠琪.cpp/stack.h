#ifndef _STACK_H_
#define _STACK_H_

#include "Node.h"

template <class T> class Stack
{
public:
    void push(T t)
    {
        Node<T> *oldFirst = first;
        first = new Node<T>(t, oldFirst);
		++N;
    }
    void pop()
    {
        if(empty())
            return;
        Node<T> *temp = first;
        first = first->next;
        delete temp;
		--N;
    }

	
    bool empty()
    {
        return N==0;
    }

    T top()
    {
        return first->value;
    }

private:
    Node<T> * first;
	int N = 0;
};

#endif //_STACK_H_
