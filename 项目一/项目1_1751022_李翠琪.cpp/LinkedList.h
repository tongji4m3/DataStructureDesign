#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <string>
#include <iostream>
#include "Node.h"
#include "Student.h"

using namespace std;

template<class T>class LinkedList
{
public:
    LinkedList():first(nullptr)
    {

    }
    void add(T t)
    {
        Node<T> *oldFirst = first;
        first = new Node<T>(t,oldFirst);
    }

    void insert(int pos, T t)
    {
        if(pos<=0)
        {
            return;
        }
        if(pos==1)//相当于add
        {
            add(t);
        }
        else
        {
            Node<T> *cur = first;
            for (int i = 0; i < pos - 2; ++i)
            {
                if(cur== nullptr)
                    return;
                cur = cur->next;
            }
            Node<T> *newNode = new Node<T>(t,cur->next);
            cur->next = newNode;
        }
        show();
    }



    void pop(const string & id)
    {
        if(id==first->value.getId())//相当于add
        {
            first = first->next;
        }
        else
        {
            for (Node<T> * x=first; x!= nullptr ; x=x->next)
            {
                if(x->next && x->next->value.getId()==id)
                {
                    Node<T> * temp = x->next;
                    x->next = x->next->next;
                    delete temp;
                }
            }
        }
        show();
    }

    void change(const string & id,int pos,string value)
    {
        //pos 0,1,2,3,4 id,name,gender,age,examCategory
        for (Node<T> * x=first; x!= nullptr ; x=x->next)
        {
            if(id==x->value.getId())
            {
                switch (pos)
                {
                    case 0:
                        x->value.setId(value);
                        break;
                    case 1:
                        x->value.setName(value);
                        break;
                    case 2:
                        x->value.setGender(value);
                        break;
                    case 3:
                        x->value.setAge(atoi(value.c_str()));
                        break;
                    case 4:
                        x->value.setExamCategory(value);
                        break;
                    default:
                        break;
                }
            }
        }
        show();
    }

    void show()
    {
        cout<<endl<<"学号  姓名  性别  年龄  报考类别"<<endl;//空四格
        for (Node<T> * x=first; x!= nullptr ; x=x->next)
        {
            cout<<x->value<<endl;
        }
    }

    void show(const string & id)
    {
        cout<<endl<<"学号  姓名  性别  年龄  报考类别"<<endl;//空四格
        for (Node<T> * x=first; x!= nullptr ; x=x->next)
        {
            if(id==x->value.getId())
            {
                cout<<x->value<<endl;
                return;
            }
        }
        cout << "No such student";
    }

private:
    Node<T> * first;
};


#endif //_LINKED_LIST_H_
