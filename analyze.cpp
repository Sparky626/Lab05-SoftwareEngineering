#include "StringData.h"
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>

int linear_search(std::vector<std::string> container, std::string element) {
    for(int i = 0; i < container.size(); i++){
        if (container[i] == element){
            return i;
        }
    
    }
    return -1;
}

int binary_search(std::vector<std::string> container, std::string element) {
    int minIndex = 0;
    int maxIndex = container.size();
    while (maxIndex >= minIndex){
        int midIndex = minIndex + (maxIndex - minIndex)/2;
        if (element == container[midIndex])
            return midIndex;
        else if (element.compare(container[midIndex]) < 0){
            maxIndex = midIndex - 1;
        }
        else if (element.compare(container[midIndex]) > 0){
            minIndex = midIndex + 1;
        }
    }
    return -1;
}

int main(){
    std::vector<std::string> stringData = getStringData();
    std::cout << "Linear Search for not_here" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    int index = linear_search(stringData,"not_here");
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
    std::cout << "Time taken by search: " << duration.count() << " microseconds" << std::endl;
    std::cout << "The index is: " << index << std::endl;
    std::cout << "Binary Search for not_here" << std::endl;
    start = std::chrono::high_resolution_clock::now();
    index = binary_search(stringData,"not_here");
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
    std::cout << "Time taken by search: " << duration.count() << " microseconds" << std::endl;
    std::cout << "The index is: " << index << std::endl;
    std::cout << "Binary Search for not_here" << std::endl;
    start = std::chrono::high_resolution_clock::now();
    index = linear_search(stringData,"mzzzz");
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
    std::cout << "Time taken by search: " << duration.count() << " microseconds" << std::endl;
    std::cout << "The index is: " << index << std::endl;
    std::cout << "Linear Search for mzzzz" << std::endl;
    start = std::chrono::high_resolution_clock::now();
    index = binary_search(stringData,"mzzzz");
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
    std::cout << "Time taken by search: " << duration.count() << " microseconds" << std::endl;
    std::cout << "The index is: " << index << std::endl;
    std::cout << "Binary Search for mzzzz" << std::endl;
    start = std::chrono::high_resolution_clock::now();
    index = linear_search(stringData,"aaaaa");
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
    std::cout << "Time taken by search: " << duration.count() << " microseconds" << std::endl;
    std::cout << "The index is: " << index << std::endl;
    std::cout << "Linear Search for aaaaa" << std::endl;
    start = std::chrono::high_resolution_clock::now();
    index = binary_search(stringData,"aaaaa");
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
    std::cout << "Time taken by search: " << duration.count() << " microseconds" << std::endl;
    std::cout << "The index is: " << index << std::endl;
    std::cout << "Binary Search for aaaaa" << std::endl;

}
