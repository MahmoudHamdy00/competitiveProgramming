/*
 * ICPC Assuit Community - Newcomers (Array)
 * Source: https://cutt.ly/tff3SCd
 * Problem Statement :Given an array, print the elements in the even indices.
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
	for (int i = 2; i <= n; i += 2) {
		cout << arr[i] << endl;
	}
	return 0;
}
