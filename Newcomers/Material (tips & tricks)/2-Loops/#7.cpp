/*
 * ICPC Assuit Community - Newcomers (Loops)
 * Source: https://cutt.ly/5fdxPSU
 * Problem Statement :Given a number N, Print a Ramadan lantern as the following shape. (2<N<60)
 */

#include <iostream>
using namespace std;
int main() {

	int n, idx = 2;
	cin >> n;
	for (int i = 0; i < (n + (n - 1) + (n - 2)); i++) {
		if (i < n) {
			for (int j = 0; j < n - i; j++)
				cout << " ";
			for (int j = 0; j < (i + (i - 1)) + 2; j++)
				cout << "*";

			cout << "\n";
		} else if (i < n + (n - 1)) {

			int newval = (i - idx);
			for (int j = 0; j < i - (n - 2); j++)
				cout << " ";
			for (int j = 0; j < newval + (newval + 1); j++)
				cout << "*";
			cout << "\n";
			idx += 2;
		} else {
			int newval = (i - (n + (n - 2)));
			for (int j = i; j < (n + (n - 1) + (n - 1)); j++)
				cout << " ";

			for (int j = 0; j < newval + (newval + 1); j++)
				cout << "*";

			cout << "\n";
		}
	}
}
