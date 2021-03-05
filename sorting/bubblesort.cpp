#include "utils.h"
using namespace std;

void bubbleSort(vector<int>& nums) {
    int len = nums.size();
    for (int pass = 0; pass < len - 1; pass++) {
        for (int i = 0; i < len - pass - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                swap(nums[i], nums[i + 1]);
            }
        }
    }
}

int main() {
    testDefault(bubbleSort);
    return 0;
}
