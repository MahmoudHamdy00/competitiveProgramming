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
int main(){
	string n;
	cin >> n;
	int sz = n.size();
	//(sz + 1) / 2   equivalent to ceil(n/2.0);
	for (int i = 0; i < (sz + 1) / 2; i++){
		int a = n[i] - '0'; // convert first char of string to int
		int b = n[sz - i - 1] - '0'; // convert opposite  char of string to int
		int sum = a + b;
		cout << sum << endl;
	}
	return 0;
}
