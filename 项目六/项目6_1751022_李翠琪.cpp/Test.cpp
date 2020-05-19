#include<iostream>
#include "LinkedList.h"
#include <string>

using namespace std;

//用广义表
int main()
{
    cout << "**            家谱管理系统             **"<<endl;
    cout << "========================================"<<endl;
    cout << "**         请选择要执行的操作           **"<<endl;
    cout << "**            A---完善家谱             **"<<endl;
    cout << "**            B---添加家庭成员         **"<<endl;
    cout << "**            C---解散局部家庭         **"<<endl;
    cout << "**            D---更改家庭成员姓名     **"<<endl;
    cout << "**            E---查询家谱            **"<<endl;
    cout << "**            F---退出程序            **"<<endl;
    cout << "========================================"<<endl;

    LinkedList<string> families;
    string familyRoot;
    cout << "首先建立一个家谱!"<<endl;
    cout << "请输入祖先的姓名："<<endl;
    cin >> familyRoot;
    families.add(familyRoot);
    cout << "此家谱的祖先是：" << familyRoot << endl;

    cout<<"请选择要执行的操作:"<<endl;
    string ops;
    cin >> ops;
    while(true)
    {
        if(ops=="A")
        {
            string fatherName;
            int childCount;
            cout<<"请输入要建立家庭的人的姓名:";
            cin >> fatherName;
			if (families.findFromTree(fatherName))//这个人存在了才继续给他加入子女
			{
				cout << "请输入" << fatherName << "的儿女人数：";
				cin >> childCount;
				cout << "请依次输入" << fatherName << "的儿女的姓名";
				string childName;
				for (int i = 0; i < childCount; ++i)
				{
					cin >> childName;
					families.add(fatherName, childName);
				}
				cout << fatherName << "的第一代子孙是：";
				families.show(fatherName);
			}
			else
			{
				cout << "该人不存在!";
			}      
        }
        else if(ops=="B")
        {
            cout << "请输入要添加儿子（或女儿）的人的姓名:";
            string fatherName;
            cin >> fatherName;
			if (families.findFromTree(fatherName))
			{
				cout << " 请输入" << fatherName << "新添加的儿子（或女儿）的姓名：";
				string childName;
				cin >> childName;
				families.add(fatherName, childName);
				cout << fatherName << "的第一代子孙是：";
				families.show(fatherName);
			}
			else
			{
				cout << "该人不存在!";
			}
        }
        else if(ops=="C")
        {
            cout << "请输入要解散家庭的人的姓名：";
            string fatherName;
            cin >> fatherName;
            //删除操作
            cout << "要解散家庭的人是"<< fatherName<<endl;
			if (families.findFromTree(fatherName))
			{
				cout << fatherName << "的第一代子孙是:";
				families.show(fatherName);
				families.deleteFromTree(fatherName);
			}
			else
			{
				cout << "该人不存在!";
			}
		
        }
        else if(ops=="D")
        {
            cout << "请输入更改姓名的人的目前姓名";
            string fatherName;
            cin >> fatherName;
			if (families.findFromTree(fatherName))
			{
				cout << "请输入更改后的姓名";
				string updateName;
				cin >> updateName;
				cout << fatherName << "已更名为" << updateName;//不成功的更名也会有这个提示,但是不想弄了
				families.update(fatherName, updateName);
			}
			else
			{
				cout << "该人不存在!";
			}
        }
        else if(ops=="E")
        {
            string fatherName;
            cout << " 请输入要查询人的姓名：";
            cin >> fatherName;
            if(families.findFromTree(fatherName))
            {
                cout <<fatherName<< "的第一代子孙是：";
                families.show(fatherName);
            }
            else
            {
                cout << "该人不存在!";
            }
        }
        else if(ops=="F")
        {
            break;
        }
        cout<<endl<<"请选择要执行的操作:"<<endl;
        cin>>ops;
    }

    return 0;
}
