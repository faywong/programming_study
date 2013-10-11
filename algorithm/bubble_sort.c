/**
 * Copyright (C) faywong<philip584521@gmail.com>
 * Date: 2013-10-10
 */

#include "common.h"

void bubble_sort(int a[], int len)
{
	int i, j;
	for  (i = 0; i < len - 1; i++) {
		for (j = len - 2; j >= i; j--) {
			if (a[j] > a[ j + 1]) {
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

int main(void)
{
	int a[] = { 56, 12, 25, 53, -1, 88, 891 };
	const int len = sizeof(a) / sizeof(a[0]);
	dump(a, len, "before bubble sort, array:");
	bubble_sort(a, len);
	dump(a, len, "after bubble sort, array:");
	return 0;
}