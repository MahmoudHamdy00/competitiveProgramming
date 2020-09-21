/*
 * ICPC Assuit Community - Newcomers (Array)
 * Source: https://cutt.ly/tff3SCd
 * Problem Statement :you have a matrix n*m print it after divide it int to arrays with equal dimensions :(assume that n and m is always even)
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
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m / 2; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = (m / 2) + 1; j <= m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
