#include<iostream>
#include <vector>
#include "MinPQ.h"

using namespace std;

//等价与用n个元素构建一个二叉树,n个元素在树的最底层
// 并且使得除了root外,其他节点相加最小

/*
 * 反过来思考,如果每次对半分的时候,最后结果最小
 * 那么,在只有碎片的时候,每一次都拿出最小的两个进行拼凑
 * 就是对半分的逆过程了
 * 所以只需要有一个每次都能取出最小元素的优先队列即可
 */
int main()
{
    cout << "输入正整数N(分成N块,N<1024),及N个正整数(每块长度):";
    int N;
    cin >> N;
    int sum = 0;
    MinPQ minPQ(N);
    for (int i = 0; i < N; ++i)
    {
        int len;
        cin >> len;
		minPQ.push(len);
    }
    while(minPQ.size()>=2)
    {
        int min1=minPQ.delMin();
        int min2=minPQ.delMin();
        sum += min1 + min2;
        minPQ.push(min1 + min2);
    }
    cout << sum;
	cout <<endl<< "是否要退出?按1退出"<<endl;
	cin >> N;
	while (N!=1)
	{

	}

    return 0;
}