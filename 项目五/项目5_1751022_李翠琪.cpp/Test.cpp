#include<iostream>
#include <vector>
#include "LinkedList.h"

using namespace std;

int main()
{
    cout << "Please Enter the total number of customers N, and the number of N customers:";
    int N;
    cin >> N;
    vector<int> customers;

    LinkedList<int> listA, listB;
    
    for (int i = 0; i < N; ++i)
    {
        int customer;
        cin >> customer;
        customers.push_back(customer);
    }
    for (int i = 0; i <N ; ++i)
    {
        if(customers[i]%2==1)//去1
        {
            listA.enqueue(customers[i]);
        }
        else
        {
            listB.enqueue(customers[i]);
        }
    }
    
    while(!listA.empty() || !listB.empty())
    {
        if(!listA.empty())
        {
            cout << listA.first->value<<" ";
            listA.first = listA.first->next;
        }
        if(!listA.empty())
        {
            cout << listA.first->value<<" ";
            listA.first = listA.first->next;
        }
        if(!listB.empty())
        {
            cout << listB.first->value<<" ";
            listB.first = listB.first->next;
        }
    }

	cout << endl<<"Press the top right corner to exit";
	while (true)
	{

	}
    return 0;
}