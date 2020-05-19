#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <string>
#include <iostream>

using namespace std;

//成员变量:准考证号，姓名，性别，年龄和报考类别
class Student
{
public:
    Student();

    Student(const string &id, const string &name, const string &gender, int age, const string &examCategory);

    //展示该学生的所有信息 4个空格 不打印换行
    void show() const;

    friend ostream &operator<<(ostream &os, const Student &student);

    const string &getId() const;

    void setId(const string &id);

    const string &getName() const;

    void setName(const string &name);

    const string &getGender() const;

    void setGender(const string &gender);

    int getAge() const;

    void setAge(int age);

    const string &getExamCategory() const;

    void setExamCategory(const string &exam_category);
private:
    string _id;//准考证号，可能会很长，所以用string
    string _name;
    string _gender;
    int _age;
    string _exam_category;//报考类别
};


#endif //_STUDENT_H_
