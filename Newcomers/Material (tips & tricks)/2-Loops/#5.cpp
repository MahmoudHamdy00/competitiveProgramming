/*
 * ICPC Assuit Community - Newcomers (Loops)
 * Source: https://cutt.ly/5fdxPSU
 * Problem Statement :Given two numbers n and a, check if the number n is Almost prime or not.
 */

#include<iostream>
using namespace std;
int main() {
	int n, a;
	cin >> n >> a;
	bool prime = true;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			// if n is divisible by i and neither i = a nor n/i = a so number is not almost prime.
			if (i != a || n / i != a) {
				prime = false;
				break;
			}
		}
	}
	if (prime == true && n > 2) {
		cout << "This Number is almost prime" << endl;
	} else {
		cout << "This Number is not almost prime" << endl;
	}
	return 0;
}
