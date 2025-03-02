14-1-1
#include<iostream>
using namespace std;
class rmb {
public:
	rmb(unsigned int d, unsigned int c);
	rmb operator+(rmb&);
	rmb operator++();
	void display() { cout << (yuan + jf / 100.0) << endl; }
protected:
	unsigned int yuan, jf;
};
rmb::rmb(unsigned int d, unsigned int c) {
	yuan = d; jf = c;
	while (jf >= 100) {
		yuan++;
		jf -= 100;
	}
}
rmb rmb::operator+(rmb& s) {
	unsigned int c = jf + s.jf;
	unsigned int d = yuan + s.yuan;
	return rmb(d, c);
}
rmb rmb::operator++() {
	jf++;
	if (jf >= 100) {
		jf -= 100;
		yuan++;
	}
	return *this;
}
int main() {
	rmb d1(1, 60);
	rmb d2(2, 50);
	rmb d3(0, 0);
	d3 = d1 + d2;
	++d3;
	d3.display();
	return 0;
}
14-1-2
#include<iostream>
#include<String.h>
using namespace std;
class String {
	char name[256];
public:
	String(const char* str) { strcpy(name, str); }
	String() {}
	~String() {}
	String operator +(const String&);
	void display() { cout << "字符串是：" << name << endl; }
};
static char* str;
String String::operator+(const String& a) {
	strcpy(str, name);
	strcat(str, a.name);
	return String(str);
}
void main() {
	str = new char[256];
	String demo1("visual c++");
	String demo2("6.0");
	demo1.display();
	demo2.display();
	String demo3 = demo1 + demo2;
	demo3.display();
	String demo4 = demo3 + "programming";
	demo4.display();
	delete str;

}
14-1-3
#include<iostream>
using namespace std;
class rmb {
	int yuan, jf;
public:
	rmb(int d, int c);
	friend rmb operator + (rmb&, rmb&);
	friend rmb& operator++(rmb&);
	void display() { cout << (yuan + jf / 100.0) << endl; }
};
rmb::rmb(int d, int c) {
	yuan = d; jf = c;
	while (jf >= 100) {
		yuan++;
		jf -= 100;
	}
}
rmb operator+(rmb& s1, rmb& s2) {
	int jf = s1.jf + s2.jf, yuan = s1.yuan + s2.yuan;
	return  rmb(yuan, jf);
}
rmb& operator++(rmb& s) {
	s.jf++;
	if (s.jf >= 100) {
		s.jf -= 100;
		s.yuan++;
	}
	return s;
}
int main(){
	return 0;
}
14-1-4
#include<iostream>
#include<String.h>
using namespace std;
class String {
	char name[256];
public:
	String(const char* str) { strcpy(name, str); }
	String() {}
	~String() {}
	friend String operator +(const String&, const String&);
	void display() { cout << "字符串是：" << name << endl; }
};
static char* str;
String operator+(const String& a, const String& b) {
	strcpy(str,a.name);
	strcat(str,b.name);
	return String(str);
}
void main() {
	str = new char[256];
	String demo1("visual c++");
	String demo2("6.0");
	demo1.display();
	demo2.display();
	String demo3 = demo1 + demo2;
	demo3.display();
	String demo4 = demo3 + "programming";
	demo4.display();
	String demo5 = "programming" + demo4;
	delete str;

}
14-1-5
#include<iostream>
using namespace std;
class complex {
	float real, imag;	// 复数的实部和虚部
public:
	complex(float r = 0, float i = 0) { real = r; imag = i; }
	void print();
	friend complex operator + (complex a, complex b);
	friend complex operator- (complex a, complex b);
	friend complex operator * (complex a, complex b);
	friend complex operator /(complex a, complex b);
};
void complex::print() {
	cout << real;
	if (imag > 0)cout << " +";
	if (imag != 0) cout << imag << " i\n";	// image小于0,则自带
}
complex operator + (complex a, complex b) {
	complex temp;
	temp.real = a.real + b.real;
	temp.imag = a.imag + b.imag;
	return temp;
}
complex operator - (complex a, complex b) {
	complex temp;
	temp.real = a.real - b.real;
	temp.imag = a.imag - b.imag;
	return temp;
}
complex operator * (complex a, complex b) {
	complex temp;
	temp.real = a.real*b.real - a.imag * b.imag;
	temp.imag = a.real * b.imag + a.imag * b.real;
	return temp;
}
complex operator/(complex a, complex b) {
	complex temp;
	float tt;
	tt = 1 / (b.real * b.real + b.imag * b.imag);
	temp.real = (a.real * b.real + a.imag * b.imag) * tt;
	temp.imag = (b.real * a.imag - a.real * b.imag) * tt;
	return temp;
}
void main() {
	complex c1(2.3, 4.6), c2(3.6, 2.8), c3;
	c1.print();
	c2.print();
	c3 = c1 + c2;
	c3.print();
	c3 = c1 - c2;
	c3.print();
	c3 = c1 * c2;
	c3.print();
	c3 = c1 / c2;
	c3.print();
}
14-1-6
#include <iostream>
#include <string.h>

