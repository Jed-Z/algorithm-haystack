/* *************************
* FileName: SelectionSort_Array.cpp
* Author: Jed Zhang
* Site: https://www.jedbit.com
* Date: 2018.11.21
* Description: 顺序表（数组）的选择排序算法。
*              非最终版本，极可能存在bug。 
**************************/
#include <iostream>
using namespace std;

void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void quick_sort(int data[], int bottom, int top){
	if(bottom < top){
		int& pivot = data[bottom];
		int last_small = bottom;
		for(int i = bottom+1; i <= top; i++){
			if(data[i] < pivot){
				++last_small;
				swap(data[last_small], data[i]);
			} 
		}
		swap(pivot, data[last_small]);
		
		// last_small is pivot position.
		quick_sort(data, bottom, last_small-1);
		quick_sort(data, last_small+1, top);
	}
}
int main()
{
	int data[] = { 8, 4, 3, 5, 1, 7, 6, 2 };
	int size = sizeof(data) / sizeof(data[0]);

	for (int i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
	
	quick_sort(data, 0, size-1);
	
	for (int i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
	return 0;
}
