#include<iostream>
#include<cstdio>
using namespace std;
int main() {
    int d1, d2, i, j, n; char c = 'y'; cin >> d1 >> d2;
    int** a;
    n = d1 > d2 ? d1: d2;
    a = (int**)malloc(sizeof(int*) * n);
    for (i = 0; i < d1; i++)
        *(a + i) = (int*)malloc(sizeof(int) * n);
    if (a == NULL)
        cout << "分配失败\n";
    while (c == 'y') {
        cout << "输入数组：" << "\n";
        for (i = 0; i < d1; i++)
            for (j = 0; j < d2; j++)
                cin >> a[i][j];
        cout << "原数组:" << "\n";
        for (i = 0; i < d1; i++) {
            for (j = 0; j < d2; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
        cout << "转置后的数组:" << "\n";
        for (i = 0; i < d2; i++) {
            for (j = 0; j < d1; j++)
                cout << a[j][i] << " ";
            cout << endl;
        }
        cout << "还要继续吗（y/n）";
        cin >> c;
    }
    return 0;
}