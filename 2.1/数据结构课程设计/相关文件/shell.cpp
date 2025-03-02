//时间复杂度：平均时间复杂度：O(Nlog2N) 最佳时间复杂度：O(nlog2n) 最差时间复杂度：O(N ^ 2)
//空间复杂度：O(1)
//稳定性：不稳定
//特殊的直接插入排序，只是比较宽度变为gap
#include"sort.h"
void shell(int* a, int num, double& cnt1, double& cnt2){
    int i, j, t, gap, temp; cnt1 = 0; cnt2 = 0;
    for (gap = num / 2; gap > 0; gap /= 2) {        // 步长初始化为数组长度的一半，每次遍历后步长减半,
        for (i = 0; i < gap; ++i) {                 // 变量 i 为每次分组的第一个元素下标 
            for (j = i + gap; j < num; j += gap) { 
                temp = a[j];                        
                t = j - gap;                        
                while (cnt1++ && t >= 0 && a[t] > temp) {
                    cnt2++;
                    a[t + gap] = a[t];             
                    a[t] = temp;
                    t -= gap;
                }
            }
        }
    }
}