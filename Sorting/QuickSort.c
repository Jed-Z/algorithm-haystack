/*
Author: Jed Zhang
Date: 20171215
Time: 19:26
Note: QuickSort in pure C. See also: http://developer.51cto.com/art/201403/430986.htm
*/
#include <stdio.h>
void qsort(int [], int);
void swap(int *, int *);
int main(void)
{
	int n;
	scanf("%d", &n);
	int test[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &test[i]);
	}
	qsort(test, n);	//调用函数
	for(int i = 0; i < n; i++) {
		printf("%d ", test[i]);
	}
}
void qsort(int test[], int n)
{
	if(n < 2) return;	//注意结束函数的条件。
	int i = 0, j = n-1;	//i要设置为0而不是1，下面要用等于号
	int key = test[0];
	while(i != j) {
		while(test[j] >= key && i != j)	//注意有等于号
			j--;
		while(test[i] <= key && i != j)	//同上
			i++;
		swap(&test[i], &test[j]);
	}
	swap(&test[0], &test[i]);
	qsort(test, i);
	qsort(&test[i+1], n-i-1);
}
void swap(int *x, int *y)
{
	int hold = *x;
	*x = *y;
	*y = hold;
}
