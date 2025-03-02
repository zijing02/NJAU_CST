#include"sort.h"
void begin_sort(int* b, int num, int flag) {
	double cnt1, cnt2; int* a; a = (int*)malloc(sizeof(int) * num); char c;
	switch (flag) {
	case 1:for (int i = 0; i < num; i++)  a[i] = b[i]; bubble(a, num, cnt1, cnt2);
		cout << endl << "冒泡排序:" << "比较次数:" << cnt1 << " 交换次数:" << cnt2;		break;
	case 2:for (int i = 0; i < num; i++)  a[i] = b[i];	shell(a, num, cnt1, cnt2);
		cout << endl << "希尔排序:" << "比较次数:" << cnt1 << " 交换次数:" << cnt2;		break;
	case 3:for (int i = 0; i < num; i++)  a[i] = b[i]; cnt1 = 0; cnt2 = 0;	quick(a, 0, num - 1, cnt1, cnt2);
		cout << endl << "快速排序:" << "比较次数:" << cnt1 << " 交换次数:" << cnt2;		break;
	case 4:	for (int i = 0; i < num; i++)  a[i] = b[i]; cnt1 = 0; cnt2 = 0;	merge_sort(a, num, cnt1, cnt2);
		cout << endl << "二路归并:" << "比较次数:" << cnt1 << " 交换次数:" << cnt2;		break;
	case 5:	for (int i = 0; i < num; i++)  a[i] = b[i]; cnt1 = 0; cnt2 = 0;	heap_sort(a, num, cnt1, cnt2);
		cout << endl << "堆排序:" << "比较次数:" << cnt1 << " 交换次数:" << cnt2;		break;
	case 6:
		for (int i = 0; i < num; i++)  a[i] = b[i]; bubble(a, num, cnt1, cnt2);
		cout << endl << "冒泡排序:" << "比较次数:" << cnt1 << " 交换次数:" << cnt2;
		for (int i = 0; i < num; i++)  a[i] = b[i]; cnt1 = 0; cnt2 = 0;	quick(a, 0, num - 1, cnt1, cnt2);
		cout << endl << "快速排序:" << "比较次数:" << cnt1 << " 交换次数:" << cnt2;
		for (int i = 0; i < num; i++)  a[i] = b[i];	shell(a, num, cnt1, cnt2);
		cout << endl << "希尔排序:" << "比较次数:" << cnt1 << " 交换次数:" << cnt2;
		for (int i = 0; i < num; i++)  a[i] = b[i]; cnt1 = 0; cnt2 = 0;	merge_sort(a, num, cnt1, cnt2);
		cout << endl << "二路归并:" << "比较次数:" << cnt1 << " 交换次数:" << cnt2;
		for (int i = 0; i < num; i++)  a[i] = b[i]; cnt1 = 0; cnt2 = 0;	heap_sort(a, num, cnt1, cnt2);
		cout << endl << "堆排序:" << "比较次数:" << cnt1 << " 交换次数:" << cnt2;     break;
	default:cout << "错误的数字"; break;
	}
	cout << endl << "是否打印数组(y/n)："; cin >> c;
	if (c == 'y') {
		cout << endl; for (int i = 0; i < num; i++) cout << a[i] << " "; cout << endl;
	}
}