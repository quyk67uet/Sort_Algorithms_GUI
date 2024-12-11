#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "sorting_algorithms.h"
#include "utils.h"

void displayMenu() {
    std::cout << "================ Sorting Algorithms =================\n";
    std::cout << "1. Insertion Sort\n";
    std::cout << "2. Selection Sort\n";
    std::cout << "3. Bubble Sort\n";
    std::cout << "4. Merge Sort\n";
    std::cout << "5. Quick Sort\n";
    std::cout << "6. Heap Sort\n";
    std::cout << "7. Shell Sort\n";
    std::cout << "8. Radix Sort\n";
    std::cout << "9. Counting Sort\n";
    std::cout << "10. Bucket Sort\n";
    std::cout << "11. Tim Sort\n";
    std::cout << "12. Comb Sort\n";
    std::cout << "13. Gnome Sort\n";
    std::cout << "14. Pigeonhole Sort\n";
    std::cout << "15. Cycle Sort\n";
    std::cout << "16. Exit\n";
    std::cout << "=====================================================\n";
    std::cout << "Choose an algorithm: ";
}

int main() {
    while (true) {
        displayMenu();
        int choice;
        std::cin >> choice;

        if (choice == 16) {
            std::cout << "Exiting program. Goodbye!\n";
            break;
        }

        std::vector<int> array;
        int inputChoice;
        std::cout << "\nEnter input method:\n1. Keyboard\n2. Random Generation\n3. File Input\n";
        std::cin >> inputChoice;

        if (inputChoice == 1) {
            array = inputFromKeyboard();
        } else if (inputChoice == 2) {
            array = generateRandomArray();
        } else if (inputChoice == 3) {
            array = inputFromFile("input.txt");
        } else {
            std::cout << "Invalid choice. Try again.\n";
            continue;
        }

        std::cout << "Unsorted Array: ";
        printArray(array);

        // Timing the sorting process
        auto start = std::chrono::high_resolution_clock::now();
        switch (choice) {
            case 1: insertionSort(array); break;
            case 2: selectionSort(array); break;
            case 3: bubbleSort(array); break;
            case 4: mergeSort(array, 0, array.size() - 1); break;
            case 5: quickSort(array, 0, array.size() - 1); break;
            case 6: heapSort(array); break;
            case 7: shellSort(array); break;
            case 8: radixSort(array); break;
            case 9: countingSort(array); break;
            case 10: bucketSort(array); break;
            case 11: timSort(array); break;
            case 12: combSort(array); break;
            case 13: gnomeSort(array); break;
            case 14: pigeonholeSort(array); break;
            case 15: cycleSort(array); break;
            default:
                std::cout << "Invalid choice. Try again.\n";
                continue;
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        std::cout << "Sorted Array: ";
        printArray(array);
        std::cout << "Time taken: " << elapsed.count() << " seconds\n";

        std::cout << "\nWould you like to save the result to a file? (y/n): ";
        char saveChoice;
        std::cin >> saveChoice;
        if (saveChoice == 'y' || saveChoice == 'Y') {
            saveToFile("output.txt", array);
        }
    }

    return 0;
}
