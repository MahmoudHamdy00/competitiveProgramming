/*
 * ICPC Assuit Community - Newcomers (Complexity - Sorting - binary search)
 * Source: https://cutt.ly/ffdO7U1
 * Problem Statement :Can we swap an element of A with an element of B such that the sum of elements in the two arrays is equal with O (n) time complexity?
 * example :
 * array a={3, 4, 7, 8}
 * array b={1, 2, 2, 5}
 * Tutorial:https://cutt.ly/PfdOhhz
 */

#include<iostream>
using namespace std;
int fre[(int) 1e6], A[(int) 1e6], B[(int) 1e6];
int main() {
	int n, sumA = 0, sumB = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		sumA += A[i];
		fre[A[i]]++;
	}
	for (int i = 0; i < n; i++) {
		cin >> B[i];
		sumB += B[i];
	}
	int num = abs(sumA - sumB);
	if (num % 2 != 0) { // special case if num is odd so you can’t swap any element at all
		cout << "You Can’t" << endl;
		return 0;
	}
	num /= 2;
	bool ok = 0;
	// we will search about number of array B that its Subtraction with num exist in array A
	for (int i = 0; i < n; i++) {
		int x = B[i] + num; // if sumA greater
		int y = B[i] - num;  // if sumB greater
		if (fre[x]) {
			ok = 1;
			cout << "You can" << endl;
			cout << "swap " << x << " with " << B[i] << endl;
			break;
		} else if (fre[y]) {
			ok = 1;
			cout << "You can" << endl;
			cout << "swap " << y << " with " << B[i] << endl;
			break;
		}
	}
	if (!ok) {
		cout << "You Can’t" << endl;
	}
	return 0;
}
