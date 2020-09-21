/*
 * ICPC Assuit Community - Newcomers (Function)
 * Source: https://cutt.ly/SffEVgE
 * Problem Statement :Write a program to print the factorial of a number by defining a function named 'Factorial'.Factorial of any number n is represented by n! and is equal to 1*2*3*....*(n-1)*n
 */
#include<iostream>
using namespace std;

long long factorial(int x) {
	long long fac = 1;
	if (x == 0 || x == 1)
		return fac;
	for (int i = 1; i <= x; i++)
		fac = fac * i;
	return fac;
}

int main() {
	int x;
	cin >> x;
	cout << factorial(x) << "\n";
	return 0;
}
