#include <stdio.h>

void heapsort(int a[], int array_size);
void adjust(int a[], int root, int n);
void display(int a[], int array_size);

int main(int argc, char *argv[])
{
	int a[] = {26, 5, 33, 77, 1, 61, 11, 59, 15, 48, 19, 22};
	heapsort(a, 11);
	display(a, 12);
	return 0;
}

/* n: the array_size - 1 */
void heapsort(int a[], int n)
{
	int i, tmp;
	/* build the heap */
	for (i = n/2 - 1; i >= 0; i--)
		adjust(a, i, n);

	/* swap the last record with root, and adjust the heap */
	for (i = n; i >=1; i--) {
		tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;

		adjust(a, 0, i-1);
		/* display(a, array_size); */
	}
}

/**
 * Function: ajust the binary tree to establish the heap
 * Arguments:
 * 	- a: the address of array
 * 	- n: the array_size - 1 
 * */
void adjust(int a[], int root, int n)
{
	int maxchild, tmp;

	/* perform a heap sort on a[0..array_size] */
	while ((2 * root + 1) <= n) {
		maxchild = 2 * root + 1;          // left child

		if (maxchild < n && a[maxchild] < a[maxchild + 1]) // if have left child and right child, and the right is greater than left
			maxchild++; 	              // right child

		if (a[root] > a[maxchild]) 
			break;
		else {
			tmp = a[root];
			a[root] = a[maxchild];
			a[maxchild] = tmp;

			root = maxchild;
		}
	}
}

void display(int a[], int array_size)
{
	int i;
	for (i = 0; i < array_size; i++)
		printf("%d ", a[i]);

	printf("\n");
}
