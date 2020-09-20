#include <iostream>
using namespace std;

void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}
int find_max_pos(int data[], int bottom, int top) {
    int maxPos = bottom;
    for (int i = bottom + 1; i <= top; i++) {
        if (data[i] > data[maxPos]) {
            maxPos = i;
        }
    }
    return maxPos;
}
void selection_sort(int data[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int maxPos = find_max_pos(data, 0, i);
        swap(data[i], data[maxPos]);
    }
}

int main() {
    int data[] = {8, 4, 3, 5, 1, 7, 6, 2};
    int size = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    selection_sort(data, size);

    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    // system("pause");
    return 0;
}
