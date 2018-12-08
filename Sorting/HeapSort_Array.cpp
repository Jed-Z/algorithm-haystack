/* *************************
* FileName: HeapSort_Array.cpp
* Author: Jed Zhang
* Site: 
* Date: 2018.11.22
* Description: 顺序表（数组）的堆排序算法。 
**************************/
#include <iostream>
using namespace std;

void insert_heap(int data[], int current, int low, int high) {
	int largePos = 2 * low + 1;
	while (largePos <= high) {
		if (largePos < high && data[largePos] < data[largePos + 1]) {
			largePos += 1;
		}
		if (current > data[largePos]) { break; }
		else {
			data[low] = data[largePos];
			low = largePos;
			largePos = 2 * low + 1;
		}
	}
	data[low] = current;
}
void heap_sort(int data[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		insert_heap(data, data[i], i, n - 1);
	}
	for (int i = n - 1; i >= 0; i--) {
		int current = data[i];
		data[i] = data[0];
		insert_heap(data, current, 0, i - 1);
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

	heap_sort(data, size);

	for (int i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << endl;

	return 0;
}
