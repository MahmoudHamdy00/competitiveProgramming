/*
 * ICPC Assuit Community - Newcomers (Complexity - Sorting - binary search)
 * Source: https://cutt.ly/ffdO7U1
 * Problem Statement :Implement selection sort
 * Tutorial:https://cutt.ly/EfdObVX
 */

#include<iostream>
#include <algorithm>    // std::swap
using namespace std;

int main() {
	int n = 5;
	int arr[] = { 64, 25, 12, 22, 11 };


	//Selection Sort
	// One by one move boundary of unsorted subarray
	for (int i = 0; i < n - 1; i++) {
		// Find the minimum element in unsorted array
		int min_idx = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element
		swap(arr[min_idx], arr[i]);
	}

	cout << "Sorted array: ";

	//print
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
