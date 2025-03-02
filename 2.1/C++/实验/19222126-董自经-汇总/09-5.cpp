#include<iostream>
#include<string.h>
using namespace std;
class cstr1{
public:
	cstr1() {}
	cstr1(string tempstr1):str1(tempstr1) {}
	string str1;
	void showstr();
	void changestr(string);
};
class cstr2 :public cstr1 {
public:
	string str2;
	cstr2() {}
	cstr2(string tempstr1, string tempstr2):cstr1(tempstr1) { str2 = tempstr2; }
	void change() {
		changestr(str2);
	}
};
void cstr1::changestr(string str2) {
	string* s = &str1;
	*s = *s + str2;
}
void cstr1::showstr() {
	cout << str1 << endl;
}
int main(){
	cstr1 s1("ab"); cstr2 s2("ab","cd");
	s1.showstr();
	/*
	s1.changestr("cd");			//在cstr1中做出的改变
	s1.showstr();				//用cstr1调用就是abcd
	s2.showstr();				//用cstr2调用就是ab
	*/
	/*
	s2.change();				//在cstr2中做出的改变
	s1.showstr();				//用cstr1调用就是ab
	s2.showstr();				//用cstr2调用就是abcd
	*/
}