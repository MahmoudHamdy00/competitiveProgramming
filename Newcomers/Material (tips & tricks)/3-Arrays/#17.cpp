/*
 * ICPC Assuit Community - Newcomers (Array)
 * Source: https://cutt.ly/tff3SCd
 * Problem Statement :You have a matrix and your task is to determine the absolute difference between the summation of corner elements and the center  elements
 *
 */
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int arr[100][100];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	int sum_corner = arr[1][1] + arr[1][n] + arr[n][1] + arr[n][n];
	int sum_center = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 || i == n || j == 1 || j == n)
				continue;
			sum_center += arr[i][j];
		}
	}
	cout << abs(sum_center - sum_corner) << endl;
	return 0;
}
