#include <iostream>

#include "utils.h"
using namespace std;

int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[low];
    int pivot_pos = low;
    for (int i = low + 1; i <= high; i++) {
        if (nums[i] < pivot) {
            swap(nums[++pivot_pos], nums[i]);
        }
    }
    swap(nums[low], nums[pivot_pos]);
    return pivot_pos;
}

void quickSort(vector<int>& nums, int low, int high) {
    if (low < high) {
        int pivot_pos = partition(nums, low, high);
        quickSort(nums, low, pivot_pos - 1);
        quickSort(nums, pivot_pos + 1, high);
    }
}

int main() {
    testDefault([](vector<int>& nums) { quickSort(nums, 0, nums.size() - 1); });
    return 0;
}
