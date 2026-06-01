#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// MERGE SORT (Quick Revision)
// 1. Divide the array into two halves.
// 2. Recursively sort both halves.
// 3. Merge the two sorted halves.
// Time Complexity: O(n log n)
// Space Complexity: O(n)
// Stable Sorting Algorithm
  
void mergeArray(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;

    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[right++]);
    }

    while (left <= mid)
        temp.push_back(arr[left++]);

    while (right <= high)
        temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}

void mergeSort(vector<int>& arr, int low, int high) {
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    mergeArray(arr, low, mid, high);
}


// QUICK SORT (Quick Revision)
// 1. Pick a pivot element.
// 2. Place pivot at its correct position.
// 3. Elements smaller go left, larger go right.
// 4. Recursively sort left and right parts.
// Average Time Complexity: O(n log n)
// Worst Case: O(n^2)
// Space Complexity: O(log n)
// In-place Sorting Algorithm

int partitionArray(vector<int>& arr, int low, int high) {
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partitionArray(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}