using namespace std;
class Student {
	char name[10];
	float score[3];
	//静态成员sum表示参加计算的学生人数
	// 求每个学生的平均分
	static int sum;
public:
	void operator[] (Student&);
	Student(const char* na, float ma = 0, float en = 0, float ph = 0) {
		score[0] = ma; score[1] = en; score[2] = ph; strcpy(name, na);
	}
	void operator ! () {//求所有学生各门课的平均成绩
		if (sum > 0)
			cout << "mat:" << score[0] / sum << "eng:" << score[1] / sum << "phy:" << score[2] / sum;
	}
};
void Student::operator[](Student& s) {
	unsigned int i;
	float nt = 0;
	for (i = 0; i < 3; i++) {
		score[i] += s.score[i];		// 注意，此语句绝对不可以省略，这样 total 对象的 score 数组的各元素分别记录 3 个学生各门课成绩的总分
		nt += s.score[i];
	}
	cout << s.name << "		: " << nt / 3 << endl;
	sum++;		//参加计算的学生人数 +1

}
int Student::sum = 0;
void main(){
	int i;
	Student sa[] = { Student("Wang", 60, 70, 80),
					Student("Li",70, 80, 90),
					Student("Zhang", 50, 60, 70) }, total("Total");
	for (i = 0; i < 3; i++)
		total[sa[i]];//求每个学生的平均分,注意不能写成total[](sa[ij);或total[]sa[;
	!total;
	// 求所有学生各门课的平均成绩
}
14-1-7
#include<iostream>
using namespace std;
class Increase {
public:
	Increase(int x) :value(x) {}
	Increase& operator++();	//前自增
	Increase operator++(int);	//后自增
	void display() { cout << "the value is " << value << endl; }
private:
	int value;
};
Increase& Increase::operator++ () {
	value++; //先增量
	return *this;	//再返回原对象
}
Increase Increase::operator++(int) {
	Increase temp(*this);		// 临时对象存放原有对象值
	value++;					//原有对象增量修改
	return temp;				//返回原有对象值
}
void main() {
	Increase n(20);		
	n.display();
	(n++).display();		//显示临时对象值
	n.display();			//显示原有对象值
	++n;
	n.display();
	++(++n);
	n.display();
	(n++)++; // 第二次增量操作对临时对象进行
	n.display();
} 
14-1-8
#include<iostream>
using namespace std;
class Increase {
public:
	Increase(int x) :value(x) {}
	friend Increase& operator++(Increase&);	//前自增
	friend Increase operator++(Increase&,int);	//后自增
	void display() { cout << "the value is " << value << endl; }
private:
	int value;
};
Increase& operator++ (Increase& a) {
	a.value++; //先增量
	return a;	//再返回原对象
}
Increase operator++(Increase& a, int) {
	Increase temp(a);		// 临时对象存放原有对象值
	a.value++;					//原有对象增量修改
	return temp;				//返回原有对象值
}
void main() {
	Increase n(20);
	n.display();
	(n++).display();		//显示临时对象值
	n.display();			//显示原有对象值
	++n;
	n.display();
	++(++n);
	n.display();
	(n++)++; // 第二次增量操作对临时对象进行
	n.display();
}
14-1-9
#include < iostream>
using namespace std;
class pp {
public:
	int n;
	float m;
	pp* operator -> () { return this; }
};
void main() {
	pp t1;
	t1->m = 10;
	cout << "t1.m is:" << t1.m << endl;
	cout << "t1->m is" << t1->m << endl;
}
14-1-10
#include<iostream>
using namespace std;
class Sample {
	int n;
public:
	Sample() {}
	Sample(int i):n(i){}
	Sample & operator = (Sample);
	void disp() {
		cout << "n = " << n << endl;
	}
};
Sample& Sample:: operator = (Sample s) {
	Sample;; n = s.n;
	return *this;
}
void main() {
	Sample s1(10), s2;
	s2 = s1;
	s2.disp();
}
14-1-11
#include<iostream>
#include<string>
using namespace std;
class Person {
public:
	Person(const char* na) {
		cout << "call constructor" << endl;
		name = new char[strlen(na) + 1];	// 使用new 进行动态内存分
		if (name != 0)  strcpy(name, na);
	}
	Person(Person&p) {//深拷贝构造函数
		cout << "ca11 copy constructor" << endl;	//复制资源
		name = new char[strlen(p.name) + 1];
		if (name != 0)	strcpy(name, p.name);	//复制对象空间
	}
	void printname() { cout << name << end1; }
	~Person() { delete name; }
	void operator =(Person& p) {
		cout << "call operator override" << endl;
		name = new char[strlen(p.name) + 1];	// 复制资源
		if (name != 0)	strcpy(name, p.name);	// 复制对象空间
	}
private:
	char* name;
};				//类定义的结束
void main() {
	Person wang("wang");
	Person li(wang);		// 调用拷贝构造函数
	li = wang;//调用重载运算符函数
	li.printname();
	
}
14-1-12
#include<iostream>
#include<string>
using namespace std;
class Name {
	;
public:
	Name() { pName = 0; }
	Name(const char* pn) { copyName(pn); }
	~Name() { deleteName(); }
	Name& operator =(Name& s) {		//重载赋值运算符
		deleteName();
		copyName(s.pName);
		return *this;
	}
	void display() { cout << pName << endl; }
protected:
	void copyName(char* pN);
	void deleteName();
	char* pName;
};
void Name::copyName(char* pN) {
	pName = new char[strlen(pN) + 1];
	if (pName)	strcpy(pName, pN);
}
void Name::deleteName() {
	if (pName)
		delete pName,
		pName = 0;
}
void main() {
	Name s("Jone");
	Name t("temporary");
	t.display();
	t = s;	//对象赋值
	t.display();
}
14-1-13
#include<iostream>
#include<malloc.h>
using namespace std;
class Point {
	int x, y;
public:
	Point() {}
	Point(int l, int w) { x = l; y = w; }
	void disp() { cout << "面积:" << x * y << endl; }
	Point operator,(Point r) {
		Point temp;
		temp.x = r.x;
		temp.y = r.y;
		return temp;
	}
	Point operator + (Point r) {
		Point temp;
		temp.x = r.x + x;
		temp.y = r.y + y;
		return temp;
	}
};
void main() {
	Point r1(1, 2), r2(3, 4), r3(5, 6);
	r1.disp();
	r2.disp();
	r3.disp();
	r1 = (r1, r2 + r3, r3);
	r1.disp();
}