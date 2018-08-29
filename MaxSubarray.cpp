/*
Author: Jed Zhang
Date: 2018.8.28
Note: 最大子列和问题
URL: https://www.jedbit.com/article/maximum-subarray-algorithm.html
*/
#include <iostream>
using namespace std;

int max_subarray1(int A[], int n) {
    int maxSum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int tempSum = 0;
            for (int k = i; k <= j; k++) {
                tempSum += A[k];
            }
            if (tempSum > maxSum) {
                maxSum = tempSum;
            }
        }
    }
    return maxSum;
}

int max_subarray2(int A[], int n) {
    int maxSum = 0;
    for (int i = 0; i < n; i++) {
        int tempSum = 0;    // 对于固定的i，依次求从A[i]到A[j]的子列和
        for (int j = i; j < n; j++) {
            tempSum += A[j];
            if (tempSum > maxSum) {
                maxSum = tempSum;
            }
        }
    }
    return maxSum;
}

int max_subarray3(int A[], int n) {
    if (n == 1) { return A[0]; }    // 若子列长度为1，则结束递归

                                    /* 左边的最大子列和 */
    int leftMaxSum = max_subarray3(&A[0], n / 2);

    /* 右边的最大子列和 */
    int rightMaxSum = max_subarray3(&A[n / 2], n - n / 2);

    /* 跨越中间边界的最大子列和 */
    int leftScanMaxSum = 0, rightScanMaxSum = 0;
    int tempSum = 0;
    for (int i = n / 2 - 1; i >= 0; i--) {    // 向左扫描
        tempSum += A[i];
        if (tempSum > leftScanMaxSum) { leftScanMaxSum = tempSum; }
    }
    tempSum = 0;    // 清零，供向右扫描使用
    for (int i = n / 2; i <= n; i++) {    // 向右扫描
        tempSum += A[i];
        if (tempSum > rightScanMaxSum) { rightScanMaxSum = tempSum; }
    }
    int midMaxSum = leftScanMaxSum + rightScanMaxSum;

    /* 答案是三种情况中的最大值 */
    int result = leftMaxSum;
    if (rightMaxSum > result) { result = rightMaxSum; }
    if (midMaxSum > result) { result = midMaxSum; }
    return result;
}

int max_subarray4(int A[], int n) {
    int tempSum = 0, maxSum = 0;
    for (int i = 0; i < n; i++) {
        tempSum += A[i];
        if (tempSum > maxSum) {
            maxSum = tempSum;
        }
        else if (tempSum < 0) {
            tempSum = 0;
        }
    }
    return maxSum;
}

int main()
{
    // { -2,11,-4,13,-5,2 }答案应该是20
    int data[] = { -2,11,-4,13,-5,2 };
    cout << max_subarray1(data, 6) << endl;
    cout << max_subarray2(data, 6) << endl;
    cout << max_subarray3(data, 6) << endl;
    cout << max_subarray4(data, 6) << endl;

    return 0;
}
