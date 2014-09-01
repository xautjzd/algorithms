#include <stdio.h>
#include <string.h>

int lcsubstr(char *a, char *b, int m, int n);
int max(int a, int b);

int main(int argc, char **argv)
{
	char p1[] = "abcdefg";
	char p2[] = "macdefh";

	int result = lcsubstr(p1, p2, strlen(p1), strlen(p2));
	printf("%d\n", result);
	return 0;
}

/**
 * Function: get the largest common length of substring between string a and string b,
 * the length of string a is m, the length of string b is n.
 * */
int lcsubstr(char *a, char *b, int m, int n)
{
	int lcsuffix[m+1][n+1]; // store lengths of longest suffixes of substrings.
	int result = 0;        // store length of the longest common substring

	for (int i = 0; i <= m; i++) {
		for (int j =0; j <= n; j++) {
			if (i == 0 | j == 0)
				lcsuffix[i][j] = 0;
			else if (a[i] == b[j]) {
				lcsuffix[i][j] = lcsuffix[i-1][j-1] + 1;
				result = max(result, lcsuffix[i][j]);
			}
			else
				lcsuffix[i][j] = 0;
		}
	}
	return result;
}

int max(int a, int b)
{
	return (a > b)? a : b;
}
