/*
 * ICPC Assuit Community - Newcomers (Function)
 * Source: https://cutt.ly/SffEVgE
 * Problem Statement :Write a C++ program with a function which checks whether a given string consists of digits only or not. If it is, return 1 otherwise 0.
 */
#include<iostream>
using namespace std;

int check(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (!isdigit(s[i]))//   !(s[i] >= '0' && s[i] <= '9')
			return 0;
	}
	return 1;
}

int main() {
	string s;
	cin >> s;
	cout << check(s);
	return 0;
}
