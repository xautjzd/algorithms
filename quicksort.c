#include <stdio.h>

static void quicksort(int a[], int left, int right);
static void swap(int *p, int *q);
static void display(int a[], int length);

int main(int argc, char *argv[])
{
	int a[] = {44, 22, 20, 15, 15, 13, 11, 10};
	quicksort(a, 0, 7);
	display(a, 7);

	return 0;
}

static void quicksort(int a[], int left, int right) 
{

	/* the elements of array a is more than 1 */
	if (left < right) {
		int i = left, j = right, pivot = a[left];

		while (i < j) {

			/* 两个while循环不能交换，必须j--在前，i++在后 */
			while (i < j && pivot < a[j])      // 从右向左找第一个小于等于pivot的数
				j--;

			while ( i < j && pivot >= a[i])   // 从左向右找第一个大于pivot的数
				i++;

			if (i < j)
				swap(&a[i], &a[j]);
		}
		swap(&a[left], &a[i]);
		quicksort(a, left, i-1);
		quicksort(a, i+1, right);
	}
} 

void another_quicksort(int a[], int left, int right)
{
	/* the elements of array a is more than 1 */
	if (left < right) {
		int i = left, j = right, pivot = a[left];
		while (i < j) {

			/* 两个while循环不能交换，必须j--在前，i++在后 */
			while (i < j && pivot < a[j])     // 从右向左找第一个小于等于pivot的数
				j--;
			if (i < j)
				a[i++] = a[j];

			while (i < j && pivot > a[i])     // 从左向右找第一个大于pivot的数
				i++;
			if (i < j)
				a[j--] = a[i];
		}
		a[i] = pivot;
		quicksort(a, left, i-1);
		quicksort(a, i+1, right);
	}
	
}

static void swap(int *p, int *q) 
{
	int tmp;
	tmp = *p;
	*p = *q;
	*q = tmp;
}

static void display(int a[], int length) 
{
	int i = 0;
	for (; i <= length; i++)
		printf("%d ", a[i]);
	printf("\n");
}
