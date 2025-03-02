#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main() {
	//比较字符串
	adc abe bec bad cde    ->    abe adc bad bec cde
	char t[5][10]; char s[10];
	for (int i = 0; i < 5; i++) 
		cin >> t[i];
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4 - j; i++) {
			if (strcmp(t[i], t[i + 1]) > 0) {
				strcpy(s, t[i]);
				strcpy(t[i], t[i + 1]);
				strcpy(t[i + 1], s);
			}
		}
	}
	for (int i = 0; i < 5; i++)
		cout << t[i] << "\n";
	
	return 0;
}



















