#include "Student.h"

Student::Student
(const string &id, const string &name, const string &gender, int age, const string &examCategory) :
_id(id), _name(name), _gender(gender), _age(age), _exam_category(examCategory)
{

}

const string &Student::getId() const
{
    return _id;
}

void Student::setId(const string &id)
{
    _id = id;
}

const string &Student::getName() const
{
    return _name;
}

void Student::setName(const string &name)
{
    _name = name;
}

const string &Student::getGender() const
{
    return _gender;
}

void Student::setGender(const string &gender)
{
    _gender = gender;
}

int Student::getAge() const
{
    return _age;
}

void Student::setAge(int age)
{
    _age = age;
}

const string &Student::getExamCategory() const
{
    return _exam_category;
}

void Student::setExamCategory(const string &exam_category)
{
    _exam_category = exam_category;
}

void Student::show() const
{
   cout<<_id<<"    "<<_name<<"    "<<_gender<<"    "<<_age<<"    "<<_exam_category;
}

Student::Student() {}

ostream &operator<<(ostream &os, const Student &student)
{
    os << student._id << "    " << student._name << "    " << student._gender << "    "
       << student._age << "    " << student._exam_category;
    return os;
}
