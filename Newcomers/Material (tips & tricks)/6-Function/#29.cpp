/*
 * ICPC Assuit Community - Newcomers (Function)
 * Source: https://cutt.ly/SffEVgE
 * Problem Statement :Write a program in C++ to check Armstrong number using the function.An Armstrong number is an n-digit number that is equal to the sum of the n-th powers of its digits.If so, the return value should be 1 otherwise 0.
 * example :  371              output: 1
 */
#include<iostream>
#include<string>
using namespace std;

int checkArmstrong(int n, int sz) {
	int num = n, sum = 0;
	while (num > 0) {
		int pow_dig = 1;
		for (int i = 0; i < sz; i++) {
			pow_dig *= (num % 10);
		}
		sum += pow_dig;
		num /= 10;
	}
	return (n == sum);
}
int main() {
	int n;
	cin >> n;
	string s = to_string(n);
	cout << checkArmstrong(n, s.size());
}
