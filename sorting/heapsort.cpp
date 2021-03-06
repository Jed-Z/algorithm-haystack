#include "utils.h"
using namespace std;

void maxHeapify(vector<int>& nums, int low, int high) {
    int current = nums[low];
    int largePos = 2 * low + 1;
    while (largePos <= high) {
        if (largePos < high && nums[largePos] < nums[largePos + 1]) {
            largePos += 1;
        }
        if (current > nums[largePos]) {
            break;
        } else {
            nums[low] = nums[largePos];
            low = largePos;
            largePos = 2 * low + 1;
        }
    }
    nums[low] = current;
}

void heapSort(vector<int>& nums) {
    int len = nums.size();
    for (int i = len / 2 - 1; i >= 0; i--) {
        maxHeapify(nums, i, len - 1);
    }
    for (int i = len - 1; i >= 0; i--) {
        swap(nums[0], nums[i]);
        maxHeapify(nums, 0, i - 1);
    }
}

int main() {
    testDefault(heapSort);
    return 0;
}
