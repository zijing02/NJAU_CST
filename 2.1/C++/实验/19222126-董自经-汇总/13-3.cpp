#include<iostream>
using namespace std;
template <class T1, class T2, class T3>
class Test {
	T1 data1;  T2 data2;  T3 data3;
public:
	Test(T1 x, T2 y, T3 z) { data1 = x;  data2 = y;  data3 = z; }
	void Display();
};
template <class T1, class T2, class T3>
void Test<T1, T2, T3>::Display() {
	cout << data1 << "\t" << data2 << "\t" << data3 << endl;
}

void main() {
	Test<int, int, double> obj1(1, 2, 3.3);    obj1.Display();
	Test<char, float, double> obj2('A', 1.1, 2.2); obj2.Display();
	Test<string, int, string> obj3("c++", 98, "分"); obj3.Display();


}
