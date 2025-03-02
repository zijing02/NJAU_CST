//时间复杂度：O(n)
//空间复杂度：O(1)
//稳定性：不稳定
#include"sort.h"
void swap(int* a, int* b, double& cnt2) {
    int temp = *b; *b = *a;  *a = temp;
    cnt2++;
}
void heapify(int* array, int start, int end, double& cnt1, double& cnt2) {  //建立父节点指标和子节点指标
    int dad = start;    int son = dad * 2 + 1;
    while (son <= end) {                                                        //若子节点指标在范围内才做比较
        if (++cnt1 && son + 1 <= end && array[son] < array[son + 1])            //先比较两个子节点大小，选择最大的
            son++;
        if (++cnt1 && array[dad] > array[son])                                  //如果父节点大于子节点代表调整完毕，直接跳出函数
            return;
        else {                                                                  //否则交换父子内容再继续子节点和孙节点比较
            swap(&array[dad], &array[son], cnt2);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}
void heap_sort(int* array, int num, double& cnt1, double& cnt2) {
    int i;   
    for (i = num / 2 - 1; i >= 0; i--)                                           //初始化，i从最后一个父节点开始调整
        heapify(array, i, num - 1, cnt1, cnt2);
    
    for (i = num - 1; i > 0; i--) {                                             //先将第一个元素和已排好元素前一位做交换，再从新调整，直到排序完毕
        swap(&array[0], &array[i], cnt2);
        heapify(array, 0, i - 1, cnt1, cnt2);
    }
}


