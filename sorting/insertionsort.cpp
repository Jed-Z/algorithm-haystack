#include <vector>

#include "utils.h"
using namespace std;

void insertionSort(vector<int>& nums) {
    int len = nums.size();
    for (int i = 1; i < len; i++) {
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}

int main() {
    testDefault(insertionSort);
    return 0;
}
