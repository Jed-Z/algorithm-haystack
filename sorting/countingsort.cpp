#include "utils.h"
using namespace std;

void countingSort(vector<int>& nums) {
    int len = nums.size();
    int max_val = nums[0], min_val = nums[0];
    for (int i = 0; i < len; i++) {
        max_val = max(max_val, nums[i]);
        min_val = min(min_val, nums[i]);
    }
    vector<int> count(max_val - min_val + 1);
    vector<int> output(len);
    for (int i = 0; i < len; i++) {
        count[nums[i] - min_val]++;
    }
    // count[i] now contains the number of elements equal to i

    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }
    // count[i] now contains the number of elements less than or equal to i

    for (int i = len - 1; i >= 0; i--) {
        int num = nums[i];
        output[count[num - min_val]] = num;
        count[num - min_val]--;
    }
    nums = output;
}

int main() {
    testDefault(countingSort);
    return 0;
}
