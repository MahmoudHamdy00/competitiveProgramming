/*
 * ICPC Assuit Community - Newcomers (Loops)
 * Source: https://cutt.ly/5fdxPSU
 * Problem Statement :Given a number n, your task is to print the summation for every two opposite numbers.
 * example 12376         output:7
 *								9
 *								6
 *
 */

#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int numOfDigits = 0; //store number of digits.
	int tmp = n;
	int rev = 0; //store the number in reversed order
	while (n) {
		rev = rev * 10 + n % 10;
		n /= 10;
		numOfDigits++; // increase 1 digit.
	}
	n = tmp;

	int len = (numOfDigits + 1) / 2; //(numOfDigits + 1) / 2   equivalent to ceil(numOfDigits/2.0);
	while (len--) {
		cout << n % 10 + rev % 10 << endl;
		n /= 10, rev /= 10;
	}
	return 0;
}
