#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Edge.h"
#include "EdgeWeightedGraph.h"
#include "KruskalMST.h"

using namespace std;

int main()
{

	cout << "**             电网建设造价模拟系统             **" << endl;
	cout << "================================================" << endl;
	cout << "**                A---创建电网顶点             **" << endl;
	cout << "**                B---添加电网的边             **" << endl;
	cout << "**                C---构造最小生成树           **" << endl;
	cout << "**                D---显示最小生成树           **" << endl;
	cout << "**                E---退出程序                **" << endl;
	cout << "================================================" << endl;

	unordered_map<string, int> names;//节点名字与节点数字相互对应
	EdgeWeightedGraph * G = nullptr;
	KruskalMST * kruskal = nullptr;

	while (true)
	{
		cout << "请选择操作:";
		char operation;
		cin >> operation;
		if (operation == 'A')
		{
			cout << "请输入节点数量:";
			int N;//节点数量
			cin >> N;
			cout << "请依次输入节点名称:";
			for (int i = 0; i < N; ++i)
			{
				string node;
				cin >> node;
				names[node] = i;
			}
			G = new EdgeWeightedGraph(N);//生成一个没有边的图
		}
		else if (operation == 'B')
		{
			while (true)
			{
				cout << "请输入两个顶点及边：(输入0 0 0 结束)";
				string node1, node2;
				double nodeValue;
				cin >> node1 >> node2 >> nodeValue;
				if (node1 == "0" && node2 == "0" && nodeValue == 0)
				{
					break;
				}
				if (nodeValue <= 0)
				{
					cout << "输入错误,两个城市线路的花费不能小于等于0";
				}
				int v = 0, w = 0;
				auto iter = names.find(node1);
				if (iter != names.end())
				{
					v = iter->second;
				}
				auto iter2 = names.find(node2);
				if (iter2 != names.end())
				{
					w = iter2->second;
				}
				if (v == -1 || w == -1)
				{
					cout << "输入错误,输入的顶点不在图中!";
				}
				else
				{
					Edge edge(v, w, nodeValue);
					G->addEdge(edge);
				}
			}
		}
		else if (operation == 'C')
		{
			cout << "最小生成树构建成功!";
			kruskal = new KruskalMST(*G);
		}
		else if (operation == 'D')
		{
			cout << "最小生成树的顶点和边为:" << endl;
			Queue<Edge> queue = kruskal->getMST();
			while (!queue.empty())
			{
				Edge e = queue.dequeue();
				int v = e.either();
				int w = e.other(v);
				string name1, name2;

				int count = 0;
				for (auto iter = names.begin(); iter != names.end(); ++iter)
				{
					if (iter->second == v)
					{
						name1 = iter->first;
						++count;
					}
					if (iter->second == w)
					{
						name2 = iter->first;
						++count;
					}
					if (count == 2)
					{
						break;
					}//找到这两就退出
				}
				cout << "[" << name1 << "---" << name2 << " cost: " << e.getWeight() << "]" << endl;
			}
			// kruskal->printAll(); 需要字符显示
		}
		else if (operation == 'E')
		{
			cout << "期待您的下次使用!";
			return 0;
		}
	}
}

