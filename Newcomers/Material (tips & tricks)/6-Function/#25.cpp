/*
 * ICPC Assuit Community - Newcomers (Function)
 * Source: https://cutt.ly/SffEVgE
 * Problem Statement :Write a C++ program which calculates the sum  1/1 + 1/2 + 1/3 + 1/4 + ... + 1/N.where N is a positive integer.
 */
#include<iostream>
using namespace std;

double calc_sum(int n) {
	double sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += (1.0 / i);
	}
	return sum;
}

int main() {
	int n;
	cin >> n;
	cout << calc_sum(n);

	return 0;
}
