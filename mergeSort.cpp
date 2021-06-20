#include <iostream>
using namespace std;

void merge(int arr[], int p, int q, int r) {
  /*
    Merges two subarrays of arr[].
    First subarray is arr[p..q]
    Second subarray is arr[q+1..r]
  */
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1], R[n2];
  // fill the two subarrays.
  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int i = 0; i < n2; i++)
    R[i] = arr[q + 1 + i];
  
  // merge the two subarrays back into arr[p..r].
  int i = 0, j = 0, k = p;
  while (i < n1 && j < n2) {
    if (L[i] < R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  // copy the remaining elements of L[] and R[], if there are any.
  while(i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while(j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int p, int r) {
  if (p >= r) return;
  // divide array into two subarrays, then merge them.
  int q = p + (r - p)/ 2;
  mergeSort(arr, p, q);
  mergeSort(arr, q + 1, r);
  merge(arr, p, q, r);
}

int main() {
  int arr [] = {5,4,2,6,1,3};
  int n = end(arr) - begin(arr);
  mergeSort(arr, 0, n);
  for (int i:arr)
    cout<<i<<" ";
  return 0;
}
