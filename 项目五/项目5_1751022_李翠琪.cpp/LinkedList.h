#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include "Node.h"

using namespace std;

template<class T>class LinkedList
{
public:
    LinkedList():first(nullptr),last(nullptr)
    {

    }
    bool empty()
    {
        return first == nullptr;
    }
    void enqueue(T t)
    {
        if(first== nullptr && last== nullptr)
        {
            first = new Node<T>(t, nullptr);
            last = new Node<T>(t, nullptr);
        }
        else
        {
            Node<T> *temp = new Node<T>(t, nullptr);
            last->next = temp;
            last=last->next;
            if(first->next== nullptr)
            {
                first->next = last;
            }
        }
    }

    T dequeue()
    {
		if (first == nullptr)
		{
			return nullptr;
		}
        T t = first->value;
		first = first->next;

        if(first== nullptr)
        {
            last = nullptr;
        }
        return t;
    }

    Node<T> * first;
    Node<T> * last;
};


#endif //_LINKED_LIST_H_
