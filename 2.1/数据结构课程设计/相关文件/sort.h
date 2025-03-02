/*内部排序算法的实现与比较
【问题描述】
从冒泡排序、希尔排序、折半插入排序、二路归并排序、堆排序、选择排序、快速排序、基数排序等排序方法中选用 5 种，实现数据的排序。
【基本要求】
对随机生成的 3 组 500 个待排整数进行排序，并从关键字的比较次数和关键字的移动次数来对选用的算法进行比较分析。
【选作内容】
随机产生 3 组数据，分别有 1000、10000、100000 个待排整数，存入文件，从文件读入待排数据进行排序，统计每种算法的执行时间，并进行分析比较
*/

#include"iostream"
#include"stdlib.h"
#include"time.h"
using namespace std;
//cnt1为比较次数,cnt2为交换次数
void begin_sort(int* b, int num, int flag);
void bubble(int* a, int num, double& cnt1, double& cnt2);
void heap_sort(int* array, int num, double& cnt1, double& cnt2);
void merge_sort(int* a, int num, double& cnt1, double& cnt2);
void quick(int* a, int left, int right, double& cnt1, double& cnt2);
void shell(int* a, int num, double& cnt1, double& cnt2);



