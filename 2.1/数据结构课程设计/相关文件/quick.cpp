//时间复杂度：O(nlog2n) 平均时间复杂度为：O(nlog2n)
//由于快速排序用到了递归调用，因此计算其时间复杂度也需要用到递归算法计算
//递归算法的时间复杂度公式：T[n] = aT[n / b] + f(n)
//最优情况下时间复杂度
//快速排序最优的情况就是每一次取到的元素都刚好平分整个数组
//此时的时间复杂度公式则为：T[n] = 2T[n / 2] + f(n)；T[n / 2]为平分后的子数组的时间复杂度，f[n] 为平分这个数组时所花的时间
//第一次递归：
//T[n] = 2T[n / 2] + n;
//第二次递归:
//令 n = n / 2
//= 2 ^ 2 T[n / (2 ^ 2)] + 2n
//第三次递归 :
//令：n = n / (2 ^ 2)
//= 2 ^ 3 T[n / (2 ^ 3)] + 3n
//…
//第m次递归 :
//令：n = n / (2 ^ (m - 1))
//= 2 ^ m T[1] + mn
//当最后平分的不能再平分时，也就是说把公式一直往下跌倒，到最后得到T[1]时，说明这个公式已经迭代完了（T[1]是常量了）。
//得到：T[n / (2 ^ m)] = T[1] == = >> n = 2 ^ m ====> > m = logn；
//T[n] = 2 ^ m T[1] + mn ；其中m = logn;
//T[n] = 2 ^ (logn)T[1] + lognn = n + nlogn
//又因为当n >= 2时：nlogn >= n(也就是logn > 1)，所以取后面的 nlogn；
//快速排序最优的情况下时间复杂度为：O(nlogn)
//
//最差情况下时间复杂度
//最差的情况就是每一次取到的元素就是数组中最小 / 最大的，这种情况其实就是冒泡排序了(每一次都排好一个元素的顺序)
//此时的时间复杂度为:T[n] = n * (n - 1) = n ^ 2 + n;
//快速排序最差的情况下时间复杂度为：O(n ^ 2)

//空间复杂度：O(n) 空间复杂度：logn 主要是由于递归造成的栈空间的使用，最好的情况下其树的深度为：log2(n) 空间复杂度为 O(logn)而最坏的情况下:需要n - 1次调用，每2个数都需要交换，此时退化为冒泡排序 空间复杂度为 O(n)
//稳定性：一般不稳定
#include"sort.h"
void quick(int* a, int left, int right, double& cnt1, double& cnt2){
	int i, j, temp;
	if (left > right) return;
	temp = a[left]; i = left; j = right;					
	while (i != j) {
		while (a[j] >= temp && i < j) {	
			j--;
			cnt1++;
		}
		while (a[i] <= temp && i < j) {
			i++;
			cnt1++;
		}
		if (i < j) {
			cnt2++;
			a[j] = a[i] + a[j];
			a[i] = a[j] - a[i];
			a[j] = a[j] - a[i];
		}
	}
	a[left] = a[i];									//基准数归位
	a[i] = temp;
	cnt2 += 2;
	cnt2++;	
	quick(a, left, i - 1, cnt1, cnt2);								
	quick(a, i + 1, right, cnt1, cnt2);
}
