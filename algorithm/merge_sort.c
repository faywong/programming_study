/**
 * Copyright (C) faywong<philip584521@gmail.com>
 * Date: 2013-10-11
 */
#include <stdio.h>

#include "common.h"

void merge_array(int a[], int start, int middle, int end, int tmp[]);

void merge_sort(int a[], int start, int end, int tmp[])
{
#ifdef DEBUG
	printf("%s in, start:%d end:%d\n", __FUNCTION__, start, end);
#endif
	if (start < end) {
		int middle = (start + end) / 2;
		merge_sort(a, start, middle, tmp);
		merge_sort(a, middle + 1, end, tmp);
		merge_array(a, start, middle, end, tmp);
	}
}

void merge_array(int a[], int start, int middle, int end, int tmp[])
{
#ifdef DEBUG
	printf("%s in, start:%d middle:%d end:%d\n", __FUNCTION__, start, middle, end);
#endif
	int i = 0, no = end - start + 1, j = start, k = middle + 1;
	while (j <= middle && k <= end) {
		if (a[j] < a[k]) {
			tmp[i++] = a[j++];
		} else {
			tmp[i++] = a[k++];
		}
	}
	
	while (k <= end) {
		tmp[i++] = a[k++]; 
	}
	while (j <= middle) {
		tmp[i++] = a[j++];
	}
	
	j = 0;
#ifdef DEBUG
	printf("merge array result:\n");

	for (i = start; i <= end; i++) {
		a[i] = tmp[j++];
		printf("%d ", a[i]);
	}
	printf("\n");
#endif
}

int main(void)
{
	int a[] = { 17, 22, 13, -34, 0, 15, 47637, 23, -45 };
	const int len = sizeof(a) / sizeof(a[0]);
	dump(a, len, "before merge sort, array:");
	int tmp[len];
	merge_sort(a, 0, len - 1, tmp);
	dump(a, len, "after merge sort, array:");
	return 0;
}