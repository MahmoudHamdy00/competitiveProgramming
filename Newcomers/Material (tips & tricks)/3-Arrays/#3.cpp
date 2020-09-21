/*
 * ICPC Assuit Community - Newcomers (Array)
 * Source: https://cutt.ly/tff3SCd
 * Problem Statement :Given an array, print its elements in reversed order.
 */
#include<iostream>
using namespace std;
int arr[100];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = n; i > 0; i--) {
		cout << arr[i] << " ";
	}
	return 0;
}
