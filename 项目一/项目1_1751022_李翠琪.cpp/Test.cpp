#include <iostream>
#include<string>
#include"Student.h"
#include "LinkedList.h"

using namespace std;

/*
	用控制台选项的选择方式完成下列功能：
	输入考生信息；输出考生信息；查询考生信息；添加考生信息；修改考生信息；删除考生信息。

	项目功能要求：
	本项目的实质是完成对考生信息的建立，查找，插入，修改，删除等功能。
	考生信息包括准考证号，姓名，性别，年龄和报考类别
	数据结构，定义类的成员变量和成员函数；
	然后实现各成员函数以完成对数据操作的相应功能；
	最后完成主函数以验证各个成员函数的功能并得到运行结果。
	采用链表实现
*/

int main()
{
    cout<<"首先请建立考试信息系统!"<<endl;
    cout<<"首先输入考试人数：";
    int N;
    cin>>N;//输入学生人数
    cout<<"请依次输入考生的考号，姓名，性别，年龄和报考类别:";
    //用自定义链表进行存储
    /*
    LinkedList存储Student类，自己实现
    单向链表
    默认的add，在后面加入
    */
    LinkedList<Student> studentList;
    for (int i = 0; i < N; i++)
    {
        string id,name,gender,exam_category;
        int age;
        cin>>id>>name>>gender>>age>>exam_category;
        Student student(id,name,gender,age,exam_category);
        studentList.add(student);
    }
    studentList.show();
    cout<<"请选择你要进行的操作(1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作)"<<endl;

    bool is_continue=true;
    while(is_continue)
    {
        cout<<"请选择你要进行的操作：";
        int operate;//操作
        int pos;//位置
        string id,name,gender,exam_category;
        int age;
        string value;//修改时指定的属性
        Student student;
        cin>>operate;
        //1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作
        switch(operate)
        {
            case 1:
                cout<<"请输入你要插入的考生的位置：";
                cin>>pos;
                //插入一个考生信息
                cout << "请依次输入该考生的信息: ";
                cin>>id>>name>>gender>>age>>exam_category;
                student.setId(id);
                student.setName(name);
                student.setGender(gender);
                student.setAge(age);
                student.setExamCategory(exam_category);
                studentList.insert(pos,student);
                break;
            case 2:
                cout<<"请输入要删除的考生的考号：";
                //注意是操作考号，所有得是string
                cin>>id;
                studentList.pop(id);
                break;
            case 3:
                cout << "请输入要查找的考生的考号：";
                cin >> id;
                studentList.show(id);
                break;
            case 4:
                cout << "请输入要修改的考生的考号：";
                cin >> id;
                cout << "请输入要修改的位置：";
                cin >> pos;
                cout << "请输入要修改的值：";
                cin >> value;
                studentList.change(id,pos,value);
                break;
            case 5:
                studentList.show();
                break;
            case 0:
                is_continue=false;
                break;
            default:
                break;
        }
    }
}