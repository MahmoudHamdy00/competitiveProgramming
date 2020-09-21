/*
 * ICPC Assuit Community - Newcomers (Complexity - Sorting - binary search)
 * Source: https://cutt.ly/ffdO7U1
 * Problem Statement :Implement Bubble Sort
 * Tutorial:https://cutt.ly/SfdO89b
 */

#include<iostream>
#include <algorithm>    // std::swap
using namespace std;

int main() {
	int n = 5;
	int arr[] = { 64, 25, 12, 22, 11 };

	//Bubble Sort
	for (int i = 0; i < n - 1; i++)

		// Last i elements are already in place
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);

	cout << "Sorted array: ";

	//print
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
