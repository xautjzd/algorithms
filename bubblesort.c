#include <stdio.h>

void bubblesort(int a[], int length);
void optimized_bubblesort(int a[], int length);
void display(int a[], int length);

int main(int argc, char *argv[])
{
	int a[] = {11, 9, 13, 15, 7, 5, 12, 20, 18, 16};
	optimized_bubblesort(a, 10);
	display(a, 10);
	return 0;
}

/**
 * bubblesort: 冒泡排序
 * arguments: 
 * 	-a: 待排数组名
 * 	-length: 待排数组长度
 * */
void bubblesort(int a[], int length)
{
	int i, j, tmp, flag=1;    // flag用来标志一趟冒泡排序里是否发生交换，若交换过，则置1;否则置0.
	int n = length;

	for (i = 0; flag && i < n-1; i++) {
		flag = 0;
		for (j = 0; j < n-i; j++) 
			if (a[j] > a[j+1]) {
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
				flag = 1;
			}
	}
}

/**
 * optimized_bubblesort: 记录下每趟最后一次交换的位置，此位置之后的数据已经有序，无须比较
 * */
void optimized_bubblesort(int a[], int length)
{
	int i, j, k, tmp, flag= length;
	int n = length;

	for (i = 0; flag && i < n-1; i++) {
		k = flag;
		flag = 0;
		for (j = 0; j < k; j++)
			if (a[j] > a[j+1]) {
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
				flag = j;
			}
	}
}


/**
 * display: 打印排序后的数组内容
 * */
void display(int a[], int length)
{

	int i;
	for (i = 0; i < length; i++)
		printf("%d ", a[i]);
	printf("\n");
}
