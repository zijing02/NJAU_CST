#include <iostream>
using namespace std;
class BaseClass{
public:
	virtual BaseClass afn(){ cout << "This is BaseClass.\n";  return *this; }
	};
class SubClass : public BaseClass{
public:
	BaseClass afn(){ cout << "This is SubClass.\n"; return *this; }
};
void test(BaseClass& x){	BaseClass b;   b = x.afn();}
void main(){ BaseClass bc;   SubClass sc;   test(bc);   test(sc); }