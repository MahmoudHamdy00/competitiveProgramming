/*
 * ICPC Assuit Community - Newcomers (Function)
 * Source: https://cutt.ly/SffEVgE
 * Problem Statement :Write a program in C++ to find the square of any number using the function
 * example :  20            output: 400
 */
#include<iostream>
using namespace std;

int squar(int n) {
	return n * n;
}

int main() {
	int n;
	cin >> n;
	cout << squar(n);
}
