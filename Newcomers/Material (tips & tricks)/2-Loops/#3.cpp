/*
 * ICPC Assuit Community - Newcomers (Loops)
 * Source: https://cutt.ly/5fdxPSU
 * Problem Statement :Given three numbers n, a, and b, your task is to print the numbers from 1 to n that divisible by a and not divisible by b.
 * example : n= 15  a=2 b= 3;  	output : 2 4 8 10 14
 */

#include<iostream>
using namespace std;
int main() {
	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
		if (i % a == 0 && i % b != 0) {
			cout << i << " ";
		}
	}
	return 0;
}
