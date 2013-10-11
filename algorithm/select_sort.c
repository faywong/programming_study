/**
 * Copyright (C) faywong<philip584521@gmail.com>
 * Date: 2013-10-11
 */
 
#include "common.h"

void select_sort(int a[], int len)
{
	int i, j, k;
	for (i = 0; i < len; i++) {
		int min_v = a[i], min_i = i;
		for (k = i; k < len; k++) {
			if (min_v > a[k]) {
				min_v = a[k];
				min_i = k;
			}
		}
		swap(a, min_i, i);
	}
}

int main(void)
{
	int a[] = { 17, 22, 13, -34, 0, 15, 47637, 23, -45 };
	const int len = sizeof(a) / sizeof(a[0]);
	dump(a, len, "before select sort, array:");
	select_sort(a, len);
	dump(a, len, "after select sort, array:");
	return 0;
}