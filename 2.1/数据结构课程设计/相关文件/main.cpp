#include"sort.h"
int main() {
	/*
	FILE* fp = NULL;
	int  a[10] = { 0 }, b[10] = { 0 };
	fp = fopen("D:\sort.txt", "w+");
	for (int i = 0; i < 10; i++) 
		a[i] = i;
	for (int i = 0; i < 10; i++) 
		fprintf(fp, "%d\n", a[i]);
	fclose(fp);
	fp = fopen("D:\sort.txt", "r");
	for (int i = 0; i < 10; i++) 
		fscanf_s(fp, "%d", &b[i]);
	fclose(fp);
	for (int i = 0; i < 10; i++) 
		cout << b[i] << " ";
	*/ 
	/*
	int num;
	cout << "输入需要排序数字数目:"; cin >> num;
	int* a, * b;
	a = (int*)malloc(sizeof(int) * num); b = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++) a[i] = rand();
	FILE* fp = fopen("D:\sort.txt","w+");
	for (int i = 0; i < num; i++) fprintf(fp, "%d\t", a[i]);		//将a[i]写入文件
	fclose(fp);
	fp = fopen("D:\sort.txt", "r");
	for (int i = 0; i < num; i++)  fscanf_s(fp, "%d", &b[i]);		//读取文件内容到b[i]
	fclose(fp);
	for (int i = 0; i < num; i++) cout << b[i] << " ";
	*/
	/*
	//将1000/10000/100000个数据写入文件备用
	for (int i = 0; i < num; i++) a[i] = rand();
	if (num == 1000) {
		fp = fopen("D:\sort_1000.txt", "w+");
		for (int i = 0; i < num; i++) fprintf(fp, "%d ", a[i]);		//将a[i]写入文件
		fclose(fp);
	}
	else if (num == 10000) {
		fp = fopen("D:\sort_10000.txt", "w+");
		for (int i = 0; i < num; i++) fprintf(fp, "%d ", a[i]);		//将a[i]写入文件
		fclose(fp);
	}
	else {
		fp = fopen("D:\sort_100000.txt", "w+");
		for (int i = 0; i < num; i++) fprintf(fp, "%d ", a[i]);		//将a[i]写入文件
		fclose(fp);
	}
	*/
	int num, flag; FILE* fp;
	cout << "输入要排序的数字数量（0/500/1000/10000/100000）:"; cin >> num;
	while (num) {
		cout << "选择排序方式：0.退出排序 1.冒泡排序 2.希尔排序 3.快速排序 4.二路归并 5.堆排序 6.以上全部排序方式" << endl; cin >> flag;
		int* b; b = (int*)malloc(sizeof(int) * num);  srand((unsigned int)time(NULL));	void Fopen(int, int, FILE * fp, int* b);
		if (flag) {
			if (num == 500) {						//基础，三组随机的500个数据
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < num; j++)	b[j] = rand();
					if (i)		cout << "选择排序方式：0.退出排序 1.冒泡排序 2.希尔排序 3.快速排序 4.二路归并 5.堆排序 6.以上全部排序方式" << endl, cin >> flag;
					cout << "第" << i + 1 << "次，共3次";
					begin_sort(b, num, flag);
				}
			}
			else if (num == 1000) 
				fp = fopen("D:\sort_1000.txt", "r"), Fopen(num, flag, fp, b);
			else if (num == 10000) 
				fp = fopen("D:\sort_10000.txt", "r"), Fopen(num, flag, fp, b);
			else if (num == 100000) 
				fp = fopen("D:\sort_100000.txt", "r"), Fopen(num, flag, fp, b);
		}
		else exit(0);
		cout << "输入要排序的数字数量（0/500/1000/10000/100000）:"; cin >> num;
	}
	return 0;
}
void Fopen(int num, int flag, FILE* fp, int* b) {
	for (int i = 0; i < num; i++)
		fscanf_s(fp, "%d", &b[i]);		//读取文件内容到b[i]
	fclose(fp);
	begin_sort(b, num, flag);
}