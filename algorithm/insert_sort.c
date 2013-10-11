/**
 * Copyright (C) faywong<philip584521@gmail.com>
 * Date: 2013-10-11
 */
 
#include "common.h"

void insert_sort(int a[], int len)
{
	int i, j, k;
	// i --> index of target element to be inserted
	for (i = 1; i < len; i++) {
		for (j = 0; j <= i; j ++) {
			// first element larger than target to be inserted
			if (a[j] >= a[i]) {
				int tmp = a[i];
				for (k = i; k > j; k--) {
					a[k] = a[k - 1];
				}
				a[k] = tmp;
			}
		}
	}
}

int main(void)
{
	int a[] = { 63, 35, 56, 155, -1, -1456, 576 };
	const int len = sizeof(a) / sizeof(a[0]);
	dump(a, len, "before insert sort, array:");
	insert_sort(a, len);
	dump(a, len, "after insert sort, array:");
	return 0;
}