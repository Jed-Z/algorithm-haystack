#include <iostream>
#include <vector>

std::vector<int> td_standard = {4, 9, 0, 5, 6, 2, 1, 7, 3, 8};
std::vector<int> td_reversed = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
std::vector<int> td_duplicated = {3, 3, 0, 4, 3, 2, 5, 2, 1, 5};

template <class T>
void print(std::vector<T> vec) {
    if (vec.empty()) {
        std::cout << "{ }" << std::endl;
    } else {
        std::cout << "{ " << vec[0];
        for (int i = 1; i < vec.size(); i++) {
            std::cout << ", " << vec[i];
        }
        std::cout << " }" << std::endl;
    }
}

template <class T>
void print(T arr[], size_t n) {
    if (n == 0) {
        std::cout << "{ }" << std::endl;
    } else {
        std::cout << "{ " << arr[0];
        for (int i = 1; i < n; i++) {
            std::cout << ", " << arr[i];
        }
        std::cout << " }" << std::endl;
    }
}

bool test(std::vector<int> nums, void (*algorithm)(std::vector<int>&), bool display = true) {
    srand((unsigned)time(NULL));
    std::vector<int> nums_stl = nums;
    sort(nums_stl.begin(), nums_stl.end());
    algorithm(nums);
    bool isCorrect = (nums_stl == nums);
    std::cout << (isCorrect ? "OK" : "ERR") << ' ';
    if (display)
        print(nums);
    else
        std::cout << std::endl;
    return isCorrect;
}

void testDefault(void (*algorithm)(std::vector<int>&)) {
    test(td_standard, algorithm);
    test(td_reversed, algorithm);
    test(td_duplicated, algorithm);
    std::vector<int> td_random(10000);
    for (int i = 0; i < 10000; i++) td_random[i] = rand();
    test(td_random, algorithm, false);
}
