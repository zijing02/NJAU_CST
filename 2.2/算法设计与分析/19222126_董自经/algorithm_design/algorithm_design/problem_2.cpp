#include"total.h"
string shortestCommonSupersequence(string str1, string str2) {
    int n = str1.size(), m = str2.size(), t1 = 0, t2 = 0;   string str; 
    int** dp = new int* [n + 1];
    for (int i = 0; i <= n; ++i) 
        dp[i] = new int[m + 1];
    for (int i = 0; i <= n; ++i) 
        dp[i][m] = n - i;
    for (int i = 0; i <= m; ++i) 
        dp[n][i] = m - i;
    for (int i = n - 1; i >= 0; --i)
        for (int j = m - 1; j >= 0; --j)
            if (str1[i] == str2[j])  
                dp[i][j] = dp[i + 1][j + 1] + 1;
            else  
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + 1;
    while (t1 < n && t2 < m) {
        if (str1[t1] == str2[t2]) 
            str += str1[t1],
            ++t1,++t2;
        else if (dp[t1][t2] == dp[t1 + 1][t2] + 1) 
            str += str1[t1],
            ++t1;
        else if (dp[t1][t2] = dp[t1][t2 + 1] + 1) 
            str += str2[t2],
            ++t2;
    }
    if (t1 < n)
        str += str1.substr(t1);
    else if (t2 < m)
        str += str2.substr(t2);
    cout << "the dp array is as follow:" << endl;
    for (int i = n; i >= 0; i--) {
        if (n - i >= 1)  cout << str1[n - i - 1] << " ";
        else {
            cout << "    ";
            for (int j = 0; j < m; j++) cout << str2[j] << " ";
            cout << endl << "  ";
        }
        for (int j = m; j >=0; j--) 
            cout  << dp[i][j] << " ";
        cout << endl;
    }
    return str;
}
void problem_2() {
    //A 65 Z 90 a 97 z 122
    srand((int)time(NULL));
    string str1, str2; char c = 'y', flag = 'y'; int t1 = 0, t2 = 0, t3 = 0, t;
    while (c == 'y' || c == 'Y') {
        cout << "do you want to input the two strings yourself?" << endl
            << "if so, you need to input two arbitrary strings,else please give the length of the two strings" << endl
            << "press y to inupt strings yourself,press n to give the length of the two strings:   ";
        cin >> flag;
        if (flag == 'y' || flag == 'Y')
            cout << "input the first string: ", cin >> str1,
            cout << "input the second string: ", cin >> str2;
        else {
            cout << "input the first length: "; cin >> t1;
            cout << "input the second length: "; cin >> t2;
            for (int i = 0; i < t1; i++) {
                t3 = rand() % 2;    //0->upper 1->lower
                if (t3) t = rand() % 26 + 97;
                else t = rand() % 26 + 65;
                str1 += t;
            }
            for (int i = 0; i < t2; i++) {
                t3 = rand() % 2;    
                if (t3) t = rand() % 26 + 97;
                else t = rand() % 26 + 65;
                str2 += t;
            }
            cout << "str1:\"" << str1 << "\"" << endl << "str2:\"" << str2 << "\"" << endl;
        }
        string result = shortestCommonSupersequence(str1,str2);
        cout << "the length of the shortest common supersequence is: " << result.size() << endl
            << "the shortest common supersequence is:\"" << result << "\"" << endl
            << "whether to start problrm_2 again?(y/n)   ";
        cin >> c; str1 = str2 = "";
    }
}
