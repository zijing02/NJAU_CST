#include"sort.h"
void begin_sort(int* b, int num, int flag) {
	double cnt1, cnt2; int* a; a = (int*)malloc(sizeof(int) * num); char c; double start, end;
	switch (flag) {
	case 1:for (int i = 0; i < num; i++)  a[i] = b[i]; start = clock(); bubble(a, num, cnt1, cnt2); end = clock(); 
		cout << "冒泡排序:" << "比较次数:" << cnt1 << " 交换次数:" << cnt2 << " 耗费时间：" << end - start << "ms";		break;
	case 2:for (int i = 0; i < num; i++)  a[i] = b[i];	start = clock(); shell(a, num, cnt1, cnt2); end = clock();
		cout << "希尔排序:" << "比较次数:" << cnt1 << " 交换次数:" << cnt2 << " 耗费时间：" << end - start << "ms";		break;
	case 3:for (int i = 0; i < num; i++)  a[i] = b[i]; cnt1 = 0; cnt2 = 0;	start = clock(); quick(a, 0, num - 1, cnt1, cnt2); end = clock();
		cout << "快速排序:" << "比较次数:" << cnt1 << " 交换次数:" << cnt2 << " 耗费时间：" << end - start << "ms";		break;
	case 4:for (int i = 0; i < num; i++)  a[i] = b[i]; cnt1 = 0; cnt2 = 0; start = clock();	merge_sort(a, num, cnt1, cnt2); end = clock();
		cout << "二路归并:" << "比较次数:" << cnt1 << " 交换次数:" << cnt2 << " 耗费时间：" << end - start << "ms";		break;
	case 5:for (int i = 0; i < num; i++)  a[i] = b[i]; cnt1 = 0; cnt2 = 0;	start = clock(); heap_sort(a, num, cnt1, cnt2); end = clock();
		cout << "堆排序:" << "比较次数:" << cnt1 << " 交换次数:" << cnt2 << " 耗费时间：" << end - start << "ms";		break;
	case 6:
		for (int i = 0; i < num; i++)  a[i] = b[i]; start = clock(); bubble(a, num, cnt1, cnt2); end = clock();
		cout << "冒泡排序:" << "比较次数:" << cnt1 << " 交换次数:" << cnt2 << " 耗费时间：" << end - start << "ms"; 
		for (int i = 0; i < num; i++)  a[i] = b[i];	start = clock(); shell(a, num, cnt1, cnt2); end = clock();
		cout << endl << "希尔排序:" << "比较次数:" << cnt1 << " 交换次数:" << cnt2 << " 耗费时间：" << end - start << "ms";
		for(int i = 0; i < num; i++)  a[i] = b[i]; cnt1 = 0; cnt2 = 0;	start = clock(); quick(a, 0, num - 1, cnt1, cnt2); end = clock();
		cout << endl << "快速排序:" << "比较次数:" << cnt1 << " 交换次数:" << cnt2 << " 耗费时间：" << end - start << "ms"; 
		for (int i = 0; i < num; i++)  a[i] = b[i]; cnt1 = 0; cnt2 = 0; start = clock();	merge_sort(a, num, cnt1, cnt2); end = clock();
		cout << endl << "二路归并:" << "比较次数:" << cnt1 << " 交换次数:" << cnt2 << " 耗费时间：" << end - start << "ms";
		for (int i = 0; i < num; i++)  a[i] = b[i]; cnt1 = 0; cnt2 = 0;	start = clock(); heap_sort(a, num, cnt1, cnt2); end = clock();
		cout << endl << "堆排序:" << "比较次数:" << cnt1 << " 交换次数:" << cnt2 << " 耗费时间：" << end - start << "ms";		break;
	default:cout << "错误的数字"; break;
	}
	cout << endl << "是否打印数组(y/n)："; cin >> c;
	if (c == 'y') {
		cout << endl; for (int i = 0; i < num; i++) cout << a[i] << " "; cout << endl;
	}
}