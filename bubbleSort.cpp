#include <iostream>
using namespace std;

/*
  worst: O(n^2) when array is reverse sorted.
  best: O(n). when array is already sorted.
*/

void optimizedBubbleSort(int arr[], int* n) {
  for (int i = 0; i < *n - 1; i++) {
    bool swapped = false;
    for (int j = 0; j < *n - i - 1; j++) {
      if (arr[j] > arr[j+1]) {
        swap(arr[j], arr[j+1]);
        swapped = true;
      }
    }
    // if no two elements were swapped by inner loop, then break.
    if (!swapped) 
      break;
  }
}

/*
  worst, best: O(n^2), even if the array is sorted.
*/

void bubbleSort(int arr[], int* n) {
  for (int i = 0; i < *n - 1; i++) {
    for (int j = 0; j < *n - i - 1; j++) {
      if (arr[j] > arr[j+1])
        swap(arr[j], arr[j+1]);
    }
  }
}

int main() {
  int arr[] = {5,4,2,6,1,3};
  int n = end(arr) - begin(arr);
  optimizedBubbleSort(arr, &n);
  for (int i: arr) {
    cout<<i<<" ";
  }
  return 0;
}
