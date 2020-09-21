/*
 * ICPC Assuit Community - Newcomers (Array)
 * Source: https://cutt.ly/tff3SCd
 * Problem Statement :You have an array and your task is to calculate the summation of the maximum value in each prefix of the array and the summation of the minimum value in each prefix of the array.
 */
#include<iostream>
#include <climits>
using namespace std;
int arr[(int) 1e6];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int mn = INT_MAX, mx = INT_MIN, sum_mn = 0, sum_mx = 0;
	for (int i = 0; i < n; i++) {
		mn = min(mn, arr[i]);
		mx = max(mx, arr[i]);
		sum_mn += mn;
		sum_mx += mx;
	}
	cout << "summation of minimum values equal " << sum_mn << endl;
	cout << "summation of maximum values equal " << sum_mx << endl;
	return 0;
}
