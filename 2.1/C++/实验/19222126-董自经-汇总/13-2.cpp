#include<iostream>
#include<math.h>
using namespace std;
const int N = 5;
template <class T>
T Max(T value[], int size) {
	T max = value[0];
	for (int i = 0; i < size; i++) 
		max = max > value[i] ? max : value[i];
	return max;
}
void main() {
	int i, arr[N];
	double dou[N];
	for (i = 0; i < N; i++) {
		arr[i] = (i + 1) * 2;
		cout << arr[i] << "\t";
	}
	cout << endl << "最大值为" << Max(arr, N) << endl;
	for (i = 0; i < N; i++) {
		dou[i] = (i + 1) + sqrt(i + 1);
		cout << dou[i] << "\t";
	}
	cout << endl << "最大值为" << Max(dou, N) << endl;
}
