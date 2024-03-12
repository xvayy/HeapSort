#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROWS = 2;
const int COLS = 9;

// Function to swap elements
void swapElements(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to build max heap
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swapElements(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to perform HeapSort
void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        swapElements(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Function to find the row with the minimum element
int findMinEl(int arr[ROWS][COLS]) {
    cout << "Finding the row with the minimum element" << endl;

    int* minArr = new int[ROWS]; // Array to store the minimum elements of rows

    for (int i = 0; i < ROWS; i++) {
        int min = arr[i][0]; // Assume the first element of the row is the minimum

        for (int j = 0; j < COLS; j++) {
            cout << arr[i][j] << "\t"; // Output elements of the row

            if (arr[i][j] < min) {
                min = arr[i][j]; // Found a smaller element
            }
        }

        minArr[i] = min; // Store the minimum element of the row
        cout << endl;
    }

    int minimal = minArr[0]; // Assume the first minimum element is the smallest
    int minIndex = 0; // Index of the row with the minimum element

    for (int i = 1; i < ROWS; i++) {
        if (minArr[i] < minimal) {
            minimal = minArr[i]; // Found a smaller minimum element
            minIndex = i; // Save the index of the row
        }
    }

    delete[] minArr; // Free memory
    cout << "Minimum element: " << minimal << endl;
    cout << "Index of the row with the minimum element: " << minIndex << endl;
    return minIndex; // Return the index of the row with the minimum element
}

int main() {
    srand(time(nullptr));

    int arr[ROWS][COLS];

    // Fill the array with random values
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = rand() % 100; // Random numbers from 0 to 99
        }
    }

    // Find the row with the minimum element
    int minRowIndex = findMinEl(arr);

    // Sort the found row in ascending order
    heapSort(arr[minRowIndex], COLS);

    // Output the sorted row
    cout << "Sorted row: ";
    for (int i = 0; i < COLS; i++) {
        cout << arr[minRowIndex][i] << " ";
    }
    cout << endl;

    return 0;
}
