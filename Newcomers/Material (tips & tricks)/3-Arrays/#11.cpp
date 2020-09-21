/*
 * ICPC Assuit Community - Newcomers (Array)
 * Source: https://cutt.ly/tff3SCd
 * Problem Statement :Given an array A of consist of  N numbers ( 4 <N<1^5 ) , (-10^9<A[i]<10^9) and  your task is  to find the second lowest and the second highest numbers
 */
#include<iostream>
using namespace std;
int arr[(int) 1e5 + 5];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cout << arr[1] << " " << arr[n - 2] << endl;
	return 0;
}
