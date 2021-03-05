#include "utils.h"
using namespace std;

void merge(vector<int>& nums, int low, int mid, int high) {
    // Copy data into two temp vectors
    vector<int> left(nums.begin() + low, nums.begin() + mid + 1);
    vector<int> right(nums.begin() + mid + 1, nums.begin() + high + 1);

    // Merge them back into the original vector
    int i = 0, j = 0, k = low;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j])
            nums[k++] = left[i++];
        else
            nums[k++] = right[j++];
    }
    while (i < left.size()) nums[k++] = left[i++];
    while (j < right.size()) nums[k++] = right[j++];
}

void mergeSort(vector<int>& nums, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
}

int main() {
    testDefault([](vector<int>& nums) { mergeSort(nums, 0, nums.size() - 1); });
    return 0;
}