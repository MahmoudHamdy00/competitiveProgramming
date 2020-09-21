/*
 * ICPC Assuit Community - Newcomers (Array)
 * Source: https://cutt.ly/tff3SCd
 * Problem Statement :You have an array , your task is to find the first number that has been repeated in the array .
 */
#include<iostream>
using namespace std;
int fre[100000];
int main() {
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (fre[a]) {
			cout << a << endl;
			return 0;
		}
		fre[a]++;
	}
	return 0;
}
