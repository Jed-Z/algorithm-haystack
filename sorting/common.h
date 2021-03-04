#include <iostream>
#include <vector>

std::vector<int> td_random = {4, 9, 0, 5, 6, 2, 1, 7, 3, 8};
std::vector<int> td_reversed = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
std::vector<int> td_duplicated = {3, 3, 0, 4, 3, 2, 5, 2, 1, 5};

template <class T>
void print(std::vector<T> data) {
    if (data.empty())
        std::cout << "{ }" << std::endl;
    else {
        std::cout << "{ " << data[0];
        for (int i = 1; i < data.size(); i++) {
            std::cout << ", " << data[i];
        }
        std::cout << " }" << std::endl;
    }
}
