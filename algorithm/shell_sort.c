/**
 * Copyright (C) faywong<philip584521@gmail.com>
 * Date: 2013-10-11
 */
 
#include "common.h"

void shell_sort(int a[], int len)
{
	int i, j, k, p, gap;
	for (gap = len / 2; gap > 0; gap = gap / 2)
	{
		for (i = 0; i < gap; i++) {
			for (j = i + gap; j < len; j += gap) {
				for (p = i; p < j; p += gap) {
					if (a[p] > a[j]) {
						int tmp = a[j];
						for (k = j; k > p; k -= gap) {
							a[k] = a[k - gap];
						}
						a[k] = tmp;
					}
				}
			}
		}
	}
}

int main(void)
{
	int a[] = { 5, 26, 1, -1, 0, 15, 256, 12, -245 };
	const int len = sizeof(a) / sizeof(a[0]);
	dump(a, len, "before shell sort, array:");
	shell_sort(a, len);
	dump(a, len, "after shell sort, array:");
	return 0;
}