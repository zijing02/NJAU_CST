#include<iostream>
#include<cstdio>
using namespace std;
int main() {
    int d1, d2, i, j, n; char c = 'y'; cin >> d1 >> d2;
    int** a;
    a = (int**)malloc(sizeof(int*) * d1);
    for (i = 0; i < d1; i++)
        *(a + i) = (int*)malloc(sizeof(int) * d2);
    if (a == NULL)
        cout << "分配失败\n";
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
    while (c == 'y') {
        cout << "输入倍数:";    cin >> n;    cout << endl;
        cout << "加倍后的数组:" << "\n";
        for (i = 0; i < d1; i++) {
            for (j = 0; j < d2; j++)
                cout << a[i][j] * n << " ";
            cout << endl;
        }
        cout << "还要继续吗（y/n）";
        cin >> c;
    }
    return 0;
}