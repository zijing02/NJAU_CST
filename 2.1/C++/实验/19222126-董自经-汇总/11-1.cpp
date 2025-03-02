#include <iostream>
using namespace std;
class Wood {
public:
	int wamount;
	Wood(int temp) :wamount(temp) { UseWood(); }
	void UseWood() { cout << "The furniture uses " << wamount << " pieces woods." << endl; }
};
class Mental {
public:
	int mamount;
	Mental(int temp) :mamount(temp) { UseMental(); }
	void UseMental() { cout << "The furniture uses " << mamount << " pieces mentals." << endl; }
};
class Furniture : public Wood, public Mental {
public:
	Furniture(int t1, int t2) :Wood(t1), Mental(t2) {}
};
class Sofa : public Furniture {
protected:
	int sofacapacity;  double sofaweight;
public:
	Sofa(int t1, int t2, int t3, int t4) : Furniture(t1, t2) { sofacapacity = t3; sofaweight = t4; show(); }
	void show() { cout << "The sofa weights " << sofaweight << " and can sit " << sofacapacity << " persons." << endl; }

};
class Bed : public Furniture {
protected:
	int bedcapacity;  double bedweight;
public:
	Bed(int t1, int t2, int t3, int t4) :Furniture(t1, t2), bedcapacity(t3), bedweight(t4) { CanLie(); }
	void CanLie() { cout << "The bed weights " << bedweight << " and can lie " << bedcapacity << " persons." << endl; }
};
class SofaBed : public Sofa, public Bed {
public:
	SofaBed(int t1, int t2, int t3, int t4, int t5, int t6, int t7, int t8) :Sofa(t1, t2, t3, t4), Bed(t5, t6, t7, t8) { ItsFunction(); }
	void ItsFunction() { cout << "The sofabed uses " << Sofa::wamount + Bed::wamount << " pieces woods and " << Sofa::mamount + Bed::mamount << " pieces mentals,and weights " << Sofa::sofaweight + Bed::bedweight << " and can accommodate " << Sofa::sofacapacity + Bed::bedcapacity << " persons." << endl; }


};
void main() { SofaBed test(40, 20, 4, 100, 60, 30, 2, 150); }
