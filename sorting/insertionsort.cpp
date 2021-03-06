#include "utils.h"
using namespace std;

void insertionSort(vector<int>& nums) {
    int len = nums.size();
    for (int i = 1; i < len; i++) {
        int temp = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > temp) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = temp;
    }
}

int main() {
    testDefault(insertionSort);
    return 0;
}
