#include <iostream>
using namespace std;

/* 
  In every iteration of selection sort, the minimum element (considering ascending order) 
  from the unsorted subarray is picked and moved to the sorted subarray. 
  time complexity O(n^2), space O(1).
  The good thing about selection sort is it never makes more than O(n) swaps and 
  can be useful when memory write is a costly operation.
*/

int getMin(int arr[], int s, int* n) {
  int minIndex = s;
  for (int i = s + 1; i < *n; i++) {
    if (arr[minIndex] > arr[i]) {
      minIndex = i;
    }
  }
  return minIndex;
}

void selectionSort(int arr[], int* n) {
  for (int i = 0; i < *n; i++) {
    int minIndex = getMin(arr, i, n);
    swap(arr[minIndex], arr[i]);
  }
}

int main() {
  int arr[] = {5,4,2,6,1,3};
  int n = end(arr) - begin(arr);
  selectionSort(arr, &n);
  for (int i: arr) {
    cout<<i<<" ";
  }
  return 0;
}
