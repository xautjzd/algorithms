#include <stdio.h>

void print_vertical(int num);

int main(int argc, char **argv)
{
	int a=1234;
	print_vertical(a);
	return 0;
}

void print_vertical(int num)
{
	if (num < 10)
		printf("%d\n", num);
	else {
		print_vertical(num/10);
		printf("%d\n", num%10);
	}
}
