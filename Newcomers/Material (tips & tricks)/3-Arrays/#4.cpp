/*
 * ICPC Assuit Community - Newcomers (Array)
 * Source: https://cutt.ly/tff3SCd
 * Problem Statement :Given an array, check if it’s a palindrome or not.
 */
#include<iostream>
using namespace std;
int arr[100];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	bool palind = true;
	for (int i = 0, j = n - 1; i < j; i++, j--) {
		if (arr[i] != arr[j]) {
			palind = false;
			break;
		}
	}
	if (palind) {
		cout << "This array is palindrome " << endl;
	} else {
		cout << "this is not a palindrome array " << endl;
	}
	return 0;
}
