/*
 * ICPC Assuit Community - Newcomers (Function)
 * Source: https://cutt.ly/SffEVgE
 * Problem Statement :Write a program in C++ to check whether two given strings are an anagram. If so, the return value should be 1 otherwise 0.
 * example :  spare  pears              output: 1
 */
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int frqa[100], frqb[100];
int check_anagram(string a, string b) {
	if (a.size() != b.size())
		return 0;
	for (int i = 0; i < (int) a.size(); i++) {
		frqa[a[i] - 'a']++;
		frqb[b[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (frqa[i] != frqb[i]) {
			return 0;
		}
	}
	return 1;
}
int check_anagram2(string a, string b) {
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	return a==b;
}
int main() {
	string a, b;
	cin >> a >> b;
	cout << check_anagram(a, b);
	return 0;
}
