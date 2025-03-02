#include <iostream>
#include <string>
using namespace std;
class Automobile;
class Park {
	int N, income, numAuto; Automobile** spaces;
public:
	Park(int N) {
		spaces = new Automobile * [N];
		for (int i = 0; i < N; i++)  spaces[i] = NULL;
		this->N = N;
		income = 0;
		numAuto = 0;
	}
	~Park() { delete[] spaces; }
	void showInfo();
	bool assignSpace(Automobile* pa);
	bool reclaimSpace(Automobile* pa, int fee);
};
class Automobile {
protected:
	string plateNO;
public:
	Automobile(string plateNO) :plateNO(plateNO) {};
	void enter(Park& park) { park.assignSpace(this); };
	void leave(Park& park) {};
	string getPlateNO() { return plateNO; };
};
class Truck : public Automobile {
protected:
	double capacity;
public:
	Truck(string plateNO, double capacity) :Automobile(plateNO), capacity(capacity) {}
	void leave(Park& park) { park.reclaimSpace(this, 3); };
};
class Bus : public Automobile {
protected:
	int numPassengers;
public:
	Bus(string plateNO, int numPassengers) :Automobile(plateNO), numPassengers(numPassengers) {}
	void leave(Park& park) { park.reclaimSpace(this, 2); };
};
class Car : public Automobile {
protected:
	string brand;
public:
	Car(string plateNO, string brand) : Automobile(plateNO), brand(brand) {}
	void leave(Park& park) { park.reclaimSpace(this, 1); };
};
void Park::showInfo() {
	if (numAuto == 0)
		cout << "停车场目前停放了" << numAuto << "辆汽车，共收入" << income << "元停车费!";
	else {
		cout << "停车场目前停放了" << numAuto << "辆汽车：";
		for (int i = 0; i < N; i++)
			if (spaces[i] != NULL)
				cout << spaces[i]->getPlateNO() << ",";
		cout << "共收入" << income << "元停车费!" << endl;
	}
}
bool Park::assignSpace(Automobile* pa) {
	for (int i = 0; i < N; i++) {
		if (spaces[i] == NULL) {
			spaces[i] = pa;
			numAuto++;
			cout << pa->getPlateNO() << "进入停车场，分配停车位!" << endl;
			return true;
		}
	}
	cout << "无法为" << pa->getPlateNO() << "分配停车位!" << endl;
	return false;
}
bool Park::reclaimSpace(Automobile* pa, int fee) {
	for (int i = 0; i < N; i++) {
		if (spaces[i] == pa) {
			spaces[i] = NULL;
			numAuto--;
			income += fee;
			cout << pa->getPlateNO() << "离开停车场，缴纳停车费" << fee << "元!" << endl;
			return true;
		}
	}
	cout << "停车场中没有车牌为" << pa->getPlateNO() << "的汽车!";
	return false;
}
void main() {
	int N = 0;
	cout << "请输入停车位数量：";
	cin >> N;                      //输入停车位数量，此处输入2
	Park park(N);                  //创建一个停车场对象
	Truck truck("苏A-01234", 20);   //创建卡车对象
	truck.enter(park);              //truck进入停车场，分配车位
	Car car1("苏A-56789", "Audi A8");      //创建轿车对象
	car1.enter(park);                   //car1进入停车场，分配停车位
	car1.leave(park);                   //car1离开停车场，缴纳停车费
	Bus bus("苏A-43210", 50);          //创建公交车对象
	bus.enter(park);                    //bus进入停车场，分配车位
	/*显示当前停放的车辆的车牌号码，以及当前的全部停车费收入*/
	park.showInfo();
	Car car2("苏A-98765", "Benz S400");   //创建轿车对象
	car2.enter(park);
	//car2进入停车场，分配停车位。因为没有空余停车位，所以无法分配
	bus.leave(park);                      //bus离开停车场，缴纳停车费
	truck.leave(park);                     //truck离开停车场，缴纳停车费
	/*显示当前停放的车辆的车牌号码，以及当前的全部停车费收入*/
	park.showInfo();
}