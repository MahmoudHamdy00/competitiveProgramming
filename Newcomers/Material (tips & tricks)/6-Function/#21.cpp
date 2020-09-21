/*
 * ICPC Assuit Community - Newcomers (Function)
 * Source: https://cutt.ly/SffEVgE
 * Problem Statement :Write a program that checks whether two integer arrays are the same(they have the same size and values). In this case, the return value should be 1 otherwise 0.
 */

#include <iostream>
using namespace std;
int check(int n, int a[], int b[]) {
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			return 0;
		}
	}
	return 1;
}
int main() {
	int n, a[1000], b[1000];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	cout << check(n, a, b);
	return 0;
}
