/*
 * ICPC Assuit Community - Newcomers (Array)
 * Source: https://cutt.ly/tff3SCd
 * Problem Statement :You have an array 2D print the summation of the lower left triangle of the matrix.
 */
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	int arr[100][100];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int sum_low = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			sum_low += arr[i][j];
		}
	}
	cout << sum_low << endl;
	return 0;
}
