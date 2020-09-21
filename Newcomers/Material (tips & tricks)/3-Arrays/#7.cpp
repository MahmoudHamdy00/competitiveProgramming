/*
 * ICPC Assuit Community - Newcomers (Array)
 * Source: https://cutt.ly/tff3SCd
 * Problem Statement :Given an array A of N integers returns the smallest integer that does not occur in A, as N is an integer within the range [1..100,000] and each element of array A is an integer within the range [0..1,000,00].
 */
#include<iostream>
using namespace std;
int fre[(int) 1e5 + 5];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		fre[a]++;
	}
	for (int i = 0; i <= 1e5; i++) {
		if (!fre[i]) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}
