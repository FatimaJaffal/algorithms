#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
 * best case when array is sorted {1,2,3} O(n)
 * worst case when array is reversed {3,2,1} O(n^2)
 * used when array is already sorted or partially sorted
*/
vector<int> insertionSort(vector<int> elements) {
    int n = elements.size();
    for (int i = 1; i < n; i++) {
        int key = elements[i];
        int j = i - 1;
        // change condition to elements[j] < key to get descending order
        while (j >= 0 && elements[j] > key) {
            elements[j + 1] = elements[j];
            j--;
        }
        elements[j + 1] = key;
    }
    return elements;
}

int main() {
    vector<int> v = insertionSort({9, 6, 2, 3, 10});
    for (auto i : v) cout << i << " ";
    return 0;
}
