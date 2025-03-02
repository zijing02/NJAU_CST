#include <iostream>
#include <string>
using namespace std;
class GrandFather {
private:
	int  CardID;
	void showCardID() { cout << "GrandFather::CardID=" << CardID << endl; }
protected:
	int Age;
	void showAge() { cout << "GrandFather::Age=" << Age << endl; }
public:
	string Name;
	void showName() { cout << "GrandFather::Name = " << Name << endl; }
	GrandFather(string name, int age, int cardid) { Name = name; Age = age; CardID = cardid; }
		//void showGrandFatherCardID(){showCardID();}    //预留的显示GrandFather类中CardID信息的接口；
};
class Father :public GrandFather {
private:
	int CardID; string Name;
	void showCardID() { cout << "Father::CardID=" << CardID << endl; }
protected:

public:
	void showName() { cout << "Father::Name = " << Name << endl; }
	Father(string tempname, int tempage, int tempid, string tempname2, int tempage2, int tempid2) :GrandFather(tempname, tempage, tempid) { Father::CardID = tempid2; Name = tempname2; Age = tempage2; }


	//void showGrandFatherCardIDinFather(){showGrandFatherCardID();}  //Father类中用于显示GrandFather类的CardID信息的接口；
	//void showFatherCardID(){showCardID();}                          //预留的显示Father类中CardID信息的接口；
};
class Child :public Father {
private:
	int CardID;
	void showCardID() { cout << "Child::CardID=" << CardID << endl; }
protected:
	int Age;
	void showAge() { cout << "Child::Age=" << Age << endl; }
public:
	string Name;
	//void showName() { cout << "Child::Name = " << Name << endl; }
	Child(string tempname, int tempage, int tempid, string tempname2, int tempage2, int tempid2, string tempname3, int tempage3, int tempid3) :Father(tempname, tempage, tempid, tempname2, tempage2, tempid2) {
		Child::CardID = tempid3; Name = tempname3; Age = tempage3;
	}


	//void showGrandFatherCardIDinChild(){showGrandFatherCardIDinFather();}//Child类中用于显示GrandFather类的CardID信息的接口；
	//void showFatherCardIDinChild(){showFatherCardID();}//预留的显示Child类中CardID信息的接口；
};
int main() {
	//以下代码为验证同名覆盖机制和局部优先原则；
	GrandFather g("GrandFather", 70, 123);
	g.showName();
	//g.showAge();
	//g.showCardID();
	Father f("GrandFather", 70, 123, "Father", 40, 456);
	f.showName();
	//f.showAge();
	//f.showCardID();
	Child c("GrandFather", 70, 123, "Father", 40, 456, "Child", 10, 789);
	//c.showName();
	//c.showAge();
	//c.showCardID();

	//以下代码为验证支配规则（即作用域规则）；
	f.GrandFather::showName();
	c.GrandFather::showName();
	c.Father::showName();

	//以下代码为验证最近优先原则（需要注释掉Child类中的showName()成员函数）；
	c.showName();
	return 0;
}