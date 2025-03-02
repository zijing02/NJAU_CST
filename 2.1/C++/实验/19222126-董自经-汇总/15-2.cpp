#include <iostream>
using namespace std;
/*
Calling test(bc)
In BaseClass, int x = 1
In BaseClass, int x = 2
Calling test(sc)
In SubClass, float x = 1
In SubClass, float x = 2
*/
class BaseClass{
public:
	virtual void fn(float x){ cout << "In BaseClass, int x=" << x << endl; }
};
class SubClass : public BaseClass{
public:
	void fn(float x){ cout << "In SubClass, float x=" << x << endl; }
};
void test(BaseClass& b){ int i = 1;   b.fn(i);   float f = 2.0;   b.fn(f); }
void main()
{
	BaseClass bc;    SubClass sc;
	cout << "Calling test(bc)\n";    test(bc);
	cout << "Calling test(sc)\n";    test(sc);
}