/*
 * ICPC Assuit Community - Newcomers (Function)
 * Source: https://cutt.ly/SffEVgE
 * Problem Statement :Write a program to print the circumference and area of a circle of radius entered by the user by defining your own function?
 */

#include <iostream>
#include <cmath>
using namespace std;
double PI = acos(-1); //acos(-1)=3.141  but it's more accurate,it's exist in "cmath" library.
double get_circumference(double r) {
	return 2 * r * PI;
}
double get_area(double r) {
	return r * r * PI;
}
int main() {
	double r;
	cin >> r;
	cout << "circumference = " << get_circumference(r) << endl;
	cout << "area = " << get_area(r);
	return 0;
}
