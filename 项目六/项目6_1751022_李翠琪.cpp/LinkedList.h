#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include "Node.h"
#include <iostream>

using namespace std;

template<class T>class LinkedList
{
public:
    LinkedList(): root(nullptr)
    {

    }

    void add(T familyRoot)
    {
        root = new Node<T>(familyRoot);
    }

    void add(T familyName,T childName)
    {
        curFind = nullptr;//每次都要重新开始
        findFromTree(root,familyName);//找到了父节点
        if(curFind== nullptr || curFind->value=="-1")
        {
            return;
        }
        Node<T> *curChild = curFind->link;//父节点的子节点,不一定存在
        if(curChild== nullptr)
        {
            curChild = new Node<T>(childName);
            curFind->link = curChild;
        }
        else
        {
            //平行节点
            Node<T> *x = curChild;
            while(x->next!= nullptr)
            {
                x = x->next;
            }
            x->next = new Node<T>(childName);
        }
    }

    void deleteFromTree(T fatherName)
    {
        curFind = nullptr;//每次都要重新开始
        findFromTree(root,fatherName);
        if(curFind== nullptr || curFind->value=="-1")
        {
            return;
        }
        curFind->value = "-1";//延时实现删除操作
        Node<T> *x=curFind->link;
        curFind->link = nullptr;//子代没了

    }

    void update(T fatherName,T updateName)
    {
        curFind = nullptr;//每次都要重新开始
        findFromTree(root,fatherName);
        if(curFind== nullptr || curFind->value=="-1")
        {
            return;
        }
        Node<T> *cur = curFind;
        cur->value = updateName;
    }

    void show(T familyName)
    {
		int N = 0;//子女个数,为了在为空的时候输出一条信息
        curFind = nullptr;//每次都要重新开始
        findFromTree(root, familyName);
        if(curFind== nullptr || curFind->value=="-1")
        {
            return;
        }
        for (Node<T> * temp=curFind->link;temp!= nullptr;temp=temp->next)
        {
            if(temp->value!="-1")
            {
				++N;
                cout << temp->value << " ";
            }
        }
		if(N==0)
		{
			cout << "null"<<endl;
		}
    }

    bool findFromTree(T familyName)
    {
        curFind = nullptr;
        findFromTree(root, familyName);
        if(curFind== nullptr || curFind->value=="-1")
            return false;
        else
            return true;
    }

private:
    void findFromTree(Node<T> * x,T familyName)
    {
        if(x== nullptr)
        {
            return;
        }
        if(x->value==familyName)
        {
            curFind = x;
            return;
        }
        findFromTree(x->link,familyName);
        for (Node<T> * temp=x->next;temp!= nullptr;temp=temp->next)
        {
            findFromTree(temp,familyName);
        }
    }

    Node<T> * root;
    Node<T> *curFind;
};


#endif //_LINKED_LIST_H_
