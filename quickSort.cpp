#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * D & C ==> T(n) = aT(n/b)+Combine(n)+Divide(n)
 * quick sort ==> T(n) = aT(n/b) + 1 + n
 * best case ==> T(n) = 2T(n/2) + n O(n log n)
 * worst case ==> T(n) = T(n-1) + T(0) + n
 * divide array to two sub arrays with length n-1 and 0 when array is already sorted
 * O(n^2)
 */


int partition(vector<int> &elements, int p, int r) {
    int pivot = elements[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (elements[j] <= pivot) {
            i++;
            swap(elements[i], elements[j]);
        }
    }
    swap(elements[i + 1], elements[r]);
    return i + 1;
}

void quickSort(vector<int> &elements, int p, int r) {
    if (p < r) {
        int q = partition(elements, p, r);
        quickSort(elements, p, q - 1);
        quickSort(elements, q + 1, r);
    }
}

int main() {
    vector<int> v{5, 13, 12, 6, 4, 1, 3, 7};
    quickSort(v, 0, v.size() - 1);
    for (auto i : v) cout << i << " ";
    return 0;
}
