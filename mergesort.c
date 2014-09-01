#include <stdio.h>
#include <stdlib.h>

/**
 * merge_sort：进行归并排序
 * 参数: 
 * 		init[]: 存储待排数据
 * 		merged[]: 存储排好后的数据
 * 		array_size: 存储待排数据大小
 * */
void merge_sort(int init[], int merged[], int array_size);

/**
 * m_sort：将待排数组划分为多个子表进行排序
 * 参数:
 * 		init[]: 存储待排数据
 * 		merged[]: 存储排好后的数据
 * 		left: 表示归并子表的左起始点
 * 		right: 表示归并排序子表的右结束点
 * */
void m_sort(int init[], int merged[], int left, int right);

/**
 * merge: 将已经排序好的各子表归并得到最终排好的数组
 * 参数:
 * 		left: 归并子表起始点
 * 		right: 归并子表结束点
 * */
void merge(int init[], int merged[], int left, int mid, int right);

int main(int argc, char **argv)
{
	int a[] = {5, 6, 11, 3, 8, 7, 4, 9, 1, 10, 2};
	int b[11];
	merge_sort(a, b, 11);

	int i;
	for (i = 0; i < 11; i++)
		printf("%d ", b[i]);
	printf("\n");
	return 0;
}

void merge_sort(int init[], int merged[], int array_size)
{
	m_sort(init, merged, 0, array_size-1);
}

void m_sort(int init[], int merged[], int left, int right)
{
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		m_sort(init, merged, left, mid);               // 排序左子表
		m_sort(init, merged, mid + 1, right);         //  排序右子表

		merge(init, merged, left, mid, right);        // 归并操作
	}
}

void merge(int init[], int merged[], int left, int mid, int right)
{
	int i, j, k;
	i = left;
	j = mid + 1;
	k = i;
	int n = right - left;   

	while (i <= mid && j <= right) {
		if (init[i] < init[j])
			merged[k++] = init[i++];
		else
			merged[k++] = init[j++];
	}

	while (i <= mid)              // 将左子表中剩余的数据拷贝到merged数组
		merged[k++] = init[i++];
	while (j <= right)
		merged[k++] = init[j++]; // 将右子表中剩余的数据拷贝到merged数组

	while (n >= 0) {
		init[right] = merged[right];  // 将已排序好的子数组保存到原数组中
		right -= 1;
		n--;
	}
}
