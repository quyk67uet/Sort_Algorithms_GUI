#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <vector>

void insertionSort(std::vector<int>& arr);
void selectionSort(std::vector<int>& arr);
void bubbleSort(std::vector<int>& arr);
void mergeSort(std::vector<int>& arr, int left, int right);
void quickSort(std::vector<int>& arr, int low, int high);
void heapSort(std::vector<int>& arr);
void shellSort(std::vector<int>& arr);
void radixSort(std::vector<int>& arr);
void countingSort(std::vector<int>& arr);
void bucketSort(std::vector<int>& arr);
void timSort(std::vector<int>& arr);
void combSort(std::vector<int>& arr);
void gnomeSort(std::vector<int>& arr);
void pigeonholeSort(std::vector<int>& arr);
void cycleSort(std::vector<int>& arr);


#endif // SORTING_ALGORITHMS_H
