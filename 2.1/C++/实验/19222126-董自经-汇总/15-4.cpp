#include <iostream>
using namespace std;
class People{
	int age;
public:
	People(int t) :age(t){ cout << "Life is short, we should learn c++ harder!" << endl; }
	virtual void showage(){ cout << "People:" << age << endl; }
};
class Baby : public People{
	int bage;
public:
	Baby(int t1, int t2) :People(t1), bage(t2){}
	void showage(){ cout << "Baby:" << bage << endl; }
};
class Student : public Baby{
	int sage;
public:
	Student(int t1, int t2, int t3) :Baby(t1, t2){ sage = t3; }
	void showage(){ cout << "Student:" << sage << endl; }
};
class Adult : public Student{
	int aage;
public:
	Adult(int t1, int t2, int t3, int t4) :Student(t1, t2, t3), aage(t4){}
	void showage(){ cout << "Adult:" << aage << endl; }
};
class Older : public Adult{
	int oage;
public:
	Older(int t1, int t2, int t3, int t4, int t5) :Adult(t1, t2, t3, t4), oage(t5){}
	void showage(){ cout << "Older:" << oage << endl; }
};
void main(){
	Baby b(1, 6); Student s(7, 12, 18); Adult a(19, 30, 40, 50); Older o(60, 70, 80, 90, 100);
	People p(0), *ptr[5] = { &p, &b, &s, &a, &o };
	for (int i = 0; i<5; i++)
		ptr[i]->showage();
}