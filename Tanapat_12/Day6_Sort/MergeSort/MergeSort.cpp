#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    // Create temporary vectors
    vector<int> leftArr;
    vector<int> rightArr;

    // Copy data to temporary vectors
    for (int i = left; i <= mid; i++) leftArr.push_back(arr[i]);
    for (int i = mid + 1; i <= right; i++) rightArr.push_back(arr[i]);

    // Merge the temporary vectors back into arr
    int i = 0, j = 0, k = left;
    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

  // Copy the remaining elements
  while (i < leftArr.size()) {
    arr[k] = leftArr[i];
    i++;
    k++;
  }
  while (j < rightArr.size()) {
    arr[k] = rightArr[j];
    j++;
    k++;
  }
}

void mergeSort(vector<int>& arr, int left, int right) {
  if (left < right) {
    // Find the middle point
    int mid = (left + right) / 2;

    // Sort first and second halves
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the sorted halves
    merge(arr, left, mid, right);
  }
}

void printVector(const vector<int>& arr) {
  for (int num : arr) {
    cout << num << " ";
  }
  cout << endl;
}

int main() {
  vector<int> arr = {6, 5, 3, 1, 8, 7, 2, 4};

  cout << "Unsorted vector: ";
  printVector(arr);

  mergeSort(arr, 0, arr.size() - 1);

  cout << "Sorted vector: ";
  printVector(arr);

  return 0;
}