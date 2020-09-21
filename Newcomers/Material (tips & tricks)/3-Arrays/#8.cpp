/*
 * ICPC Assuit Community - Newcomers (Array)
 * Source: https://cutt.ly/tff3SCd
 * Problem Statement :You have an array of chars, determine if you can create the word "Hello" by using the chars you are given or not.
 */
#include<iostream>
using namespace std;
int fre[26];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (islower(c)) {
			if (c == 'e' || c == 'l' || c == 'o')
				fre[c - 'a']++;
		} else {
			if (c == 'H')
				fre[c - 'A']++;
		}
	}
	if (fre['H' - 'A'] > 0 && fre['e' - 'a'] > 0 && fre['l' - 'a'] >= 2 && fre['o' - 'a'] > 0) {
		cout << "You Can Form the word \"Hello\" " << endl;
	} else {
		cout << "You can't form it" << endl;
	}
	return 0;
}
