#include <chrono>
#include <iostream>
#include <string>
#include <vector>

#include "StringData.h"

int linear_search(std::vector<std::string> container, std::string element) {
    for (int i = 0; i < container.size(); i++) {
        if (container[i] == element)
            return i;
    }
    return -1;
}

int binary_search(std::vector<std::string> container, std::string element) {
    int min_index = 0;
    int max_index = container.size();
    while (max_index >= min_index) {
        int mid_index = min_index + (max_index - min_index) / 2;
        if (element == container[mid_index]) {
            return mid_index;
        } else if (element.compare(container[mid_index]) < 0) {
            max_index = mid_index - 1;
        } else if (element.compare(container[mid_index]) > 0) {
            min_index = mid_index + 1;
        }
    }
    return -1;
}

std::vector<int> time_func(std::vector<std::string> container, std::string element, int (*func)(std::vector<std::string>, std::string)) {
    auto start_time = std::chrono::high_resolution_clock::now();
    int result = func(container, element);
    auto stop_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop_time - start_time);
    int time_taken = duration.count();
    std::vector<int> output;
    output.push_back(result);
    output.push_back(time_taken);
    return output;
}

void search_and_time(std::vector<std::string> container, std::string element) {
    std::cout << "Searching for: \"" << element << "\"\n";
    std::cout << "Linear search:\n";
    std::vector<int> result = time_func(container, element, linear_search);
    std::cout << "\tTarget index: " << result[0] << "\n";
    std::cout << "\tTime: " << result[1] << "ms\n";
    std::cout << "Binary search:\n";
    result = time_func(container, element, binary_search);
    std::cout << "\tTarget index: " << result[0] << "\n";
    std::cout << "\tTime: " << result[1] << "ms\n";
}

int main() {
    std::vector<std::string> stringData = getStringData();
    search_and_time(stringData, "not_here");
    search_and_time(stringData, "mzzzz");
    search_and_time(stringData, "aaaaa");
}