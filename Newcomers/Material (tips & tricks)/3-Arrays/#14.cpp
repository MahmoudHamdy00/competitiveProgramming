/*
 * ICPC Assuit Community - Newcomers (Array)
 * Source: https://cutt.ly/tff3SCd
 * Problem Statement :You have an array A copy it in another  one  B then sort array A  in ascending order  and the array B  in descending order, then find the summation of the absolute difference  between each element from A and the corresponding element from B
 */
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int arr[100], arr2[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arr2[i] = arr[i];
	}
	sort(arr, arr + n);
	sort(arr2, arr2 + n);
	reverse(arr2, arr2 + n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += abs(arr[i] - arr2[i]);
	}
	cout << sum << endl;
	return 0;
}
