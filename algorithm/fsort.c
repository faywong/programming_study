/**
 * Copyright (C) faywong<philip584521@gmail.com>
 * Date: 2013-10-10
 */

#include <stdio.h>

int partition(int array[], int a, int b)
{
	printf("%s in, a = %d, b = %d\n", __FUNCTION__, a, b);
	int x = array[b];
	int i = a - 1;
	int j;
	for (j = a; j < b; j++) {
		if (array[j] <= x) {
			i++;
			swap(array, i, j);
		}
	}
	swap(array, i + 1, b);
	return i + 1;
}

int fsort(int array[], int a, int b) 
{
	printf("%s in, a = %d, b = %d\n", __FUNCTION__, a, b);
	if (a < b) {
		int n = partition(array, a, b);
		printf("middle %d\n", n);
		fsort(array, a, n - 1);
		fsort(array, n + 1, b);
	} else {
		return;
	}
}

int main(void)
{
	int a[] = { 2, 4, 1, 0, 7, 9, -1, -3};
	int length = sizeof(a) / sizeof(a[0]);
	dump(a, length, "before fsort, array:");
	fsort(a, 0, length -1);
	dump(a, length, "after fsort, array:");
	return 0;
}