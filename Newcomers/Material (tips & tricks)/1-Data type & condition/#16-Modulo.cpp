/*
 * ICPC Assuit Community - Newcomers (Loops)
 * Source: https://cutt.ly/5fdxPSU
 * Problem Statement :Given two numbers a and b, your task is to print the remainder of division a by b
 */

#include<iostream>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	cout << a - a / b * b << endl;
	return 0;
}
