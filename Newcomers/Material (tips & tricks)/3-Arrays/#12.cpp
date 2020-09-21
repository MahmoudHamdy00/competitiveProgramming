/*
 * ICPC Assuit Community - Newcomers (Array)
 * Source: https://cutt.ly/tff3SCd
 * Problem Statement :Write a C++ program to count the number of occurrences of a given number in a sorted array of integers (you have to answer several queries)
 */
#include<iostream>
int frq[(int) 1e5];
using namespace std;
int main() {
	int n, q;
	cin >> n >> q;
	for (int i = 1, x; i <= n; i++) {
		cin >> x;
		frq[x]++;
	}
	while (q--) {
		int num;
		cin >> num;
		cout << frq[num] << endl;
	}
	return 0;
}
