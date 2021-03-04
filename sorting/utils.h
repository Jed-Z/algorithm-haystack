#include <iostream>
#include <vector>

std::vector<int> td_random = {4, 9, 0, 5, 6, 2, 1, 7, 3, 8};
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

void testDefault(void (*f)(std::vector<int>&)) {
    f(td_random);
    print(td_random);
    f(td_reversed);
    print(td_reversed);
    f(td_duplicated);
    print(td_duplicated);
}
