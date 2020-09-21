/*
 * ICPC Assuit Community - Newcomers (Function)
 * Source: https://cutt.ly/SffEVgE
 * Problem Statement :Write a program in C++ to convert decimal number to hexadecimal number using the function
 * example :  123458             output: 1E242
 */

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string convert_to_hexadecimal(int n) {
	string res = "";
	while (n > 0) {
		int y = n % 16;
		if (y > 9) {
			res += char(y - 10 + 'A');
		} else {
			res += char(y + '0');
		}
		n /= 16;
	}
	reverse(res.begin(), res.end());
	return res;
}
int main() {
	int n;
	cin >> n;
	cout << convert_to_hexadecimal(n);
}
