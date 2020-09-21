/*
 * ICPC Assuit Community - Newcomers (Loops)
 * Source: https://cutt.ly/5fdxPSU
 * Problem Statement :Given a number n, your task is to print the number after increasing every digit in the number by 1.
 * example n=123456		     output   234567
 * example n=12920			output   23031
 */

#include<iostream>
using namespace std;
int main() {
	int n, ans = 0;
	cin >> n;
	int numOfDigits = 0;
	while (n > 0) {
		int x = n % 10; // get the last digit
		x++;    // increase digit by 1
		if (x == 10)
			x = 0;  // special case
		ans *= 10;  // adding digit to my answer
		ans += x;
		n /= 10;   // remove the last digit
		numOfDigits++; //increase 1 digit
	}

	// now my answer is in reversed order so print it starting from the last digit

	while (ans > 0) {
		cout << ans % 10;
		ans /= 10;
		numOfDigits--; //Decrease 1 digit
	}
	//now if there exist 9 in the first digit from right it will be 0 so it won't be stored in ans , so the remaining digits will be 0
	while (numOfDigits--) {
		cout << 0;
	}
	return 0;
}
