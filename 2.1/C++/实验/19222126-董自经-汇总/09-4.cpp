#include<iostream>
#include<string.h>
using namespace std;
class employee {
public:
	int num; string name; double salary;
	employee() {}
	employee(int tempnum, string tempname, double tempsa) :num(tempnum) { name = tempname; salary = tempsa; }
};
class salesman :public employee {
public:
	double sales; double commrate;//占比
	salesman() {}
	salesman(int tempnum, string tempname, double tempsa, double tempcom) :employee(tempnum, tempname, tempsa) { commrate = tempcom; }
	void pay();
	void print();
};
void salesman::pay() { sales = commrate * salary; }
void salesman::print() { cout << name << "员工的薪水是：" << commrate << "*" << salary << "=" << sales << endl; }
class salesmanager :public salesman {
public:
	double msalary; salesman p;
	salesmanager() {}
	salesmanager(int tempnum, string tempname, double tempsa, salesman tp, double tempcom) :salesman(tempnum, tempname, tempsa, tempcom) { p = tp; }
	void pay() { msalary = 8000 + commrate* salary; }
	void print() { cout << name << "经理薪水是：" << "8000+" << commrate << "*" << salary << "=" << msalary << endl; }
};
int main() {
	double s,com;
	cout << "输入月销售额与提成率: "; cin >> s>>com;
	salesman li(12, "李华", s, com);
	salesmanager wang(1, "张三", s, li, com);
	li.pay(); li.print(); wang.pay(); wang.print();
}