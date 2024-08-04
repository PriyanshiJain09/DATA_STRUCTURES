#include <iostream>
using namespace std;
class ArraySorter {
public:
    void insertionSort(int arr[], int n) {
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }

            arr[j + 1] = key;
        }
    }

    void bubbleSort(int arr[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void selectionSort(int arr[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < n; ++j) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
};

int main() {
    using namespace std;

    const int size = 5;
    int arr[size];

    cout << "Enter " << size << " elements for the array:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int choice;
    cout << "\nChoose a sorting algorithm:\n";
    cout << "1. Insertion Sort\n";
    cout << "2. Bubble Sort\n";
    cout << "3. Selection Sort\n";
    cout << "Enter your choice (1, 2, or 3): ";
    cin >> choice;

    ArraySorter sorter;

    switch (choice) {
        case 1:
            sorter.insertionSort(arr, size);
            break;
        case 2:
            sorter.bubbleSort(arr, size);
            break;
        case 3:
            sorter.selectionSort(arr, size);
            break;
        default:
            cout << "Invalid choice\n";
            return 1;
    }
    cout << "Sorted Array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

