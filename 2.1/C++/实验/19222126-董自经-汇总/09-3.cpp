3.1
#include <iostream>
#include <string>
using namespace std;
const int SNUM = 2;
const int TNUM = 2;
const int ANUM = 2;
class Person {
protected:
	string name, gender; int age;
public:
	Person() {}
	Person(string tname, string tgender, int tage) :name(tname), gender(tgender), age(tage) {}
};
class Student : public Person {
protected:
	int sno; string major, impression;
public:
	Student() {}
	Student(int tempno, string tempname, string tempgender, int tempage, string tempstr) :Person(tempname, tempgender, tempage) { sno = tempno, major = tempstr; Enroll(); }
	void Enroll() { cout << "一个学生注册完成" << endl; }
	void ShowStudent() { cout << sno << "  " << name << "  " << gender << "  " << age << "  " << major << endl; }
	~Student() { cout << "unconstruct a student" << endl; }
	void LikeOrNot(string tempimpression) { impression = tempimpression; }
};
class Teacher : public Person {
protected:
	int tno; string college, course;
public:
	Teacher() {}
	Teacher(int tempno, string tempname, string tempgender, int tempage, string tempstr) :Person(tempname, tempgender, tempage) { tno = tempno, college = tempstr; Recruit(); }
	void Recruit() { cout << "一名教师招聘完成" << endl; }
	void ShowTeacher() { cout << tno << "  " << name << "  " << gender << "  " << age << "  " << college << endl; }
	~Teacher() { cout << "unconstruct a teacher" << endl; }
	void Course(string tempcourse) { course = tempcourse; }
};
class Administrator : public Person {
protected:
	int ano; string section; Student as; Teacher at;
public:
	Administrator() {}
	Administrator(int tano, string tname, string tgender, int tage, string tsection) : Person(tname, tgender, tage), ano(tano), section(tsection) { Employ(); }
	void Employ() { cout << "一个管理人员招聘完成" << endl; }
	void ShowAdministrator() { cout << ano << "  " << name << "  " << gender << "  " << age << "  " << section << endl; }
	void ManageStudent(Student tempas) { as = tempas; }
	void ArrangeCourse(Teacher temptat) { at = temptat; }
	~Administrator() { cout << "unconstruct an administrator" << endl; }
};
class University {
	string uname, uaddress;  Student s[SNUM];	Teacher t[TNUM];	Administrator a[ANUM];
public:
	University() {}
	University(string tname, string taddress, Student* sp, Teacher* tp, Administrator* ap) :uname(tname) {
		for (int i = 0; i < SNUM; i++) { s[i] = sp[i]; }
		for (int i = 0; i < TNUM; i++) { t[i] = tp[i]; }
		for (int i = 0; i < ANUM; i++) { a[i] = ap[i]; }
	}
	void TermBegin() {}
	void ShowUniversity() {
	}
};
void main() {
	cout << "请输入大学的名称和地址 ";
	string tuname, tuaddress;
	cin >> tuname >> tuaddress;
	int i, tempno, tempage; string tempname, tempgender, tempstr;
	Student ts[SNUM];Teacher tt[TNUM];Administrator ta[ANUM];
	cout << "请按照如下格式输入" << SNUM << "个学生的信息:" << endl << "(学号 姓名 性别 年龄 专业)" << endl;
	for (i = 0; i < SNUM; i++) {
		cin >> tempno >> tempname >> tempgender >> tempage >> tempstr;
		ts[i] = Student(tempno, tempname, tempgender, tempage, tempstr);
		ta[i].ManageStudent(ts[i]);
	}
	cout << "请按照如下格式输入" << TNUM << "个教师的信息::" << endl << "(工号 姓名 性别 年龄 学院)" << endl;
	for (i = 0; i < TNUM; i++) {
		cin >> tempno >> tempname >> tempgender >> tempage >> tempstr;
		tt[i] = Teacher(tempno, tempname, tempgender, tempage, tempstr);
		ta[i].ArrangeCourse(tt[i]);
	}
	cout << "请按照如下格式输入" << ANUM << "个管理人员的信息:" << endl << "(工号 姓名 性别 年龄 部门)" << endl;
	for (i = 0; i < ANUM; i++) {
		cin >> tempno >> tempname >> tempgender >> tempage >> tempstr;
		ta[i] = Administrator(tempno, tempname, tempgender, tempage, tempstr);
	}
	University u(tuname, tuaddress, ts, tt, ta);
	u.ShowUniversity();
}
3.2

#include <iostream>
#include <string>
using namespace std;
const int SNUM = 2;
const int TNUM = 2;
const int ANUM = 2;
class Person {
protected:
	string name, gender; int age;
};
class Student : public Person {
protected:
	int sno; string major, impression;
public:
	void Enroll() {
		cin >> sno >> name >> gender >> age >> major;
		cout << "一个学生注册完成！" << endl;
	}
	void ShowStudent() {}
	void LikeOrNot(string tempimpression) { impression = tempimpression; }
	~Student() { cout << "unconstruct a student" << endl; }
};
class Teacher : public Person {
protected:
	int tno; string college, course;
public:
	void Recruit() {
		cin >> tno >> name >> gender >> age >> college;
		cout << "一个教师招聘完成！" << endl;
	}
	void ShowTeacher() { cout << tno << "  " << name << "  " << gender << "  " << age << "  " << college << endl; }
	void Course(string tempcourse) { course = tempcourse; }
	~Teacher() { cout << "unconstruct a teacher" << endl; }
};
class Administrator : public Person {
protected:
	int ano; string section;  Student as; Teacher at;
public:
	void Employ() {
		cin >> ano >> name >> gender >> age >> section;
		cout << "一个管理人员招聘完成！" << endl;
	}
	void ShowAdministrator() { cout << ano << "  " << name << "  " << gender << "  " << age << "  " << section << endl; }
	void ManageStudent(Student tempas) {  as = tempas; }
	void ArrangeCourse(Teacher temptat) { at = temptat; }
	~Administrator() { cout << "unconstruct an administrator" << endl; }
};
class University {
	string uname, uaddress;  Student s[SNUM];	Teacher t[TNUM];	Administrator a[ANUM];
public:
	University() {}
	void TermBegin() {
		cout << "请输入大学的名称和地址: ";
			cin >> uname >> uaddress;
		int i;
		cout << "请按照如下格式输入" << SNUM << "个学生的信息:" << endl << "(学号 姓名 性别 年龄 专业)" << endl;			for (i = 0; i < ANUM; i++) { s[i].Enroll(); a[i].ManageStudent(s[i]); }
		cout << "请按照如下格式输入" << TNUM << "个教师的信息:" << endl << "(工号 姓名 性别 年龄 学院)" << endl;			for (i = 0; i < ANUM; i++) { t[i].Recruit(); a[i].ArrangeCourse(t[i]); }
		cout << "请按照如下格式输入" << ANUM << "个管理人员的信息:" << endl << "(工号 姓名 性别 年龄 部门)" << endl;		for (i = 0; i < ANUM; i++) { a[i].Employ(); }

	}
	void ShowUniversity() {
		cout << "该大学的基本信息显示如下:" << endl << uname << "  " << uaddress << endl;

	}
};
/*
南京农业大学浦口校区 点将台路40号
201818101 张三 男 20 计算机科学与技术
201828101 李四 女 19 网络工程
2012135 王五 男 33 信息学院
2018078 周丽 女 26 生科学院
2009068 侯退 男 37 教务处
2010135 钱芳 女 31 学工处 
*/
void main()
{
	University u;
	u.TermBegin();
	u.ShowUniversity();
}
