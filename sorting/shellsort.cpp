#include "utils.h"
using namespace std;

void shellSort(vector<int>& nums) {
    int len = nums.size();
    for (int gap = len / 2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort
        for (int i = gap; i < len; i++) {
            int temp = nums[i];
            int j = i - gap;
            while (j >= 0 && nums[j] > temp) {
                nums[j + gap] = nums[j];
                j -= gap;
            }
            nums[j + gap] = temp;
        }
    }
}

int main() {
    testDefault(shellSort);
    return 0;
}
