#include <iostream>
using namespace std;

int binary_search(int data[], int size, int key) {
	int left = 0, right = size - 1, mid = (left + right) / 2;
	while (left <= right) {    // Caution: '<=' instead of '<'!
		if (key > data[mid]) {
			left = mid + 1;
			mid = (left + right) / 2;
		}
		else if (key < data[mid]) {
			right = mid - 1;
			mid = (left + right) / 2;
		}
		else {
			return mid;
		}
	}

	return -1;
}
int main()
{
	int data[] = { 2, 5, 8, 13, 52, 79, 159, 500, 687, 861, 901, 999, 1000 };
	cout << binary_search(data, 12, 5) << endl;
	
	return 0;
}
