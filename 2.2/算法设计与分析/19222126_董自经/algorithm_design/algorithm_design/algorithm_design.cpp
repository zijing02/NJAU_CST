#include"total.h"
int main() {
	char c = 'y'; int i = 0;
	while (c == 'y' || c == 'Y') {
		cout << "which problem do you want to choose(1 2 3)?    "; 	cin >> i;
	p1:	if (i == 1)		problem_1();
		else if (i == 2)		problem_2();
		else if (i == 3)		problem_3();
		else {
			cout << "wrong number,input again please: ";
			cin >> i;
			c = 'y';
			goto p1;
		}
		cout << "do you want to start again?(y/n)      "; cin >> c;
	}
}