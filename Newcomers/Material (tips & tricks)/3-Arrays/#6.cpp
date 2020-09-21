/*
 * ICPC Assuit Community - Newcomers (Array)
 * Source: https://cutt.ly/tff3SCd
 * Problem Statement :Given an array, you can change elements from it, print the minimum number of elements you need to change ,to make all elements in the array equal. (0 <= numbers <= 1e5)
 *
 */
#include<iostream>
using namespace std;
int fre[(int)1e5];
int main(){
    int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int a;
		cin >> a;
		fre[a]++;
	}
	int mx = 0;
	for (int i = 0; i < 10; i++){
		mx = max(mx, fre[i]);
	}
	cout << n - mx << endl;
	return 0;
}
