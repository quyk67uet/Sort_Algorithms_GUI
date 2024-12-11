#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

std::vector<int> inputFromKeyboard();
std::vector<int> generateRandomArray();
std::vector<int> inputFromFile(const std::string& filename);
void saveToFile(const std::string& filename, const std::vector<int>& array);
void printArray(const std::vector<int>& array);

#endif // UTILS_H
