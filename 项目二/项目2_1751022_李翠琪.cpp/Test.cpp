#include<iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> list1, list2;
    cout<<"输入两行数字:"<<endl;
    int index;
    bool goFirst = true;
    while(cin>>index)
    {
        if(index==-1)
        {
            goFirst=false;
        }
        else if(goFirst)//-1都不需要
        {
            list1.add(index);
        }
		else if(!goFirst)
        {
            list2.add(index);
        }
    }
    Node<int> * cur1 = list1.first;
    Node<int> * cur2 = list2.first;
    bool hasPrint = false;
    while(cur1 && cur2)
    {
        if(cur1->value<cur2->value)
        {
            cur1 = cur1->next;
        }
        else if(cur1->value>cur2->value)
        {
            cur2 = cur2->next;
        }
        else
        {
            hasPrint=true;
            cout << cur1->value << " ";
            cur1 = cur1->next;
        }
    }
    if(!hasPrint)
    {
        cout << "NULL";
    }
	cout <<endl<< "退出请右上角关闭";
	while (true)
	{
	}
    return 0;
}