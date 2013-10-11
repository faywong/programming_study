/**
 * Copyright (C) faywong<philip584521@gmail.com>
 * Date: 2013-10-11
 */
#include <stdio.h>

#include "common.h"

void minheap_fix_down(int a[], int i, int n);
void make_minheap(int a[], int len);

void heap_sort(int a[], int len)
{
	int i;
	for (i = len - 1; i > 0; i--) {
		swap(a, i, 0);
		minheap_fix_down(a, 0, i);
	}
}

void make_minheap(int a[], int len)
{
	int i;
	// index of last node: len - 1
	// index of its parent node: (len - 2) / 2
	for (i = (len - 2) / 2; i >= 0; i--) {
		minheap_fix_down(a, i, len);
	}
}

/**
 * @param a target array
 * @param i index of start node to be fixed
 * @param n number of nodes
 */
void minheap_fix_down(int a[], int i, int n)
{
	int j, tmp;
	tmp = a[i];
	j = 2 * i + 1;
	while (j < n) {
		if (j + 1 < n && a[j + 1] < a[j]) {
			j++;
		}
		
		if (a[j] >= tmp) {
			break;
		}
		
		a[i] = a[j];
		i = j;
		j = i * 2 + 1;
	}
	a[i] = tmp;
}

int main(void)
{
	int a[] = { 17, 22, 13, -34, 0, 15, 47637, 23, -45 };
	const int len = sizeof(a) / sizeof(a[0]);
	dump(a, len, "before heap sort, array:");
	make_minheap(a, len);
	heap_sort(a, len);
	dump(a, len, "after heap sort, array:");
	return 0;
}