12-1
#include <iostream>
#include <string>
using namespace std;
class A {
	int i;
protected:
	char c;
public:
	string s;
	A(int tempi, char tempc, string temps) :i(tempi) { c = tempc; s = temps; }
	void show() { cout << "A::i=" << i << "  A::c=" << c << "  A::s=" << s << endl; }
};
class B {
	int i;
protected:
	char c;
public:
	string s;
	B(int tempi, char tempc, string temps) :i(tempi) { c = tempc; s = temps; }
	void show() { cout << "B::i=" << i << "  B::c=" << c << "  B::s=" << s << endl; }
};
class C : public A, public B {
public:
	C(int tempai, char tempac, string tempas, int tempbi, char tempbc, string tempbs) :A(tempai, tempac, tempas), B(tempbi, tempbc, tempbs) {}
};
void main() {
	C c(1, 'a', "as", 2, 'b', "bs");  
	//c.show();
	c.A::show();  c.B::show();
}
