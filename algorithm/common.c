/**
 * Copyright (C) faywong<philip584521@gmail.com>
 * Date: 2013-10-10
 */

#include <stdio.h>

int swap(int array[], int a, int b) 
{
#ifdef DEBUG
	printf("swapping %d with %d\n", a, b);
#endif
	int tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}

void dump(int a[], int len, const char* prompt)
{
	int i;
	printf("\n%s\n", prompt);
	for (i = 0; i < len - 1; ++i) {
		printf("%d ", a[i]);
	}
	printf("%d", a[i]);
	printf("\n\n");
}
