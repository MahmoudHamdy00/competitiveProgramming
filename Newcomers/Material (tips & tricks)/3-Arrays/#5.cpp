/*
 * ICPC Assuit Community - Newcomers (Array)
 * Source: https://cutt.ly/tff3SCd
 * Problem Statement :Given 2 matrices, your task is to swap the main diagonal of the matrices with each other.
 */
#include<iostream>
using namespace std;
int arr1[100][100], arr2[100][100];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr1[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr2[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		swap(arr1[i][i], arr2[i][i]);

	}
	cout << "First Array " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr1[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Second Array " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr2[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
