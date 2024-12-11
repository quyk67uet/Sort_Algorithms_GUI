#include "utils.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

std::vector<int> inputFromKeyboard() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter the elements: ";
    for (int& num : arr) {
        std::cin >> num;
    }
    return arr;
}

std::vector<int> generateRandomArray() {
    int n, maxValue;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    std::cout << "Enter the maximum value: ";
    std::cin >> maxValue;

    std::vector<int> arr(n);
    for (int& num : arr) {
        num = rand() % (maxValue + 1);
    }
    return arr;
}

std::vector<int> inputFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<int> arr;
    int num;

    while (file >> num) {
        arr.push_back(num);
    }
    return arr;
}

void saveToFile(const std::string& filename, const std::vector<int>& array) {
    std::ofstream file(filename);
    for (int num : array) {
        file << num << " ";
    }
    std::cout << "Results saved to " << filename << "\n";
}

void printArray(const std::vector<int>& array) {
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}
