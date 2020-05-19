#include<iostream>
#include <string>


#include "SortCompare.h"

using namespace std;

int main()
{
    cout << "**            排序算法比较             **"<<endl;
    cout << "========================================"<<endl;
    cout << "**            1---冒泡排序             **"<<endl;
    cout << "**            2---选择排序             **"<<endl;
    cout << "**            3---直接插入排序          **"<<endl;
    cout << "**            4---希尔排序             **"<<endl;
    cout << "**            5---快速排序             **"<<endl;
    cout << "**            6---堆排序               **"<<endl;
    cout << "**            7---归并排序             **"<<endl;
    cout << "**            8---基数排序             **"<<endl;
    cout << "**            9---退出程序             **"<<endl;
    cout << "========================================"<<endl;

    cout << "请输入要产生的随机数的个数：";
    int N;
    cin>>N;
    
    int whichSort;
    vector<string> changeIndex={"","冒泡排序","选择排序","直接插入排序","希尔排序","快速排序","堆排序","归并排序","基数排序"};
    SortCompare sortCompare(N);

    double sortTime=0;
    long long exchangeTime=0;
    
    while(true)
    {
        cout << "请选择排序算法:";
        cin >> whichSort;
        if(whichSort==9)
        {
            break;
        }
        sortCompare.test(whichSort, sortTime, exchangeTime);
        cout<<changeIndex[whichSort]<<"所用时间:"<<sortTime<<"s"<<endl;
        //归并排序不进行两两交换,所以看比较次数
        if(whichSort==7)
            cout<<changeIndex[whichSort]<<"比较次数："<<exchangeTime<<endl;
        else
            cout<<changeIndex[whichSort]<<"交换次数："<<exchangeTime<<endl;
        //重置
        sortTime = 0.0;
        exchangeTime = 0;
    }




    return 0;
}