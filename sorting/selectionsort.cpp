#include <iostream>

#include "utils.h"
using namespace std;

void selectionSort(vector<int> &nums) {
    int len = nums.size();
    for (int i = 0; i < len - 1; i++) {
        int min_pos = i;
        for (int j = i + 1; j < len; j++) {
            if (nums[j] < nums[min_pos]) {
                min_pos = j;
            }
        }
        swap(nums[i], nums[min_pos]);
    }
}

int main() {
    testDefault(selectionSort);
    return 0;
}
