13-1-1
#include<iostream>
using namespace std;
template<class T>
class tem {
	T* data;
	int size;
public:
	tem(int);
	~tem() { delete[]data; }
	T& operator[](int i) { return data[i]; }
};
template<class T>
tem<T>::tem(int n) {
	data = new T[n];
	size = n;
}
int main() {
	tem<int>x(5);
	for (int i = 0; i < 5; i++) {
		x[i] = i;
		cout << x[i] << " ";
	}
	cout << endl;
	return 0;
}
13-1-2
#include<iostream>
using namespace std;
template<class T>
class list {
public:
	list();
	void add(T&t) {
		node* temp = new node;
		temp->pt = &t;
		temp->next = pfirst;
		pfirst = temp;
	}
	void remove(T&);
	T* find(T&);
	void print();
	~list();
protected:
	struct node {
		node* next;
		T* pt;
	};
	node* pfirst;
};
template<class T>
list<T>::list() {
	pfirst = 0;
}
template<class T>
void list<T>::remove(T& t) {
	node* q = 0;
	if (*pfirst->pt == t) {
		q = pfirst;
		pfirst = pfirst->next;
	}
	else {
		for (node* p = pfirst; p->next; p = p->next) 
			if (*(p->next->pt) == t) {
				q = p->next;
				p->next = q->next;
				break;
			}
	}
	if (q) {
		delete q->pt;
		delete q;
	}
	else 
		cout << "没有该节点";
}
template<class T>
T* list<T>::find(T& t) {
	for (node* p = pfirst; p->next; p = p->next) {
		if (*(p->pt) == t)
			return p->pt;
	}
	return 0;

}
template<class T>
void list<T>::print(){
	for (node* p = pfirst; p->next; p = p->next)
		cout << *p->pt << "\t";
	cout << endl;
}
template<class T>
list<T>::~list() {
	node* p = pfirst;
	while (p) {
		pfirst = pfirst->next;
		delete p->pt;
		delete p;
		p = pfirst;
	}
}
int main() {
	list<float>fl;
	for (int i = 0; i < 7; i++) 
		fl.add(*new float(i + 0.3));
	fl.print();
	float b = 3.3;
	float* pa = fl.find(b);
	if (pa)
		fl.remove(*pa);
	fl.remove(*new float(2.3));
	fl.print();
	return 0;
}

