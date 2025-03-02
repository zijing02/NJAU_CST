#include<iostream>
using namespace std;
class Student{
public:
	virtual void calTuition(){ cout << "计算学生学费" << endl; }
};
class Master : public Student{
public:
	void calTuition(){ cout << "计算硕士生学费" << endl; }
};
class Doctor : public Student{
public:
	void calTuition(){ cout << "计算博士生学费" << endl; }
};
void fn(Student& x){ x.calTuition(); }
void main()
{
	Student s;   Master m;  Doctor d;
	fn(s);           //计算一下学生s的学费
	fn(m);          //计算一下硕士生m的学费
	fn(d);          //计算一下博士生d的学费
}