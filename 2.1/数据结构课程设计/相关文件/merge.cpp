//时间复杂度：O(nlog2n)
//空间复杂度：O(n)
//稳定性：稳定
//此处的cnt2包含了将原数组中的元素送入新数组中
#include"sort.h"
void merge(int* input, int* output, int start, int mid, int end, double& cnt1, double& cnt2) {
    int i = start, j = mid + 1, k = start;  // i第一块初始下标,j第二块初始下标,k充当合并块的下标 
    // 判断遍历两个分块结束
    while ((i <= mid) && (j <= end)) { // 第一块第 i 个值比第二块第 j 值小
        if (++cnt1 && input[i] <= input[j]) {
            output[k++] = input[i++]; // 把小的值存入第二个数组，即第一块第 i 个值
            cnt2++;
        }
        else {
            ++cnt1;
            output[k++] = input[j++]; // 小的值存入第二个数组，即第二块第 j 个值
            cnt2++;
        }
    }
    while (i <= mid) {    // 第一块没遍历完，而第二块遍历结束，说明第一块剩余值都大于第二块，直接把剩余第一块数据都存入第二个数组
        output[k++] = input[i++];
        cnt2++;
    }
    while (j <= end) {   // 第二块没遍历完，而第一块遍历结束，说明第二块剩余值都大于第一块，直接把剩余第二块数据都存入第二个数组
        output[k++] = input[j++];
        cnt2++;
    }
}
void merge_split(int* input, int* output, int gap, int num, double& cnt1, double& cnt2) {
    int i = 0;
    while (i + 2 * gap - 1 < num) {
        merge(input, output, i, i + gap - 1, i + 2 * gap - 1, cnt1, cnt2); // 归并分块排序
        i = i + 2 * gap;                                                   // 归并间隔，指向下一个分块的起始点
    }
    if ((i + gap - 1) < num - 1)
        merge(input, output, i, i + gap - 1, num - 1, cnt1, cnt2);
    else
        for (int j = i; j < num; j++)
            output[j] = input[j];
}
void merge_sort(int* a, int num, double& cnt1, double& cnt2) {
    int* b = (int*)malloc(sizeof(int) * num);
    int gap = 1;
    while (gap < num) {
        merge_split(a, b, gap, num, cnt1, cnt2); // 归并，结果在 b 中
        gap = 2 * gap;                      
        merge_split(b, a, gap, num, cnt1, cnt2); // 归并，结果在 a 中
        gap = 2 * gap;                    
    }
}



