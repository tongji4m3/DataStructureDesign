#include<iostream>
#include <vector>
#include "Stack.h"

using namespace std;

void dfs(vector<vector<int>> & map, vector<vector<bool>>& marked,Stack<pair<int,int>>& path, int i, int j, int xhi,int yhi,bool & hasPath)
{
    int M = map.size(), N = map[0].size();
    path.push(make_pair(i, j));
    marked[i][j] = true;
    if(i==xhi && j==yhi)
    {
		hasPath = true;
        Stack<pair<int, int>> reverse;
        while(!path.empty())
        {
            pair<int, int> p = path.top();
            path.pop();
            reverse.push(p);//反转的stack,用于输出路径
            map[p.first][p.second] = 2;
        }

        cout<<endl;
        cout << "      ";
        for (int i = 0; i < N; ++i)
        {
            cout << i << "列  ";
        }
        cout<<endl;
        for (int i = 0; i < M; ++i)
        {
            cout << i << "行    ";
            for (int j = 0; j < N; ++j)
            {
                if(map[i][j]==0)
                {
                    cout << "0";
                }
                else if(map[i][j]==2)
                {
                    cout << "X";
                }
                else
                {
                    cout << "#";
                }
                cout << "    ";
            }
            cout<<endl;
        }

        cout<<endl<<"迷宫路径为:"<<endl;
        while(!reverse.empty())
        {
            pair<int, int> p = reverse.top();
            reverse.pop();
            if(p.first==xhi && p.second==yhi)
                cout<<"(" << p.first << "," << p.second<<")"<<endl;
            else
                cout << "(" << p.first << "," << p.second << ")->";
        }
    }
    if(i-1>=0 && map[i-1][j]==0 && !marked[i-1][j])
    {
        dfs(map, marked,path, i - 1, j, xhi, yhi, hasPath);
    }
    if(i+1<M && map[i+1][j]==0 && !marked[i+1][j])
    {
        dfs(map, marked,path, i+1, j, xhi, yhi, hasPath);
    }
    if(j+1<N && map[i][j+1]==0 && !marked[i][j+1])
    {
        dfs(map, marked,path, i, j+1, xhi, yhi, hasPath);
    }
    if(j-1>=0 && map[i][j-1]==0 && !marked[i][j-1])
    {
        dfs(map, marked,path, i, j-1, xhi, yhi, hasPath);
    }
    //无路可走时,弹栈
    path.pop();
}

bool isValid(vector<vector<int>> & map,int M,int N,int xlo,int ylo,int xhi,int yhi)
{
    if (xlo < 0 || xlo >= M || ylo < 0 || ylo >= N)
    {
        cout << "起始路径不在迷宫里面";
    }
    else if (map[xlo][ylo] == 1)//输入为墙
    {
        cout << "起始路径为墙,你让他怎么走?";
    }
    else if (xhi < 0 || xhi >= M || yhi < 0 || yhi >= N)
    {
        cout << "终点不在迷宫里面";
    }
    else if (map[xhi][yhi] == 1)//终点为墙
    {
        cout << "终点为墙,你让他怎么到?";
    }
    else
    {
        return true;
    }
    return false;
}

int main()
{
    int M,N;
	cout << "先输入两个正整数,代表迷宫大小M*N;再输入M*N正整数(0,1代表迷宫的路和墙):";
	cin >> M >> N;
    vector<vector<int>> map(M, vector<int>(N,1));//默认设置全为墙,当然没什么用,因为是用户进行输入
    vector<vector<bool>> marked(M, vector<bool>(N, false));//默认为没访问过的
    Stack<pair<int,int>> path;
    /*
     * 0 0 路
     * 1 # 墙
     * 2 x 走的路径
     */
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int mapType;
			cin >> mapType;
            map[i][j] = mapType;
		}
	}
	cout << "输入起始坐标和结束坐标(xlo, ylo), (xhi, yhi):";
	int xlo, ylo, xhi, yhi;
	cin >> xlo >> ylo >> xhi >> yhi;

	if(!isValid(map,M,N,xlo,ylo,xhi,yhi))
    {

		cout <<endl<< "想结束程序就按1: ";
		int gameOver = 0;
		while (true)
		{
			cin >> gameOver;
			if (gameOver == 1)
			{
				break;
			}
		}
	    return 1;
    }

	cout << "迷宫地图:(入口为[" << xlo << "," << ylo << "],终点为[" << xhi << "," << yhi << "])" << endl;

    cout << "      ";
    for (int i = 0; i < N; ++i)
    {
        cout << i << "列  ";
    }
    cout<<endl;
    for (int i = 0; i < M; ++i)
    {
        cout << i << "行    ";
        for (int j = 0; j < N; ++j)
        {
            if(map[i][j]==0)
            {
                cout << "0";
            }
            else
            {
                cout << "#";
            }
            cout << "    ";
        }
        cout<<endl;
    }

	bool hasPath = false;

    //搜索
    dfs(map,marked,path,xlo,ylo,xhi,yhi, hasPath);
	if (!hasPath)
	{
		cout << "没有路径从入口[" << xlo << "," << ylo << "]到达终点[" << xhi << "," << yhi << "])" << endl;
	}

	cout << endl << "想结束程序就按1: ";
	int gameOver = 0;
	while (true)
	{
		cin >> gameOver;
		if (gameOver == 1)
		{
			break;
		}
	}

    return 0;
}


