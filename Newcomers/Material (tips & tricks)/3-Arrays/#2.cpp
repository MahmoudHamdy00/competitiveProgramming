/*
 * ICPC Assuit Community - Newcomers (Array)
 * Source: https://cutt.ly/tff3SCd
 * Problem Statement :Given an array, print odd numbers then print even numbers.
 */
#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int arr[100];
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i] % 2 != 0) {
			cout << arr[i] << endl;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i] % 2 == 0) {
			cout << arr[i] << endl;
		}
	}
	return 0;
}
