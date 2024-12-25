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
        std::cout << "Invalid choice. Exiting program.\n";
        return 1;
    }

    while (true) {
        displayMenu();
        int choice;
        std::cin >> choice;

        if (choice == 16) {
            std::cout << "Exiting program. Goodbye!\n";
            break;
        }

        std::vector<int> arrayCopy = array; // Copy the original array for sorting

        std::cout << "Unsorted Array: ";
        printArray(arrayCopy);

        // Timing the sorting process
        auto start = std::chrono::high_resolution_clock::now();
        switch (choice) {
            case 1: insertionSortWithSteps(arrayCopy); break;
            case 2: selectionSortWithSteps(arrayCopy); break;
            case 3: bubbleSortWithSteps(arrayCopy); break;
            case 4: mergeSortWithSteps(arrayCopy, 0, arrayCopy.size() - 1); break;
            case 5: quickSortWithSteps(arrayCopy, 0, arrayCopy.size() - 1); break;
            case 6: heapSortWithSteps(arrayCopy); break;
            case 7: shellSortWithSteps(arrayCopy); break;
            case 8: radixSortWithSteps(arrayCopy); break;
            case 9: countingSortWithSteps(arrayCopy); break;
            case 10: bucketSortWithSteps(arrayCopy); break;
            case 11: timSortWithSteps(arrayCopy); break;
            case 12: combSortWithSteps(arrayCopy); break;
            case 13: gnomeSortWithSteps(arrayCopy); break;
            case 14: pigeonholeSortWithSteps(arrayCopy); break;
            case 15: cycleSortWithSteps(arrayCopy); break;
            default:
                std::cout << "Invalid choice. Try again.\n";
                continue;
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        std::cout << "Sorted Array: ";
        printArray(arrayCopy);
        std::cout << "Time taken: " << elapsed.count() << " seconds\n";

        std::cout << "\nWould you like to save the result to a file? (y/n): ";
        char saveChoice;
        std::cin >> saveChoice;
        if (saveChoice == 'y' || saveChoice == 'Y') {
            saveToFile("output.txt", arrayCopy);
        }
    }

    return 0;
}
