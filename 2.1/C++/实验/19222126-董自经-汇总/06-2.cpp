#include<iostream>
#include<cstdio>
using namespace std;
class LinkList{
public:
	float* List;
	int max, num;
	void create();
	void add(float x);
	void output();
	LinkList(int n = 10) { 
		List = new float[n];
		max = n; num = 0;
	}
};
void LinkList::create() {
	int t;
	cout << "输入链表的元素个数："; cin >> t;
	cout << endl << "输入链表元素：";
	for (int i = 0; i < t; i++)
		cin >> List[i];
	num = t;
	cout << endl;
}
void LinkList::add(float x) {
	if (num < max)
		List[num++] = x;
	else{
		float* NewList = new float[max + 5];
		for (int i = 0; i < num; i++) 
			NewList[i] = List[i];
		delete List;
		max += 5;
		List = NewList;
		List[num++] = x;
	}
}
void LinkList::output() {
	cout << endl;
	for (int i = 0; i < num; i++) 
		cout << List[i] << " ";
	cout << endl;
}
int main(){
	LinkList L; float x;
	L.create();
	cout << "输入要插入的数字:"; cin >> x;	L.add(x);
	L.output();
	return 0;
}