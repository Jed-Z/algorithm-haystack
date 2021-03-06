#include "utils.h"
using namespace std;

void maxHeapify(vector<int>& nums, int low, int high) {
    int large_pos = 2 * low + 1;
    while (large_pos <= high) {
        if (large_pos + 1 <= high && nums[large_pos] < nums[large_pos + 1]) {
            large_pos += 1;  // Index of the larger of the two children nodes
        }
        if (nums[low] > nums[large_pos]) {
            break;
        } else {
            swap(nums[low], nums[large_pos]);
            low = large_pos;
            large_pos = 2 * low + 1;
        }
    }
}

void heapSort(vector<int>& nums) {
    int len = nums.size();

    // Build the initial heap
    for (int i = len / 2 - 1; i >= 0; i--) {
        maxHeapify(nums, i, len - 1);
    }

    // Extract elements one by one
    for (int i = len - 1; i >= 0; i--) {
        swap(nums[0], nums[i]);
        maxHeapify(nums, 0, i - 1);
    }
}

int main() {
    testDefault(heapSort);
    return 0;
}
