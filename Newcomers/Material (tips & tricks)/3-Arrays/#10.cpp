/*
 * ICPC Assuit Community - Newcomers (Array)
 * Source: https://cutt.ly/tff3SCd
 * Problem Statement :You have an array and your task is to calculate the summation of the maximum value in each prefix of the array and the summation of the minimum value in each prefix of the array.
 */
#include<iostream>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	a *= 2;
	b *= 2;
	int copy_b = 0;
	while (b) {
		copy_b = (copy_b * 10) + (b % 10);
		b /= 10;
	}
	while (copy_b) {
		a = (a * 10) + (copy_b % 10);
		copy_b /= 10;
	}
	int good = a * 2;
	cout << "Good number is " << good << endl;
	return 0;
}
