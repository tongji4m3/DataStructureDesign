#ifndef _NODE_H_
#define _NODE_H_

template <class T> class Node
{
public:
    T value;
    Node<T> *next;
    Node<T> *link;

    Node(T value) : value(value), next(nullptr), link(nullptr) {}
};
#endif //_NODE_H_
