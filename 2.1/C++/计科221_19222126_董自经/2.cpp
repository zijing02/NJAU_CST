#include<iostream>
using namespace std;
class Count{
	static int counter;
	int obj_jd;
public:
	Count();
	static void display_total();
	void display();
	~Count();
};
int Count::counter = 0;
Count::Count(){ counter++; obj_jd = counter; }
Count::~Count(){ counter--; cout << "Object number" << obj_jd << "being destroyed\n"; }
void Count::display_total(){ cout << "Number of objects created is =" << counter << endl; }\
void Count::display(){ cout << "Object ID id" << obj_jd << endl; }
int main(){
	Count a1; Count::display_total();
	Count a2, a3, a4; Count::display_total();
	a2.display(); a4.display();
	return 0;
}