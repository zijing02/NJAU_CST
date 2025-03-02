#include <iostream>
#include <string>
using namespace std;
class Ancestor{
protected:
	string Aname;	char Agender;
public:
	Ancestor(string name, char gender) :Aname(name), Agender(gender) { cout << "The Ancestor is constructed!" << endl; }
	void displayAncestor(){ cout << "The information of my Ancestor is: " << Aname << "  " << Agender << endl; }
	~Ancestor(){ cout << "The Ancestor is unconstructed!" << endl; }
};
class GrandFather : public Ancestor{
protected:
	string Gname;	char Ggender;
public:
	GrandFather(string name1, char gender1, string name2, char gender2):Ancestor(name1,gender1),Gname(name2),Ggender(gender2){}
	void displayMyself(){ cout << "The information of my GrandFather is: " << Gname << "  " << Ggender << endl; }
	void displayGrandFather(){ displayAncestor(); displayMyself(); }
	~GrandFather(){ cout << "The GrandFather is unconstructed!" << endl; }
};
class Father : public GrandFather{
protected:
	string Fname;	char Fgender;
public:
	Father(string name1, char gender1, string name2, char gender2, string name3, char gender3):GrandFather(name1,gender1,name2,gender2),Fname(name3),Fgender(gender3)	{cout << "The Father is constructed!" << endl; }
	void displayMyself(){ cout << "The information of my Father is: " << Fname << "  " << Fgender << endl; }
	void displayFather(){ displayGrandFather(); displayMyself(); }
	~Father(){ cout << "The Father is unconstructed!" << endl; }
};
class Brother : public Father{
protected:
	string Bname;	char Bgender;
public:
	Brother(string name1, char gender1, string name2, char gender2, string name3, char gender3, string name4, char gender4) :Father(name1, gender1, name2, gender2, name3, gender3), Bname(name4), Bgender(gender4){cout << "The Brother is constructed!" << endl; }
	void displayMyself(){ cout << "The information of my Brother is: " << Bname << "  " << Bgender << endl; }
	void displayBrother(){ displayFather(); displayMyself(); }
	~Brother(){ cout << "The Brother is unconstructed!" << endl; }
};
class Sister : public Father{
protected:
	string Sname;	char Sgender;
public:
	Sister(string name1, char gender1, string name2, char gender2, string name3, char gender3, string name4, char gender4) :Father(name1, gender1, name2, gender2, name3, gender3), Sname(name4), Sgender(gender4){ cout << "The Sister is constructed!" << endl; }
	void displayMyself(){ cout << "The information of my Sister is: " << Sname << "  " << Sgender << endl; }
	void displaySister(){ displayFather(); displayMyself(); }
	~Sister(){ cout << "The Sister is unconstructed!" << endl; }
};
class Me : public Father{
protected:
	string Mname;	char Mgender;	Brother Bro; Sister Sis;
public:
	Me(string name1, char gender1, string name2, char gender2, string name3, char gender3, string name4, char gender4, Brother tbro, Sister tsis) :Father(name1, gender1, name2, gender2, name3, gender3), Mname(name4),Mgender(gender4),Bro(tbro),Sis(tsis){cout << "The Me is constructed!" << endl; }
	void displayMe(){ displayFather(); Bro.displayMyself(); Sis.displayMyself(); cout << "The information of Me is: " << Mname << "  " << Mgender << endl; }
	~Me(){ cout << "The Me is unconstructed!" << endl; }
};
void main(){
	Brother bro("ZX", 'M', "ZF", 'M', "FQ", 'M', "Bro", 'M');
	Sister  sis("ZX", 'M', "ZF", 'M', "FQ", 'M', "Sis", 'F');
	Me me("ZX", 'M', "ZF", 'M', "FQ", 'M', "Me", 'M', bro, sis);
	me.displayMe();
}